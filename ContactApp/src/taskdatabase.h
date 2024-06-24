#ifndef TASKDATABASE_H
#define TASKDATABASE_H

#include "Task.h"
#include "sqlite3.h" // Include SQLite header file
#include <string>
#include <vector>

using std::vector;

class TaskDatabase
{
public:
    TaskDatabase(const std::string& dbFilePath);
    ~TaskDatabase();

    bool openDatabase();
    bool closeDatabase();
    bool createTaskTable();
    bool insertTask(const Task& task);
    vector<Task> getTasks();

private:
    sqlite3* m_db;
    std::string m_dbFilePath;
    vector<Task> taskList;
};

#endif // TASKDATABASE_H
