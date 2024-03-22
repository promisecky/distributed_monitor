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


## 2. docker跨主机容器通信

### 1. swarm集群创建

1. **初始化swarm**： 将当前主机设置为swarm管理节点

```sh
docker swarm init
```

2. **获取 Swarm 集群初始化令牌**：在现有的 Swarm 管理节点上，使用以下命令获取加入集群所需的令牌：

```sh
docker swarm join-token worker
```

这将生成一个加入令牌，你需要将这个令牌提供给要加入集群的工作节点

3. **在要加入的节点上执行加入命令**：在要加入 Swarm 集群的每个节点上，使用上一步中生成的加入令牌执行以下命令：

```sh
docker swarm join --token <token> <manager-ip>:<port>
```

其中，`<token>` 是在上一步生成的加入令牌，`<manager-ip>` 是 Swarm 管理节点的 IP 地址，`<port>` 是 Swarm 管理节点的监听端口（默认为 2377）。

4. **验证节点是否成功加入集群**：在 Swarm 管理节点上，执行以下命令来列出集群中的所有节点：

```sh
docker node ls
```

5. **打开通信端口**：确保swarm通信服务所需要端口是可用的

以ubuntu为例

```sh
#安装防火墙
#sudo apt update
#sudo apt install ufw

#启用防火墙
#sudo ufw enable

#允许特定端口
sudo ufw allow <port_number>

#拒绝特定端口
sudo ufw deny <port_number>

#拒绝/允许特定协议和端口号
sudo ufw allow <port_number>/<protocol>

#查看当前规则
sudo ufw status

Swarm 管理节点：
TCP 端口 2377：用于集群管理通信。
TCP 和 UDP 端口 7946：用于节点之间的通信。
UDP 端口 4789：用于 Overlay 网络通信。
```

### 2. 集群网络创建

1. **创建网络**：集群中节点通信需要创建overlay网络

```sh
docker network create --driver overlay --attachable my_network
```

2. **检查网络**：检查网络是否创建成功，一般在管理节点(初始化swarm网络的主机)上可以通过一下命令查看到网络信息，worker节点看不到创建的overlay网络信息，据说是要worker节点中使用这个网络，才能看到

```
docker network ls
```

3. **服务连接到网络**: 将需要跨宿主机通信的服务连接到网络

```sh
docker service create --name my_service --network my_network image_name

#其实也可以
docker run -it -d --name <docker_name> --net=my_network <images_name>
```

4. **查看容器中的网络配置** ：查看容器中网络配置

```sh
docker inspect <docker_name>
```

