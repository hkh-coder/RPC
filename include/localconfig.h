#ifndef LOCALCONFIG_H
#define LOCALCONFIG_H

#include "tinyxml.h"
#include <string>
#include <iostream>
using namespace std;

// 读取配置文件的类
// 设置称单例模式
class CLocal
{
public:
	static CLocal* GetInstance();

	string GetRpcServerIp()const;
	unsigned short GetRpcServerPort()const;
	string GetZKHost()const;
	int GetZKTimeout()const;

private:
	CLocal();
	void ReadXml();
	CLocal(const CLocal&) = delete;
	CLocal& operator=(const CLocal&) = delete;

	TiXmlDocument lActionXML; // 读取XML文件的对象
	string _rpc_server_ip;    // 读取RPCServer的IP地址
	unsigned short _rpc_server_port; // 读取RCPServer的prot端口号
	string _zookeeper_host;    // 读取zookeeper的host 存储方式是ip:prot
	int _zookeeper_timeout;    // zookeeper的连接的超时时间

	static CLocal * clocal_;
};





#endif // ! LOCALCONFIG_H
