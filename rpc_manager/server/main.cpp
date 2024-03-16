/*
 * @Author: ChengKeyi
 * @Date: 2024-03-11 22:11:22
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-11 22:27:38
 * @FilePath: /Desktop/monitor/rpc_manager/server/main.cpp
 * @Description:
 */
#include "rpc_manager.h"
#include <iostream>
#include <grpc/grpc.h>
#include <grpcpp/server_builder.h>

constexpr char kServerPortInfo[] = "0.0.0.0:50051";

void InitServer()
{
    grpc::ServerBuilder builder;
    builder.AddListeningPort(kServerPortInfo, grpc::InsecureServerCredentials());
    monitor::GrpcManagerImpl rpc_manager;
    builder.RegisterService(&rpc_manager);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    server->Wait();
    return;
}

int main(int argc, char *argv[])
{
    InitServer();
    return 0;
}
