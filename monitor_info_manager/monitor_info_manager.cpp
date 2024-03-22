/*
 * @Author: ChengKeyi
 * @Date: 2024-03-15 14:35:31
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-19 12:15:34
 * @FilePath: /Desktop/monitor/monitor_info_manager/monitor_info_manager.cpp
 * @Description:
 */

#include "monitor_info_manager.h"

namespace monitor
{
    MonitorInfoManager::~MonitorInfoManager()
    {
        mysql_close(&mysql);
        std::cout << "释放管理类" << std::endl;
    };

    // 初始化连接数据库
    bool MonitorInfoManager::readDataBaseInfo(const std::string &configFileName)
    {
        std::ifstream file(configFileName); // 假设文件名为config.txt
        if (!file.is_open())
        {
            std::cerr << "无法打开文件" << std::endl;
            return 1;
        }
        std::string line;
        while (std::getline(file, line))
        {
            size_t pos = line.find('=');
            if (pos != std::string::npos)
            {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                if (key == "USER")
                {
                    this->USER = value;
                }
                else if (key == "PW")
                {
                    this->PW = value;
                }
                else if (key == "IP")
                {
                    this->IP = value;
                }
                else if (key == "dataBase")
                {
                    this->dataBase = value;
                }
            }
        }
        file.close();
        // 初始化数据库
        mysql_init(&mysql);
        // 设置字符编码
        mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8mb4");
        // 连接数据库
        if (mysql_real_connect(&mysql, this->IP.c_str(), this->USER.c_str(), this->PW.c_str(), this->dataBase.c_str(), 3306, NULL, 0) == NULL)
        {
            std::cout << mysql_error(&mysql) << "  连接失败！" << std::endl;
            return false;
        }
        std::cout << "连接数据库" << std::endl;
        return true;
    };

    // 根据HostInfo获得hostID
    bool MonitorInfoManager::getHostId(const std::string &ip, const std::string &mac, int *hostId)
    {
        // std::cout << "获取hostid" << std::endl;
        // std::string ip = monitor::NetAddress().getIPAddress();
        // std::string mac = monitor::NetAddress().getMacAddress();

        *hostId = -1; // 通过解引用指针来赋值

        std::string query = "SELECT host_id FROM host WHERE host_ip = '" + ip + "' AND mac_address = '" + mac + "' LIMIT 1";

        if (mysql_query(&mysql, query.c_str()) == 0)
        {
            MYSQL_RES *result = mysql_store_result(&mysql);
            if (result)
            {
                MYSQL_ROW row = mysql_fetch_row(result);
                if (row && row[0])
                {
                    // 如果找到了记录，获取host_id
                    *hostId = std::stoi(row[0]);
                }
                mysql_free_result(result);
            }
        }
        else
        {
            std::cerr << "查询失败：" << mysql_error(&mysql) << std::endl;
            return -1;
        }
        if (*hostId == -1)
        {
            // 如果没有找到记录，插入新记录
            std::string insertQuery = "INSERT INTO host (host_name, host_ip, mac_address, create_time, description) VALUES ('" + ip + "', '" + ip + "', '" + mac + "', NOW(), 'Auto-generated')";
            if (mysql_query(&mysql, insertQuery.c_str()) == 0)
            {
                // 获取新插入记录的host_id
                *hostId = mysql_insert_id(&mysql);
                std::cout << "host_id: " << *hostId << std::endl;
                return true;
            }
            else
            {
                std::cerr << "插入失败：" << mysql_error(&mysql) << std::endl;
                return false;
            }
        }
    };

    bool MonitorInfoManager::writeIntoDataBase(const monitor::proto::MonitorInfo &monitor_info)
    {
        std::string timeStamp = systemClock();
        this->writeCpuLoad(monitor_info.cpu_load(), timeStamp, monitor_info.host_id());
        this->writeMemInfo(monitor_info.mem_info(), timeStamp, monitor_info.host_id());
        this->writeSoftIrq(monitor_info.soft_irq(), timeStamp, monitor_info.host_id());
        this->writeCpuStat(monitor_info.cpu_stat(), timeStamp, monitor_info.host_id());
        this->writeNetInfo(monitor_info.net_info(), timeStamp, monitor_info.host_id());
        return true;
    };

    // 插入cpu_load中的信息
    bool MonitorInfoManager::writeCpuLoad(const monitor::proto::CpuLoad &cpu_load, const std::string &timeStamp, const int &hostId)
    {
        // 使用ostringstream来构建SQL语句
        std::ostringstream sql;
        sql << "INSERT INTO cpu_load (timestamp, host_id, load_avg_1, load_avg_5, load_avg_15) VALUES ('"
            << timeStamp + "', "
            << hostId << ", "
            << cpu_load.load_avg_1() << ", "
            << cpu_load.load_avg_5() << ", "
            << cpu_load.load_avg_15() << ")";

        // 执行SQL语句
        if (mysql_query(&this->mysql, sql.str().c_str()))
        {
            std::cerr << "插入cpu_load失败: " << mysql_error(&this->mysql) << std::endl;
            return false;
        }
        return true;
    };

