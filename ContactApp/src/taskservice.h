#ifndef TASKSERVICE_H
#define TASKSERVICE_H

#include <vector>
#include <string>
#include "Task.h"

using std::vector;
using std::string;

class TaskService {
public:
    TaskService();
    ~TaskService();
    void addTask(string name);
    void addTask(string name, string description);
    void removeTask(int taskID);
    void updateTask(int taskID, Task task);
    Task getTask(int taskID);
    vector<Task> getTasks();

private:
    vector<Task> tasks;

};

#endif // TASKSERVICE_H
