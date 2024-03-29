/*
 * @Author: ChengKeyi
 * @Date: 2024-03-15 19:34:03
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-19 12:14:00
 * @FilePath: /Desktop/monitor/monitor_info_manager/monitor_info_manager.h
 * @Description:
 */
#pragma once
#include "monitor_info_manager.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include <mysql.h>
#include <fstream>
#include <boost/chrono.hpp>
#include <ctime>
#include <iomanip>
#include "net_address.h"

namespace monitor
{
    class MonitorInfoManager
    {
    public:
        MonitorInfoManager() : USER(""), PW(""){};
        virtual ~MonitorInfoManager();
        // 读取数据库信息，建立数据库连接
        bool readDataBaseInfo(const std::string &configFileName);

        // 获取host编号
        bool getHostId(const std::string &ip, const std::string &mac, int *hostId);

        // 将性能信息写入数据库
        bool writeIntoDataBase(const monitor::proto::MonitorInfo &monitor_info);

        // 插入cpu_load中的信息
        bool writeCpuLoad(const monitor::proto::CpuLoad &cpu_load, const std::string &timestamp, const int &hostId);

        // 插入mem_info中的信息
        bool writeMemInfo(const monitor::proto::MemInfo &mem_info, const std::string &timestamp, const int &hostId);

        bool writeSoftIrq(const google::protobuf::RepeatedPtrField<::monitor::proto::SoftIrq> &
                              softIrqs,
                          const std::string &timestamp, const int &hostId);

        bool writeCpuStat(const google::protobuf::RepeatedPtrField<::monitor::proto::CpuStat> &
                              cpuStats,
                          const std::string &timestamp, const int &hostId);

        bool writeNetInfo(const google::protobuf::RepeatedPtrField<::monitor::proto::NetInfo> &
                              netInfos,
                          const std::string &timestamp, const int &hostId);

    private:
        std::string systemClock();

    private:
        std::string USER;
        std::string PW;
        std::string IP;
        std::string dataBase;

        MYSQL mysql; // 数据库句柄
        // int hostId;
        // MYSQL_RES *res; // 查询结果集
        // MYSQL_ROW row;  // 记录结构体
        // monitor::proto::MonitorInfo *monitor_info;
    };

}