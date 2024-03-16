/*
 * @Author: ChengKeyi
 * @Date: 2024-03-12 10:21:57
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-13 10:37:44
 * @FilePath: /Desktop/monitor/condition_monitor/src/monitor/cpu_load_monitor.cpp
 * @Description:
 */
#include "monitor/cpu_load_monitor.h"

namespace monitor
{
    void CpuLoadMonitor::UpdateOnce(monitor::proto::MonitorInfo *monitor_info)
    {
        ReadFile cpu_load_file(std::string("/proc/loadavg"));
        std::vector<std::string> cpu_load;
        cpu_load_file.ReadLine(&cpu_load);
        load_avg_1_ = std::stof(cpu_load[0]);
        load_avg_5_ = std::stof(cpu_load[1]);
        load_avg_15_ = std::stof(cpu_load[2]);

        auto cpu_load_msg = monitor_info->mutable_cpu_load();
        cpu_load_msg->set_load_avg_1(load_avg_1_);
        cpu_load_msg->set_load_avg_5(load_avg_5_);
        cpu_load_msg->set_load_avg_15(load_avg_15_);

        return;
    }
}