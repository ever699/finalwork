#include "taskmanager.h"
#include <fstream>
#include <sstream>
#include <iostream>

// 1. 实现 loadFile（返回类型为 void，匹配 taskmanager.h 的声明）
void TaskManager::loadFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }
    
    // 清空现有任务列表
    tasks.clear();

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string name, startTimeStr;

        // 解析 CSV (格式: 名称,开始时间)
        if (std::getline(ss, name, ',') &&
            std::getline(ss, startTimeStr, ',')) {
            time_t startTime = std::stoll(startTimeStr);
            time_t endTime = startTime + 3600; // 默认时长 1 小时
            
            int nextId = tasks.size() + 1;
            tasks.push_back(Task(nextId, name, startTime, Priority::MEDIUM, Category::LIFE, endTime));
        }
    }
    file.close();
}

// 2. 实现 addTask
bool TaskManager::addTask(const std::string& name, time_t startTime, Priority priority, Category category, time_t endTime) {
    int nextId = tasks.size() + 1;
    tasks.push_back(Task(nextId, name, startTime, priority, category, endTime));
    return true;
}

// 3. 实现 deleteTask
bool TaskManager::deleteTask(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->GetID() == id) {
            tasks.erase(it);
            return true;
        }
    }
    return false;
}
