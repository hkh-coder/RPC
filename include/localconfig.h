#ifndef LOCALCONFIG_H
#define LOCALCONFIG_H

#include "tinyxml.h"
#include <string>
#include <iostream>
using namespace std;

// ��ȡ�����ļ�����
// ���óƵ���ģʽ
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

	TiXmlDocument lActionXML; // ��ȡXML�ļ��Ķ���
	string _rpc_server_ip;    // ��ȡRPCServer��IP��ַ
	unsigned short _rpc_server_port; // ��ȡRCPServer��prot�˿ں�
	string _zookeeper_host;    // ��ȡzookeeper��host �洢��ʽ��ip:prot
	int _zookeeper_timeout;    // zookeeper�����ӵĳ�ʱʱ��

	static CLocal * clocal_;
};





#endif // ! LOCALCONFIG_H
