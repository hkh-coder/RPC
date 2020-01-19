#ifndef RPCCLIENT_H
#define RPCCLIENT_H

#include <iostream>
#include <string>
#include <muduo/net/TcpClient.h>
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <google/protobuf/service.h>
#include "RpcClient.pb.h"
#include "zookeeper.h"
#include "localconfig.h"


using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace google::protobuf;
using namespace placeholders;


class RpcClient : public RpcChannel
{
public: 
	RpcClient();
	~RpcClient();
	void CallMethod(const MethodDescriptor* method,
		RpcController* controller, const Message* request,
		Message* response, Closure* done);
	
private:
	// �����µ����Ӻ͹ر�����
	void onConnection(const TcpConnectionPtr & con);
	// �����շ�����
	void onMessage(const TcpConnectionPtr& con, Buffer* buf, Timestamp time);

	TcpClient* client_;
	EventLoop loop;
	ZKClient zook_; // zkclient����

	// ���������ص�����
	function<void(const TcpConnectionPtr & con)> SendStr;
	function<void(string &str)> writeResponse;
};

#endif // !RPCCLIENT_H
