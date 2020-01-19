#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H


#include <zookeeper/zookeeper.h>
#include <semaphore.h>
#include <iostream>
#include <string>
#include <thread>
#include "localconfig.h"
#include <chrono>
using namespace std;


class ZKClient
{
public:
	ZKClient();
	~ZKClient();
	void init(const char* host,int timeout); // connect
	void create(const char *path, const char *data, int datalen, int state = 0);
	string get(const char* path);
 
	static void global_watcher(zhandle_t *zh, int type,
		int state, const char *path, void *watcherCtx);
	static void setRootPath(string path);
	static string getRootPath();
	void sendHeartBeat();

private:
	zhandle_t *_zkhandle; // zookeeper 对象
	static string _rootPath;  
	static sem_t _sem; // 信号量
};
#endif // ZOOKEEPER_H

