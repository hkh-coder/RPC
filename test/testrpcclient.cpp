#include "Message.pb.h"
#include "RpcClient.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	LService_Stub stub(new RpcClient()); // 使用stub的参数是一个RpcChannal的一个基类指针，因此传递一个基类的派生对象
	// 设置参数
	LogRequest request;
	request.set_name("yang");
	request.set_pwd("123");
	// 调用方法后获取的返回值
	LogResponse response;
	stub.login(nullptr, &request, &response, nullptr);
	bool loginstate = response.response(); // 调用成功
	cout << "loginstate : " << loginstate << endl;
	return 0;
}
