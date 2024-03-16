/*
 * @Author: ChengKeyi
 * @Date: 2024-03-12 10:38:30
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-12 11:38:40
 * @FilePath: /Desktop/monitor/condition_monitor/include/monitor/cpu_stat_monitor.h
 * @Description:
 */
#pragma once
#include "cpu_stat_monitor.h"
#include "monitor_inter.h"
#include <unordered_map>
#include "utils/read_file.h"

namespace monitor
{
    class CpuStatMonitor : public MonitorInter
    {
        struct CpuStat
        {
            std::string cpu_name;
            float user;
            float system;
            float idle;
            float nice;
            float io_wait;
            float irq;
            float soft_irq;
            float steal;
            float guest;
            float guest_nice;
        };

    public:
        CpuStatMonitor() {}
        void UpdateOnce(monitor::proto::MonitorInfo *monitor_info);
        void Stop() override {}

    private:
        std::unordered_map<std::string, struct CpuStat> cpu_stat_map_;
    };
}