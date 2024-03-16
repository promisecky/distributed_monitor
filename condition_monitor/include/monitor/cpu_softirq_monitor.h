/*
 * @Author: ChengKeyi
 * @Date: 2024-03-12 10:48:06
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-12 11:45:53
 * @FilePath: /Desktop/monitor/condition_monitor/include/monitor/cpu_softirq_monitor.h
 * @Description:
 */
#pragma once
#include "cpu_softirq_monitor.h"
#include <string>
#include <unordered_map>
#include "utils/read_file.h"
#include <boost/chrono.hpp>
#include "monitor_inter.h"
#include <utils/utils.h>

namespace monitor
{
    class CpuSoftirqMonitor : public MonitorInter
    {
        struct SoftIrq
        {
            std::string cpu_name;
            int64_t hi;
            int64_t timer;
            int64_t net_tx;
            int64_t net_rx;
            int64_t block;
            int64_t irq_poll;
            int64_t tasklet;
            int64_t sched;
            int64_t hrtimer;
            int64_t rcu;
            boost::chrono::steady_clock::time_point timepoint;
        };

    public:
        CpuSoftirqMonitor() {}
        void UpdateOnce(monitor::proto::MonitorInfo *monitor_info);
        void Stop() override {}

    private:
        std::unordered_map<std::string, struct SoftIrq> cpu_softirqs_;
    };

} // namespace monitor
