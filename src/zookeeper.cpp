#include "zookeeper.h"

sem_t ZKClient::_sem;
string ZKClient::_rootPath = "/RpcService";

ZKClient::ZKClient()
	:_zkhandle(nullptr)
{
	sem_init(&_sem,0,0); // 初始化信号量
}

ZKClient::~ZKClient()
{
	sem_destroy(&_sem); // 销毁信号量
	// 关闭zookeeper连接
	if (_zkhandle != nullptr)
		zookeeper_close(_zkhandle);
}

void ZKClient::init(const char* host, int timeout) // connect 连接zookeeper服务器
{
	// 连接zookeeper服务器
	_zkhandle = zookeeper_init(host, global_watcher, timeout, nullptr, nullptr, 0);
	if (_zkhandle == nullptr) // zookeeper服务器连接失败
	{
		cout << "zookeeper connect error" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "connect success" << endl;
	sem_wait(&_sem);
}

// 默认创建永久性节点，因为临时节点无法在创建孩子节点
void ZKClient::create(const char *path, const char *data, int datalen, int state)
{
	char path_buffer[128];
	int bufferlen = sizeof(path_buffer);
	// �ж�znode�ڵ��Ƿ���ڣ������ڴ���
	int flag;
	flag = zoo_exists(_zkhandle, path, 0, nullptr);
	if (ZNONODE == flag)
	{
		// ��ʾznode�ڵ㲻���ڣ�������ʱ�ڵ�
		flag = zoo_create(_zkhandle, path, data, datalen,
			&ZOO_OPEN_ACL_UNSAFE, state, path_buffer, bufferlen);
		if (flag == ZOK)
		{
			cout << "znode create success... path:" << path << endl;
		}
		else
		{
			cout << "flag:" << flag << endl;
			cout << "znode create error... path:" << path << endl;
			exit(EXIT_FAILURE);
		}
	}
}

string ZKClient::get(const char* path)
{
	char buffer[64];
	int bufferlen = sizeof(buffer);
	int flag = zoo_get(_zkhandle, path, 0, buffer, &bufferlen, nullptr);
	if (flag != ZOK)
	{
		cout << "get znode error... path:" << path << endl;
		return "";
	}
	else
	{
		return buffer;
	}
}

void ZKClient::global_watcher(zhandle_t *zh, int type,
	int state, const char *path, void *watcherCtx)
{
	cout << "=============================" << endl;
	cout << "type:" << type << endl;
	cout << "state:" << state << endl;
	cout << "path:" << path << endl;
	cout << "=============================" << endl;

	if (type == ZOO_SESSION_EVENT) // 判断客户端是否有链接或者断开 SESSION会话
	{
		if (state == ZOO_CONNECTED_STATE) // 表示连接状态
		{ 
			cout << "connecting zookeeper success..." << endl;
			sem_post(&_sem); // 给信号量加一 V操作
		}
		else if (state == ZOO_EXPIRED_SESSION_STATE) // EXPIRED 连接失效
		{
			cout << "connetion zookeeper error " << endl;
		}
	}
}

void ZKClient::setRootPath(string path)
{
	_rootPath = path;
}
string ZKClient::getRootPath()
{
	return _rootPath;
}

// 设置心跳,专门的线程处理
void ZKClient::sendHeartBeat()
{
	thread t([&]() {
		for (;;)
		{
			int time = CLocal::GetInstance()->GetZKTimeout() * 1.0 / 3;
			this_thread::sleep_for(chrono::seconds(time));
			zoo_exists(_zkhandle, _rootPath.c_str(), 0, nullptr);
		}
	});
	t.detach();
}
