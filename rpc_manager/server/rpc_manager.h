/*
 * @Author: ChengKeyi
 * @Date: 2024-03-11 21:02:47
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-16 12:58:00
 * @FilePath: /Desktop/monitor/rpc_manager/server/rpc_manager.h
 * @Description:
 */
#pragma once
#include "rpc_manager.h"
#include "monitor_info_manager.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor
{
    class GrpcManagerImpl : public monitor::proto::GrpcManager::Service
    {
    public:
        GrpcManagerImpl();
        virtual ~GrpcManagerImpl();

        ::grpc::Status SetMonitorInfo(::grpc::ServerContext *context,
                                      const ::monitor::proto::MonitorInfo *request,
                                      ::google::protobuf::Empty *response);

        ::grpc::Status GetMonitorInfo(::grpc::ServerContext *context,
                                      const ::google::protobuf::Empty *request,
                                      ::monitor::proto::MonitorInfo *response);

    private:
        monitor::proto::MonitorInfo monitor_infos_;
        std::shared_ptr<monitor::MonitorInfoManager> monitor_info_manager_ptr;
    };
}
