/*
 * @Author: ChengKeyi
 * @Date: 2024-03-12 11:19:09
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-19 12:00:49
 * @FilePath: /Desktop/monitor/condition_monitor/src/main.cpp
 * @Description:
 */

#include <memory>
#include <thread>
#include <vector>

#include "client/rpc_client.h"
#include "monitor/cpu_load_monitor.h"
#include "monitor/cpu_stat_monitor.h"
#include "monitor/mem_monitor.h"
#include "monitor/monitor_inter.h"
#include "monitor/cpu_softirq_monitor.h"
#include "monitor/net_monitor.h"

int main()
{
  std::vector<std::shared_ptr<monitor::MonitorInter>> runners_;
  runners_.emplace_back(new monitor::CpuSoftirqMonitor());
  runners_.emplace_back(new monitor::CpuLoadMonitor());
  runners_.emplace_back(new monitor::CpuStatMonitor());
  runners_.emplace_back(new monitor::MemMonitor());
  runners_.emplace_back(new monitor::NetMonitor());

  monitor::RpcClient rpc_client_;

  // 获取宿主机的IP和MAC地址
  char *hostIP = std::getenv("HOST_IP");
  char *hostMAC = std::getenv("HOST_MAC");
  monitor::proto::HostInfo host_info;
  host_info.set_ip(hostIP);
  host_info.set_mac(hostMAC);
  monitor::proto::HostID host_id;
  rpc_client_.GetHostID(host_info, &host_id);

  char *name = getenv("USER");
  std::unique_ptr<std::thread> thread_ = nullptr;
  thread_ = std::make_unique<std::thread>([&]()
                                          {
    while (true) {
      monitor::proto::MonitorInfo monitor_info;
      monitor_info.set_name(std::string(name));
      monitor_info.set_host_id(host_id.host_id());
      for (auto& runner : runners_) {
        runner->UpdateOnce(&monitor_info);
      }

      rpc_client_.SetMonitorInfo(monitor_info);
      std::this_thread::sleep_for(std::chrono::seconds(3));
    } });

  thread_->join();
  return 0;
}