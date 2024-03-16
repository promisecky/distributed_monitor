/*
 * @Author: ChengKeyi
 * @Date: 2024-03-15 15:48:38
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-15 16:14:20
 * @FilePath: /Desktop/monitor/monitor_info_manager/net_address.h
 * @Description:
 */
#pragma once
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

namespace monitor
{
    class NetAddress
    {
    public:
        static std::string getIPAddress()
        {
            struct ifaddrs *interfaces = nullptr;
            struct ifaddrs *addr = nullptr;
            void *tmpAddrPtr = nullptr;
            char addressBuffer[INET_ADDRSTRLEN];

            // 获取所有网络接口
            if (getifaddrs(&interfaces) == -1)
            {
                std::cerr << "Failed to get network interfaces" << std::endl;
                return "";
            }

            // 遍历所有接口
            for (addr = interfaces; addr != nullptr; addr = addr->ifa_next)
            {
                if (!addr->ifa_addr)
                {
                    continue;
                }
                // 检查是否为eth0接口且地址是IPv4
                if (addr->ifa_addr->sa_family == AF_INET && strcmp(addr->ifa_name, "eth0") == 0)
                {
                    tmpAddrPtr = &((struct sockaddr_in *)addr->ifa_addr)->sin_addr;

                    inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);

                    break; // 找到eth0的IPv4地址后退出循环
                }
            }

            // 释放接口列表
            freeifaddrs(interfaces);
            return std::string(addressBuffer);
        }

        static std::string getMacAddress(std::string interface = "eth0")
        {
            std::string path = "/sys/class/net/" + interface + "/address";
            std::ifstream file(path);
            std::string mac;

            if (file.is_open())
            {
                std::getline(file, mac); // MAC地址在文件的第一行
                file.close();
            }
            else
            {
                std::cerr << "无法打开文件: " << path << std::endl;
            }

            if (!mac.empty())
            {
                return mac;
            }
            else
            {
                std::cout << "无法获取 " << interface << " 的MAC地址" << std::endl;
                return "";
            }
        }
    };
}