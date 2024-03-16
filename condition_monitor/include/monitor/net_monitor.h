/*
 * @Author: ChengKeyi
 * @Date: 2024-03-12 11:13:25
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-12 11:43:18
 * @FilePath: /Desktop/monitor/condition_monitor/include/monitor/net_monitor.h
 * @Description:
 */
#pragma once
#include "monitor_inter.h"
#include "utils/read_file.h"
#include <string>
#include <unordered_map>
#include <boost/chrono.hpp>
#include <utils/utils.h>

namespace monitor
{
    class NetMonitor : public MonitorInter
    {
        struct NetInfo
        {
            std::string name;
            int64_t rcv_bytes;
            int64_t rcv_packets;
            int64_t err_in;
            int64_t drop_in;
            int64_t snd_bytes;
            int64_t snd_packets;
            int64_t err_out;
            int64_t drop_out;
            boost::chrono::steady_clock::time_point timepoint;
        };

    public:
        NetMonitor() {}
        void UpdateOnce(monitor::proto::MonitorInfo *monitor_info);
        void Stop() override {}

    private:
        std::unordered_map<std::string, struct NetInfo> net_info_;
    };

} // namespace monitor