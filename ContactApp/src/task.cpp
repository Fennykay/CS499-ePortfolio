#include <string>
#include "task.h"

using std::string;


Task::Task() {
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
    this->name = (name.length() > maxTaskName_Length) ? name.substr(0, maxTaskName_Length) : name;
}

string Task::getTaskName() const  {
    return name;
}

void Task::setDescription(string description) {
    this->description = (description.length() > maxDescription_Length) ? description.substr(0, maxDescription_Length) : description;
}

string Task::getDescription() const  {
    return description;
}
