
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
��RPCʵ�ֳµ���ģʽ
*/

class RpcServer
{
public:
	static RpcServer*GetInstance();
	
	void run();

	//������������������
	void regisService(google::protobuf::Service * service);
	
private:
	RpcServer(EventLoop *loop, const InetAddress &addr, const string& name);
	// �շ���Ϣ����
	void oneConnection(const TcpConnectionPtr & con);
	void oneMessage(const TcpConnectionPtr & con,
		Buffer* buf, Timestamp time);
	void SendDataCallBack(const TcpConnectionPtr & con,
		google::protobuf::Message* response);


	TcpServer ser_;   // ����������
	EventLoop *loop_; // �¼�ѭ������
	ZKClient zook_;   // zkclient����
	

	// ʹ������map�洢��RPC����Ϸ����ķ���ͷ��񷢲�����
	struct serviceInfo
	{
		google::protobuf::Service * service;
		unordered_map<string, const google::protobuf::MethodDescriptor*> method_map;
	};
	unordered_map<string, serviceInfo> service_map;

	static RpcServer * rpcser_; // ��̬��Ա
};

#endif // !RPCSER_H
