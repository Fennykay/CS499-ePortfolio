#ifndef TASK_H
#define TASK_H

#include <string>

using std::string;

class Task {
    static int idCounter;

private:
    static const int maxTaskName_Length = 20;
    static const int maxDescription_Length = 50;
    string INIT = " ";
    string INIT_NUM = "123456789";
    string name;
    string description;

public:
    Task();
    Task(string name);
    Task(string name, string description);
    ~Task();

    void setTaskName(string name);
    void setDescription(string description);

    string getTaskName() const;
    string getDescription() const;
};

#endif // TASK_H
