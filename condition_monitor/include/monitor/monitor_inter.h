/*
 * @Author: ChengKeyi
 * @Date: 2024-03-12 09:48:51
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-12 09:57:29
 * @FilePath: /Desktop/monitor/condition_monitor/include/monitor/monitor_inter.h
 * @Description:
 */
#pragma once

#include <string>

#include "monitor_inter.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor
{

    class MonitorInter
    {
    public:
        MonitorInter(){};
        virtual ~MonitorInter(){};
        virtual void UpdateOnce(monitor::proto::MonitorInfo *monitorinfo) = 0;
        virtual void Stop() = 0;
    };
} // namespace monitor