/*
 * @Author: ChengKeyi
 * @Date: 2024-03-11 22:03:01
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-16 13:26:23
 * @FilePath: /Desktop/monitor/rpc_manager/server/rpc_manager.cpp
 * @Description:
 */
#include "rpc_manager.h"

#include <iostream>

namespace monitor
{
    GrpcManagerImpl::GrpcManagerImpl()
    {
        std::cout << "ManagerImpl 初始化" << std::endl;
        this->monitor_info_manager_ptr = std::make_unique<monitor::MonitorInfoManager>();
        this->monitor_info_manager_ptr->readDataBaseInfo("/work/monitor_info_manager/dataBaseConfig.txt");
        this->monitor_info_manager_ptr->getHostId();
    }
    GrpcManagerImpl::~GrpcManagerImpl() {}
    ::grpc::Status GrpcManagerImpl::SetMonitorInfo(::grpc::ServerContext *context,
                                                   const ::monitor::proto::MonitorInfo *request,
                                                   ::google::protobuf::Empty *response)
    {
        monitor_infos_.Clear();
        monitor_infos_ = *request;
        this->monitor_info_manager_ptr->writeIntoDataBase(*request);
        auto cpuload = request->cpu_load();
        auto avg_1 = cpuload.load_avg_1();
        auto avg_5 = cpuload.load_avg_5();
        auto avg_15 = cpuload.load_avg_15();
        std::cout << "avg_1 = " << avg_1 << " avg_5 = " << avg_5 << "avg_15 = " << avg_15 << std::endl;
        return ::grpc::Status::OK;
    }
    ::grpc::Status GrpcManagerImpl::GetMonitorInfo(::grpc::ServerContext *context,
                                                   const ::google::protobuf::Empty *request,
                                                   ::monitor::proto::MonitorInfo *response)
    {
        *response = monitor_infos_;
        return ::grpc::Status::OK;
    }

}