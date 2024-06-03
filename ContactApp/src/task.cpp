#include "task.h"
#include <vector>

using std::vector;

Task::Task() {
    // Default constructor
    setTaskName(INIT);
    setDescription(INIT);
}

Task::Task(string name) {
    setTaskName(name);
    setDescription(INIT);
}

Task::Task(string name, string description) {
    setTaskName(name);
    setDescription(description);
}

Task::~Task() {
    // Destructor
}

void Task::setTaskName(string name) {
    if (name.length() > maxTaskName_Length) {
        this->name = name.substr(0, maxTaskName_Length);
    } else {
        this->name = name;
    }
}

void Task::setTaskID(int taskID) {
    this->taskID = taskID;
}

void Task::setDescription(string description) {
    if (description.length() > maxDescription_Length) {
        this->description = description.substr(0, maxDescription_Length);
    } else {
        this->description = description;
    }
}

string Task::getTaskName() {
    return name;
}

int Task::getTaskID() {
    return taskID;
}

string Task::getDescription() {
    return description;
}