    // 插入mem_info中的信息
    bool MonitorInfoManager::writeMemInfo(const monitor::proto::MemInfo &mem_info, const std::string &timeStamp, const int &hostId)
    {
        // 使用ostringstream来构建SQL语句
        std::ostringstream sql;
        sql << "INSERT INTO mem_info (timestamp, host_id, total, free, avail, buffers, cached, \
            swap_cached, active, inactive, active_anon, inactive_anon, active_file, inactive_file, \
            dirty, writeback, anon_pages, mapped, sReclaimable, sUnreclaim, used_percent) VALUES ('"
            << timeStamp + "', "
            << hostId << ", "
            << mem_info.total() << ", "
            << mem_info.free() << ", "
            << mem_info.avail() << ", "
            << mem_info.buffers() << ", "
            << mem_info.cached() << ", "
            << mem_info.swap_cached() << ", "
            << mem_info.active() << ", "
            << mem_info.inactive() << ", "
            << mem_info.active_anon() << ", "
            << mem_info.inactive_anon() << ", "
            << mem_info.active_file() << ", "
            << mem_info.inactive_file() << ", "
            << mem_info.dirty() << ", "
            << mem_info.writeback() << ", "
            << mem_info.anon_pages() << ", "
            << mem_info.mapped() << ", "
            << mem_info.sreclaimable() << ", "
            << mem_info.sunreclaim() << ", "
            << mem_info.used_percent() << ")";

        // 执行SQL语句
        if (mysql_query(&this->mysql, sql.str().c_str()))
        {
            std::cerr << "插入mem_info失败: " << mysql_error(&this->mysql) << std::endl;
            return false;
        }
        return true;
    }

    // 插入softirq中的信息
    bool MonitorInfoManager::writeSoftIrq(const google::protobuf::RepeatedPtrField<::monitor::proto::SoftIrq> &
                                              softIrqs,
                                          const std::string &timeStamp, const int &hostId)
    {

        for (const auto &softirq : softIrqs)
        {
            // 使用ostringstream来构建SQL语句
            std::ostringstream sql;
            sql << "INSERT INTO cpu_softirq (timestamp, host_id, cpu_name, hi, \
                timer, net_tx, net_rx, block, irq_poll, tasklet, sched, hrtimer, rcu) VALUES ('"
                << timeStamp + "', "
                << hostId << ", '"
                << softirq.cpu() << "', "
                << softirq.hi() << ", "
                << softirq.timer() << ", "
                << softirq.net_tx() << ", "
                << softirq.net_rx() << ", "
                << softirq.block() << ", "
                << softirq.irq_poll() << ", "
                << softirq.tasklet() << ", "
                << softirq.sched() << ", "
                << softirq.hrtimer() << ", "
                << softirq.rcu() << ")";

            // 执行SQL语句
            if (mysql_query(&this->mysql, sql.str().c_str()))
            {
                std::cerr << "插入cpu_softirq失败: " << mysql_error(&this->mysql) << std::endl;
                return false;
            }
        }
        return true;
    };

    // 插入cpu_stat中的信息
    bool MonitorInfoManager::writeCpuStat(const google::protobuf::RepeatedPtrField<::monitor::proto::CpuStat> &
                                              cpuStats,
                                          const std::string &timeStamp, const int &hostId)
    {

        for (const auto &cpu_stat : cpuStats)
        {
            // 使用ostringstream来构建SQL语句
            std::ostringstream sql;
            sql << "INSERT INTO cpu_stat (timestamp, host_id, cpu_name,\
            cpu_percent, usr_percent, system_percent, nice_percent,\
            idle_percent, io_wait_percent, irq_percent, soft_irq_percent) VALUES ('"
                << timeStamp + "', "
                << hostId << ", '"
                << cpu_stat.cpu_name() << "', "
                << cpu_stat.cpu_percent() << ", "
                << cpu_stat.usr_percent() << ", "
                << cpu_stat.system_percent() << ", "
                << cpu_stat.nice_percent() << ", "
                << cpu_stat.idle_percent() << ", "
                << cpu_stat.io_wait_percent() << ", "
                << cpu_stat.irq_percent() << ", "
                << cpu_stat.soft_irq_percent() << ")";

            // 执行SQL语句
            if (mysql_query(&this->mysql, sql.str().c_str()))
            {
                std::cerr << "插入cpu_stat失败: " << mysql_error(&this->mysql) << std::endl;
                return false;
            }
        }
        return true;
    };

    // 插入net——info中的信息
    bool MonitorInfoManager::writeNetInfo(const google::protobuf::RepeatedPtrField<::monitor::proto::NetInfo> &
                                              netInfos,
                                          const std::string &timeStamp, const int &hostId)
    {

        for (const auto &net_info : netInfos)
        {
            // 使用ostringstream来构建SQL语句
            std::ostringstream sql;
            sql << "INSERT INTO net_info (timestamp, host_id, name,\
            send_rate, rcv_rate, send_packets_rate, rcv_packets_rate) VALUES ('"
                << timeStamp + "', "
                << hostId << ", '"
                << net_info.name() << "', "
                << net_info.send_rate() << ", "
                << net_info.rcv_rate() << ", "
                << net_info.send_packets_rate() << ", "
                << net_info.rcv_packets_rate() << ")";

            // 执行SQL语句
            if (mysql_query(&this->mysql, sql.str().c_str()))
            {
                std::cerr << "插入net_info失败: " << mysql_error(&this->mysql) << std::endl;
                return false;
            }
        }
        return true;
    };

    std::string MonitorInfoManager::systemClock()
    {
        // 获取当前系统时间
        boost::chrono::system_clock::time_point now = boost::chrono::system_clock::now();

        // 转换为time_t
        std::time_t now_c = boost::chrono::system_clock::to_time_t(now);

        // 转换为tm结构（假设为本地时间）
        std::tm now_tm = *std::localtime(&now_c);

        // 创建一个字符串流
        std::ostringstream oss;

        // 使用put_time将tm格式化为MySQL DATETIME格式
        oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");

        // 返回格式化的字符串
        return oss.str();
    };
}