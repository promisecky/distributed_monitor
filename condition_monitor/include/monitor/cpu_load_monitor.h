/*
 * @Author: ChengKeyi
 * @Date: 2024-03-12 09:54:16
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-12 11:37:25
 * @FilePath: /Desktop/monitor/condition_monitor/include/monitor/cpu_load_monitor.h
 * @Description:
 */
#pragma once
#include "monitor_inter.h"
#include "utils/read_file.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"
#include "utils/read_file.h"
namespace monitor
{
    class CpuLoadMonitor : public MonitorInter
    {
    public:
        CpuLoadMonitor(){};
        ~CpuLoadMonitor(){};
        void UpdateOnce(monitor::proto::MonitorInfo *monitorinfo);
        void Stop(){};

    private:
        float load_avg_1_;
        float load_avg_5_;
        float load_avg_15_;
    };

}
