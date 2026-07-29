#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include<vector>
#include<string>
#include "task.h"

class TaskManager{
  private:
     std::vector<Task> tasks;
  public:
  bool addTask(const std::string& name,time_t start=0,Priority priority = Priority::MEDIUM, Category category=Category::LIFE,time_t remind=0);
  bool deleteTask(int taskID);
  void loadFile(const std::string& filename);
  void saveFile(const std::string& filename)const;
  const std::vector<Task>& getAll()const;
  const std::vector<Task>& getTasks() const { return tasks; }
};

#endif
