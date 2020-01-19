## RPC

**C++语言开发的基于muduo网络库的RPC框架项目，数据序列化和反序列化使用protobuf，服务配置中心使用zookeeper**

## 环境

**需要安装muduo网络库，protobuf环境，以及zookeeper环境**

## 项目简介

**bin：RPC框架测试代码的可执行文件**

**lib：RPC框架生成的静态库和动态库**

**include：RPC框架头文件**

**src：RPC框架源文件**

**test：RPC框架测试用例代码**

**thirdparty：使用到的第三方库，主要使用了tinyxml**

**build：Cmake编译过程中生成的中间文件**

## 编译框架代码

**使用强大的Cmake编译，并且实现了Shell脚本一键编译**

## 运行测试代码

**在bin中会生成rpc_server 和 rpc_client 两个可执行文件**

**【注意事项1】需要开启zookeeper服务器**

**【注意事项2】在运行之前需要在zookeeper上创建RpcService的根节点**

**【注意事项3】需要注意在启动RPC服务器的目录中，配置文件 llocalconfig.xml 是否存在**