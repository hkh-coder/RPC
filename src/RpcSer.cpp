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
	// 设置回调函数
	ser_.setConnectionCallback(bind(&RpcServer::oneConnection, this, _1));
	ser_.setMessageCallback(bind(&RpcServer::oneMessage, this, _1, _2,_3));
	// 设置线程数量
	ser_.setThreadNum(4);

	// 连接zook服务器
	zook_.init(CLocal::GetInstance()->GetZKHost().c_str(), CLocal::GetInstance()->GetZKTimeout());
	// 开始发送心跳
	zook_.sendHeartBeat();
}

// 启动rpc服务
void RpcServer::run()
{
	ser_.start(); 
	loop_->loop();
}

void RpcServer::oneConnection(const TcpConnectionPtr & con)
{
	if (!con->connected())
	{
		con->shutdown(); // 服务器主动关闭
	}
	cout << "Client Connection : "<<con->peerAddress().toIpPort();
}

void RpcServer::oneMessage(const TcpConnectionPtr& con,Buffer *buf,Timestamp time)
{
	// 提取头部信息的前四个字节
	string message = buf->retrieveAllAsString(); // 读取客户端发送的序列化的数据

	// 读取message的前四个字节的整数
	int header_size = 0;
	message.copy((char*)&header_size, sizeof(int),0);

	// 读取服务类型和方法
	string service_method;
	service_method = message.substr(4, header_size); // 参数1是截取开始、参数2是截取长度
	// 将数据反序列化
	ClientData_Header header;
	header.ParseFromString(service_method); 

	string service_name = header.userservice(); // 获取服务类型名
	string method_name = header.servicemethod(); // 获取方法名

	// 读取参数
	string method_args = message.substr(4+header_size);

	cout << "======================================" << endl;
	cout << "header_size:" << header_size << endl;
	cout << "service_method:" << service_method << endl;
	cout << "service_name:" << service_name << endl;
	cout << "method_name:" << method_name << endl;
	cout << "method_args:" << method_args << endl;
	cout << "======================================" << endl;
	// 在RPC上注册的服务类中寻找需要的方法
	auto  service = service_map.find(service_name);
	if (service == service_map.end())
	{
		con->send("not serveice!");
		return;
	}
	// 在服务上寻找服务发布的方法
	auto method = service_map[service_name].method_map.find(method_name);
	if (method == service_map[service_name].method_map.end())
	{
		con->send("server not method!");
		return;
	}
	// 获取该方法的proto定义的参数类型格式
	// 参数格式指针
	auto request = service->second.service->GetRequestPrototype(method->second).New();
	request->ParseFromString(method_args); // 将参数反序列化
	// 返回值格式指针
	auto response = service->second.service->GetResponsePrototype(method->second).New();
	
	// 设置回调函数
	auto done = google::protobuf::NewCallback
		<RpcServer, const TcpConnectionPtr&, google::protobuf::Message*>
		(this, &RpcServer::SendDataCallBack, con, response);

	// 调用该方法
	service->second.service->CallMethod(method->second, nullptr, request, response, done);
}

// 注册方法
void RpcServer::regisService(google::protobuf::Service * service)
{
	cout << "ip & port :" << ser_.ipPort() << endl;

	string UserServer_path;
	serviceInfo server;
	server.service = service;

	auto servince_desc = service->GetDescriptor(); // 获取service指向派生类对象的信息描述

	// 在zookeeper上创建UserServer目录

	UserServer_path += (zook_.getRootPath() + "/" + servince_desc->name());
	zook_.create(UserServer_path.c_str(), nullptr, -1);
	cout << "UserServer_path: " << UserServer_path << endl;
	for (int i = 0; i < servince_desc->method_count(); ++i)
	{
		auto method = servince_desc->method(i);
		server.method_map[method->name()] = method;
		string methodname_path;
		methodname_path += (UserServer_path + "/" + method->name());
		// 在UserServer_path 路径下创建methodname_path 并将当前Rpcserver的ip:port存储到其中
		cout << "methodname_path: " << methodname_path << endl;
		zook_.create(methodname_path.c_str(), ser_.ipPort().c_str(), ser_.ipPort().size(), ZOO_EPHEMERAL);
	}
	service_map[servince_desc->name()] = server;
}

// 回调函数
void RpcServer::SendDataCallBack(const TcpConnectionPtr & con, google::protobuf::Message*response)
{
	// 将response的值返回给客户端
	string response_str;
	response->SerializeToString(&response_str); //将response序列化
	con->send(response_str);
	// 采取短链接的方式、由服务器树洞断开连接
	con->shutdown();
}

