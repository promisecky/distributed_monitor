/*
 * @Author: ChengKeyi
 * @Date: 2024-03-11 22:45:21
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-19 11:58:31
 * @FilePath: /Desktop/monitor/rpc_manager/client/rpc_client.cpp
 * @Description:
 */
#include "rpc_client.h"

namespace monitor
{
    RpcClient::RpcClient()
    {
        auto channel = grpc::CreateChannel("localhost:50051",
                                           grpc::InsecureChannelCredentials());
        stub_ptr = monitor::proto::GrpcManager::NewStub(channel);
    }
    RpcClient::~RpcClient() {}

    void RpcClient::SetMonitorInfo(const monitor::proto::MonitorInfo &monitorInfo)
    {
        ::grpc::ClientContext context;
        ::google::protobuf::Empty response;
        ::grpc::Status status =
            stub_ptr->SetMonitorInfo(&context, monitorInfo, &response);
        if (status.ok())
        {
        }
        else
        {
            std::cout << status.error_details() << std::endl;
            std::cout << "falied to connect !!!" << std::endl;
        }
    }

    void RpcClient::GetMonitorInfo(monitor::proto::MonitorInfo *monitorInfo)
    {
        ::grpc::ClientContext context;
        ::google::protobuf::Empty
            requires;
        ::grpc::Status status = stub_ptr->GetMonitorInfo(&context, requires, monitorInfo);
        if (status.ok())
        {
        }
        else
        {
            std::cout << status.error_details() << std::endl;
            std::cout << "falied to connect !!!" << std::endl;
        }
    }

    void RpcClient::GetHostID(const monitor::proto::HostInfo &hostInfo, monitor::proto::HostID *host_id)
    {
        ::grpc::ClientContext context;
        ::grpc::Status status = stub_ptr->GetHostID(&context, hostInfo, host_id);
        if (status.ok())
        {
        }
        else
        {
            std::cout << status.error_details() << std::endl;
            std::cout << "falied to connect !!!" << std::endl;
        }
    }
}