#include "Message.pb.h"
#include "RpcClient.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	LService_Stub stub(new RpcClient()); // ʹ��stub�Ĳ�����һ��RpcChannal��һ������ָ�룬��˴���һ���������������
	// ���ò���
	LogRequest request;
	request.set_name("yang");
	request.set_pwd("123");
	// ���÷������ȡ�ķ���ֵ
	LogResponse response;
	stub.login(nullptr, &request, &response, nullptr);
	bool loginstate = response.response(); // ���óɹ�
	cout << "loginstate : " << loginstate << endl;
	return 0;
}
