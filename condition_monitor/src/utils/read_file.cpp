/*
 * @Author: ChengKeyi
 * @Date: 2024-03-12 10:15:18
 * @LastEditors: ChengKeyi
 * @LastEditTime: 2024-03-12 10:35:14
 * @FilePath: /Desktop/monitor/condition_monitor/src/utils/read_file.cpp
 * @Description:
 */
#include "utils/read_file.h"

namespace monitor
{
    bool ReadFile::ReadLine(std::vector<std::string> *args)
    {
        std::string line;
        std::getline(ifs_, line);
        if (ifs_.eof() || line.empty())
        {
            return false;
        }

        std::istringstream line_ss(line);
        while (!line_ss.eof())
        {
            std::string word;
            line_ss >> word;
            args->push_back(word);
        }
        return true;
    }
}