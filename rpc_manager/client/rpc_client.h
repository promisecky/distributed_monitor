/*
 * @Author: ChengKeyi
 * @Date: 2024-03-11 22:31:02
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-19 11:58:15
 * @FilePath: /Desktop/monitor/rpc_manager/client/rpc_client.h
 * @Description:
 */

#pragma once
#include "grpc/grpc.h"
#include "grpcpp/create_channel.h"
#include "grpcpp/grpcpp.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor
{
    class RpcClient
    {
    public:
        RpcClient();
        ~RpcClient();
        void SetMonitorInfo(const monitor::proto::MonitorInfo &monitor_info);
        void GetMonitorInfo(monitor::proto::MonitorInfo *monitor_info);
        void GetHostID(const monitor::proto::HostInfo &host_info, monitor::proto::HostID *host_id);

    private:
        std::unique_ptr<monitor::proto::GrpcManager::Stub> stub_ptr;
    };
}
