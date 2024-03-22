# 这是一个分布式性能监控项目，能够实现多linux服务器的性能监控



## 1. 项目框架

### 1. docker

该目录为项目构建模块，内置docker构建所需的安装包和相关命令，其中对于性能监控的服务端，在docker容器运行时应使用docker_run.sh以及使用docker_into.sh进入容器。对于性能监控的客户端，使用docker_client_into.sh和docker_client_run.sh。同时需注意保证客户端主机和服务端主机能够正常通信，同时加入docker集群并连接同一个overlay网络。

### 2. proto

该目录为proto文件模块，为实现服务器多种性能数据所特定的一些数据格式和grpc函数。

### 3. condition_monitor

该目录为性能数据读取模块，linux的一大特性为一切皆文件，对其进行性能监控，实际就是对文件数据进行解析，通过工厂模式，利用c++的多态特性，实现了不同性能数据的读取和更新。

### 4. monitor_info_manager

该目录为数据存储模块，用于将获取的性能数据存到mysql数据库中，其中dataBaseConfig.txt中为数据库信息，需要根据实际数据库配置进行相应修改。

### 5. rpc_manager

该目录为grpc函数模块，用于实现具体的服务端数据库连接，客户端和服务端数据交互的业务逻辑。

### 6. cmake

该目录为编译文件夹，项目整体使用cmake进行编译，编译生成的文件内容都在这里。

