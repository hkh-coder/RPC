#include"localconfig.h"

CLocal * CLocal::clocal_ = nullptr;  // 类外初始化静态成员变量

CLocal* CLocal::GetInstance()
{
	if (clocal_ == nullptr)
	{
		clocal_ = new CLocal();
	}
	return clocal_;
}

CLocal::CLocal()
{
	ReadXml();
}

void CLocal::ReadXml()
{
	lActionXML.LoadFile("localconfig.xml");
	if (lActionXML.Error())
	{
		cout << "read failed !" << endl;
		exit(EXIT_FAILURE); // 直接退出
	}
	else
	{
		const TiXmlNode *node = lActionXML.RootElement()->IterateChildren("RpcServer", nullptr);
		const TiXmlNode *node2 = nullptr;
		if (node != nullptr)
		{
			node2 = node->IterateChildren("ip", nullptr);
			_rpc_server_ip = node2->ToElement()->GetText();
			node2 = node->IterateChildren("port", nullptr);
			_rpc_server_port = atoi(node2->ToElement()->GetText());
		}
		node = lActionXML.RootElement()->IterateChildren("zookeeper", nullptr);
		node2 = node->IterateChildren("host", nullptr);
		_zookeeper_host = node2->ToElement()->GetText();
		node2 = node->IterateChildren("timeout", nullptr);
		_zookeeper_timeout = atoi(node2->ToElement()->GetText());
	}
}

string CLocal::GetRpcServerIp()const
{
	return _rpc_server_ip;
}
unsigned short CLocal::GetRpcServerPort()const
{
	return _rpc_server_port;
}
string CLocal::GetZKHost()const
{
	return _zookeeper_host;
}
int CLocal::GetZKTimeout()const
{
	return _zookeeper_timeout;
}
