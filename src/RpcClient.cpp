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
	auto service = method->service();      // 获取方法对应的服务类
	string service_name = service->name(); // 获取服务类名
	string method_name = method->name();   // 获取方法名

	// 连接zook服务器,寻找服务和方法分布的主机的ip和port
	zook_.init(CLocal::GetInstance()->GetZKHost().c_str(), CLocal::GetInstance()->GetZKTimeout());
	string path = zook_.getRootPath() + "/" + service_name + "/" + method_name;
	string rpc_ip_port = zook_.get(path.c_str()); // 获取的格式是ip:port 
	if (rpc_ip_port.size() == 0)
	{
		return;
	}

	// 将服务器名和方法名进行序列化
	ClientData_Header header;
	header.set_userservice(service_name);
	header.set_servicemethod(method_name);
	string header_str;
	header.SerializeToString(&header_str);
	int header_size = header_str.size();
	// 获取参数的序列化
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


	// 设置发送数据的回调
	SendStr = [&](const TcpConnectionPtr & con) { con->send(send_str); };
	// 设置回写response的回调
	writeResponse = [&](string & str) { response->ParseFromString(str); };

	
	// 将ip和port 解析出来
	int index = rpc_ip_port.find(":");
	string ip = rpc_ip_port.substr(0, index);
	int port = atoi(rpc_ip_port.substr(index + 1).c_str());

	// 连接服务和方法分布的主机
	client_ = new TcpClient(&loop, InetAddress(ip, port), "client");
	client_->setConnectionCallback(bind(&RpcClient::onConnection, this, _1));
	client_->setMessageCallback(bind(&RpcClient::onMessage, this, _1, _2, _3));

	// 发送RPC请求
	client_->connect();
	loop.loop();
}


// 处理新的连接和关闭连接
void RpcClient::onConnection(const TcpConnectionPtr & con)
{
	if (con->connected()) // 连接上服务器
	{
		// 发送数据、使用回调函数
		// 因为发送的数据在callmethod
		cout << "connecting RpcServer !" << endl;
		cout << con->peerAddress().toIpPort();
		SendStr(con);
	}
	else // 断开服务
	{
		cout << "shut down Rpcserver !" << endl;
		con->shutdown(); // 关闭连接
		loop.quit(); // 停止epoll循环
	}
}

// 处理收发数据
void RpcClient::onMessage(const TcpConnectionPtr& con, Buffer* buf, Timestamp time)
{
	// 将RPC框架返回的结果写入到callmethod的response中
	string message = buf->retrieveAllAsString(); // 将数据转化为字符串
	writeResponse(message);
}

