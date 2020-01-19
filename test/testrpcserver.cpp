#include "Message.pb.h"
#include <iostream>
#include <string>
#include "RpcSer.h"
using namespace std;


/*
����muduoʵ��һ���򵥵ķ��������������ṩ��¼������ע�᷽�����Լ��޸����뷽��
*/

class UserServer : public LService
{
public:
	// ��ΪLService���������������������麯��������ڵ�ǰ����������д����
	void login(::google::protobuf::RpcController* controller,
		const ::LogRequest* request,
		::LogResponse* response,
		::google::protobuf::Closure* done)
	{
		// ��Ҫ�����login����д�����е��ñ��ط���ķ���
		// ruquest���������RPC�н��ͻ��˴��ݵĲ���������
		// response����Ҫ���������õġ���login�����ķ���ֵд��response��
		// done��RPC���ע��Ļص�����
		string name = request->name();
		string pwd = request->pwd();
		bool login_response = login(name, pwd);
		response->set_response(login_response); // ��login�ķ���ֵд�����response��
		done->Run(); // ����RPCע��Ļص�������(�ص���������RPC�Է���ֵ��δ���)
	}

	void regis(::google::protobuf::RpcController* controller,
		const ::ResRequest* request,
		::ResResponse* response,
		::google::protobuf::Closure* done)
	{
		// �������ͬ��login����
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
	// ע�����ͷ���
	cout << "RegisService " << endl;
	rpc->regisService(new UserServer());
	// ����������
	rpc->run();

	return 0;
}
