#include "RpcSer.h"
#include <thread>
#include "RpcClient.pb.h"
#include "localconfig.h"
#include <iostream>
using namespace std;

RpcServer * RpcServer::rpcser_ = nullptr;

RpcServer*RpcServer::GetInstance()
{
	if (rpcser_ == nullptr)
	{
		static EventLoop loop;
		static InetAddress addr(CLocal::GetInstance()->GetRpcServerIp(),
			CLocal::GetInstance()->GetRpcServerPort());

		rpcser_ = new RpcServer(&loop, addr, "server");
	}
	return rpcser_;
}

RpcServer::RpcServer(EventLoop *loop,
	const InetAddress &addr,
	const string& name)
	:ser_(loop, addr, name)
	,loop_(loop)
{
	// ���ûص�����
	ser_.setConnectionCallback(bind(&RpcServer::oneConnection, this, _1));
	ser_.setMessageCallback(bind(&RpcServer::oneMessage, this, _1, _2,_3));
	// �����߳�����
	ser_.setThreadNum(4);

	// ����zook������
	zook_.init(CLocal::GetInstance()->GetZKHost().c_str(), CLocal::GetInstance()->GetZKTimeout());
	// ��ʼ��������
	zook_.sendHeartBeat();
}

// ����rpc����
void RpcServer::run()
{
	ser_.start(); 
	loop_->loop();
}

void RpcServer::oneConnection(const TcpConnectionPtr & con)
{
	if (!con->connected())
	{
		con->shutdown(); // �����������ر�
	}
	cout << "Client Connection : "<<con->peerAddress().toIpPort();
}

void RpcServer::oneMessage(const TcpConnectionPtr& con,Buffer *buf,Timestamp time)
{
	// ��ȡͷ����Ϣ��ǰ�ĸ��ֽ�
	string message = buf->retrieveAllAsString(); // ��ȡ�ͻ��˷��͵����л�������

	// ��ȡmessage��ǰ�ĸ��ֽڵ�����
	int header_size = 0;
	message.copy((char*)&header_size, sizeof(int),0);

	// ��ȡ�������ͺͷ���
	string service_method;
	service_method = message.substr(4, header_size); // ����1�ǽ�ȡ��ʼ������2�ǽ�ȡ����
	// �����ݷ����л�
	ClientData_Header header;
	header.ParseFromString(service_method); 

	string service_name = header.userservice(); // ��ȡ����������
	string method_name = header.servicemethod(); // ��ȡ������

	// ��ȡ����
	string method_args = message.substr(4+header_size);

	cout << "======================================" << endl;
	cout << "header_size:" << header_size << endl;
	cout << "service_method:" << service_method << endl;
	cout << "service_name:" << service_name << endl;
	cout << "method_name:" << method_name << endl;
	cout << "method_args:" << method_args << endl;
	cout << "======================================" << endl;
	// ��RPC��ע��ķ�������Ѱ����Ҫ�ķ���
	auto  service = service_map.find(service_name);
	if (service == service_map.end())
	{
		con->send("not serveice!");
		return;
	}
	// �ڷ�����Ѱ�ҷ��񷢲��ķ���
	auto method = service_map[service_name].method_map.find(method_name);
	if (method == service_map[service_name].method_map.end())
	{
		con->send("server not method!");
		return;
	}
	// ��ȡ�÷�����proto����Ĳ������͸�ʽ
	// ������ʽָ��
	auto request = service->second.service->GetRequestPrototype(method->second).New();
	request->ParseFromString(method_args); // �����������л�
	// ����ֵ��ʽָ��
	auto response = service->second.service->GetResponsePrototype(method->second).New();
	
	// ���ûص�����
	auto done = google::protobuf::NewCallback
		<RpcServer, const TcpConnectionPtr&, google::protobuf::Message*>
		(this, &RpcServer::SendDataCallBack, con, response);

	// ���ø÷���
	service->second.service->CallMethod(method->second, nullptr, request, response, done);
}

// ע�᷽��
void RpcServer::regisService(google::protobuf::Service * service)
{
	cout << "ip & port :" << ser_.ipPort() << endl;

	string UserServer_path;
	serviceInfo server;
	server.service = service;

	auto servince_desc = service->GetDescriptor(); // ��ȡserviceָ��������������Ϣ����

	// ��zookeeper�ϴ���UserServerĿ¼

	UserServer_path += (zook_.getRootPath() + "/" + servince_desc->name());
	zook_.create(UserServer_path.c_str(), nullptr, -1);
	cout << "UserServer_path: " << UserServer_path << endl;
	for (int i = 0; i < servince_desc->method_count(); ++i)
	{
		auto method = servince_desc->method(i);
		server.method_map[method->name()] = method;
		string methodname_path;
		methodname_path += (UserServer_path + "/" + method->name());
		// ��UserServer_path ·���´���methodname_path ������ǰRpcserver��ip:port�洢������
		cout << "methodname_path: " << methodname_path << endl;
		zook_.create(methodname_path.c_str(), ser_.ipPort().c_str(), ser_.ipPort().size(), ZOO_EPHEMERAL);
	}
	service_map[servince_desc->name()] = server;
}

// �ص�����
void RpcServer::SendDataCallBack(const TcpConnectionPtr & con, google::protobuf::Message*response)
{
	// ��response��ֵ���ظ��ͻ���
	string response_str;
	response->SerializeToString(&response_str); //��response���л�
	con->send(response_str);
	// ��ȡ�����ӵķ�ʽ���ɷ����������Ͽ�����
	con->shutdown();
}

