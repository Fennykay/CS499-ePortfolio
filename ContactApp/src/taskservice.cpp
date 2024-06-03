#include "taskservice.h"

TaskService::TaskService() {

}
TaskService::~TaskService() {

}

void TaskService::addTask(string name) {
    Task newTask(name);
    tasks.push_back(newTask);
}

void TaskService::addTask(string name, string description) {
    Task newTask(name, description);
    tasks.push_back(newTask);
}

void TaskService::removeTask(int taskID) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getTaskID() == taskID) {
            tasks.erase(tasks.begin() + i);
            break;
        }
    }
}

void TaskService::updateTask(int taskID, Task task) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getTaskID() == taskID) {
            tasks[i] = task;
            break;
        }
    }
}

Task TaskService::getTask(int taskID) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getTaskID() == taskID) {
            return tasks[i];
        }
    }
    return Task();
}

vector<Task> TaskService::getTasks() {
    return tasks;
}

