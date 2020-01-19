#include "Message.pb.h"
#include <iostream>
#include <string>
#include "RpcSer.h"
using namespace std;


/*
基于muduo实现一个简单的服务器、服务器提供登录方法、注册方法、以及修改密码方法
*/

class UserServer : public LService
{
public:
	// 因为LService基类中有这两个函数的虚函数、因此在当前派生类中重写方法
	void login(::google::protobuf::RpcController* controller,
		const ::LogRequest* request,
		::LogResponse* response,
		::google::protobuf::Closure* done)
	{
		// 需要在这个login的重写方法中调用本地服务的方法
		// ruquest参数将会从RPC中将客户端传递的参数带过来
		// response是需要服务器重置的、将login函数的返回值写入response中
		// done是RPC框架注册的回调函数
		string name = request->name();
		string pwd = request->pwd();
		bool login_response = login(name, pwd);
		response->set_response(login_response); // 将login的返回值写入参数response中
		done->Run(); // 调用RPC注册的回调函数、(回调函数中是RPC对返回值如何处理)
	}

	void regis(::google::protobuf::RpcController* controller,
		const ::ResRequest* request,
		::ResResponse* response,
		::google::protobuf::Closure* done)
	{
		// 这个函数同理login函数
		int id = request->id();
		string name = request->name();
		string pwd = request->pwd();
		bool regis_response = regis(id, name, pwd);
		response->set_response(regis_response);
		done->Run();
	}

private:

	bool login(string name, string pwd)
	{
		cout << "name : " << name << " " << "pwd : " << pwd << endl;
		return false;
	}

	bool regis(int id, string name, string pwd)
	{
		cout << "id : "<< id <<" "<< "name : " << name << " "
			<< "pwd : " << pwd << endl;
		return true;
	}
};

int main()
{
	cout << "RpcServer Start" << endl;
	RpcServer * rpc = RpcServer::GetInstance();
	// 注册服务和方法
	cout << "RegisService " << endl;
	rpc->regisService(new UserServer());
	// 启动服务器
	rpc->run();

	return 0;
}
