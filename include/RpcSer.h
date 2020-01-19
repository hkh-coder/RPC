
#ifndef RPCSER_H
#define RPCSER_H

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Logging.h>
#include <functional>
#include <string>
#include <unordered_map>

using namespace muduo;
using namespace muduo::net;
using namespace std;
using namespace placeholders;

#include "google/protobuf/service.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/message.h"
#include "zookeeper.h"  // zkclient

/*
将RPC实现陈单例模式
*/

class RpcServer
{
public:
	static RpcServer*GetInstance();
	
	void run();

	//服务器发布方法函数
	void regisService(google::protobuf::Service * service);
	
private:
	RpcServer(EventLoop *loop, const InetAddress &addr, const string& name);
	// 收发消息函数
	void oneConnection(const TcpConnectionPtr & con);
	void oneMessage(const TcpConnectionPtr & con,
		Buffer* buf, Timestamp time);
	void SendDataCallBack(const TcpConnectionPtr & con,
		google::protobuf::Message* response);


	TcpServer ser_;   // 服务器对象
	EventLoop *loop_; // 事件循环对象
	ZKClient zook_;   // zkclient对象
	

	// 使用无序map存储在RPC框架上发布的服务和服务发布方法
	struct serviceInfo
	{
		google::protobuf::Service * service;
		unordered_map<string, const google::protobuf::MethodDescriptor*> method_map;
	};
	unordered_map<string, serviceInfo> service_map;

	static RpcServer * rpcser_; // 静态成员
};

#endif // !RPCSER_H
