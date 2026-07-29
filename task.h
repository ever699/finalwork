#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

enum class Priority {
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2
};

enum class Category {
    STUDY = 0,
    ENTERTAINMENT = 1,
    LIFE = 2
};

class Task {
private:
    int id;
    std::string name;
    time_t start_time;
    Priority priority;
    Category category;
    time_t remind_time;

public:
    Task(int taskid, const std::string& taskname, time_t start, Priority p, Category c, time_t remind = 0) {
        this->id = taskid;
        this->name = taskname;
        this->start_time = start;
        this->priority = p;
        this->category = c;
        this->remind_time = remind;
    }

    int GetID() const { return id; }
    std::string GetTaskName() const { return name; }
    time_t GetStartTime() const { return start_time; }
    Priority GetPriority() const { return priority; }
    Category GetCategory() const { return category; }
    time_t GetRemindTime() const { return remind_time; }

    void SetTaskName(const std::string& Taskname) { name = Taskname; }
    void SetStartTime(time_t stime) { start_time = stime; }
    void SetPriority(Priority pp) { priority = pp; }
    void SetCategory(Category cc) { category = cc; }
    void SetRemindTime(time_t rtime) { remind_time = rtime; }
};

#endif
