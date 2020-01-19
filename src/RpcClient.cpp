#include "RpcClient.h"
#include <thread>
using namespace std;

RpcClient::RpcClient() :client_(nullptr) {}
RpcClient::~RpcClient()
{
	delete client_;
	client_ = nullptr;
}

void RpcClient::CallMethod(const MethodDescriptor* method,
	RpcController* controller, const Message* request,
	Message* response, Closure* done)
{
	auto service = method->service();      // ��ȡ������Ӧ�ķ�����
	string service_name = service->name(); // ��ȡ��������
	string method_name = method->name();   // ��ȡ������

	// ����zook������,Ѱ�ҷ���ͷ����ֲ���������ip��port
	zook_.init(CLocal::GetInstance()->GetZKHost().c_str(), CLocal::GetInstance()->GetZKTimeout());
	string path = zook_.getRootPath() + "/" + service_name + "/" + method_name;
	string rpc_ip_port = zook_.get(path.c_str()); // ��ȡ�ĸ�ʽ��ip:port 
	if (rpc_ip_port.size() == 0)
	{
		return;
	}

	// �����������ͷ������������л�
	ClientData_Header header;
	header.set_userservice(service_name);
	header.set_servicemethod(method_name);
	string header_str;
	header.SerializeToString(&header_str);
	int header_size = header_str.size();
	// ��ȡ���������л�
	string request_args_str;
	request->SerializeToString(&request_args_str);

	string send_str;
	send_str.insert(0, string((char*)&header_size,4));
	send_str += header_str;
	send_str += request_args_str;

	cout << "============================================" << endl;
	cout << "header_size:" << header_size << endl;
	cout << "header_str:" << header_str << endl;
	cout << "service_name:" << service_name << endl;
	cout << "method_name:" << method_name << endl;
	cout << "request_args_str:" << request_args_str << endl;
	cout << "============================================" << endl;


	// ���÷������ݵĻص�
	SendStr = [&](const TcpConnectionPtr & con) { con->send(send_str); };
	// ���û�дresponse�Ļص�
	writeResponse = [&](string & str) { response->ParseFromString(str); };

	
	// ��ip��port ��������
	int index = rpc_ip_port.find(":");
	string ip = rpc_ip_port.substr(0, index);
	int port = atoi(rpc_ip_port.substr(index + 1).c_str());

	// ���ӷ���ͷ����ֲ�������
	client_ = new TcpClient(&loop, InetAddress(ip, port), "client");
	client_->setConnectionCallback(bind(&RpcClient::onConnection, this, _1));
	client_->setMessageCallback(bind(&RpcClient::onMessage, this, _1, _2, _3));

	// ����RPC����
	client_->connect();
	loop.loop();
}


// �����µ����Ӻ͹ر�����
void RpcClient::onConnection(const TcpConnectionPtr & con)
{
	if (con->connected()) // �����Ϸ�����
	{
		// �������ݡ�ʹ�ûص�����
		// ��Ϊ���͵�������callmethod
		cout << "connecting RpcServer !" << endl;
		cout << con->peerAddress().toIpPort();
		SendStr(con);
	}
	else // �Ͽ�����
	{
		cout << "shut down Rpcserver !" << endl;
		con->shutdown(); // �ر�����
		loop.quit(); // ֹͣepollѭ��
	}
}

// �����շ�����
void RpcClient::onMessage(const TcpConnectionPtr& con, Buffer* buf, Timestamp time)
{
	// ��RPC��ܷ��صĽ��д�뵽callmethod��response��
	string message = buf->retrieveAllAsString(); // ������ת��Ϊ�ַ���
	writeResponse(message);
}

