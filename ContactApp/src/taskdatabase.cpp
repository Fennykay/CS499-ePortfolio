#include "TaskDatabase.h"
#include <iostream>
#include <QDir>

// Constructor
TaskDatabase::TaskDatabase(const std::string& dbFilePath) : m_db(nullptr), m_dbFilePath(dbFilePath) {}

// Destructor
TaskDatabase::~TaskDatabase() {
    if (m_db != nullptr) {
        sqlite3_close(m_db);
    }
}

// Open the database connection
bool TaskDatabase::openDatabase() {
    // Print the full path of the database file
    std::string fullPath = QDir::currentPath().toStdString() + "/" + m_dbFilePath;
    std::cout << "Opening database at: " << fullPath << std::endl;

    // Open the SQLite database
    int rc = sqlite3_open(fullPath.c_str(), &m_db);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    }

    // Create the contacts table if it doesn't exist
    return createTaskTable();
}

// Close the database connection
bool TaskDatabase::closeDatabase() {
    if (m_db) {
        int result = sqlite3_close(m_db);
        if (result != SQLITE_OK) {
            std::cerr << "Cannot close database: " << sqlite3_errmsg(m_db) << std::endl;
            return false;
        }
        m_db = nullptr;
    }
    return true;
}

// Create the tasks table
bool TaskDatabase::createTaskTable() {
    const char* sql =
        "CREATE TABLE IF NOT EXISTS Tasks ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "description TEXT"
        ");";

    char* errorMsg = nullptr;
    int result = sqlite3_exec(m_db, sql, nullptr, nullptr, &errorMsg);
    if (result != SQLITE_OK) {
        std::cerr << "SQL error: " << errorMsg << std::endl;
        sqlite3_free(errorMsg);
        return false;
    }
    return true;
}

// Insert a task into the tasks table
bool TaskDatabase::insertTask(const Task& task) {
    const char* sql = "INSERT INTO Tasks (Name, Description) VALUES (?, ?);";
    sqlite3_stmt* stmt;

    int result = sqlite3_prepare_v2(m_db, sql, -1, &stmt, 0);
    if (result != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, task.getTaskName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, task.getDescription().c_str(), -1, SQLITE_TRANSIENT);

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(m_db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

// Retrieve all tasks from the tasks table
vector<Task> TaskDatabase::getTasks() {
    vector<Task> tasks;
    const char* sql = "SELECT name, description FROM Tasks;";
    sqlite3_stmt* stmt;

    int result = sqlite3_prepare_v2(m_db, sql, -1, &stmt, nullptr);
    if (result != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(m_db) << std::endl;
        return tasks;
    }

    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        string description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

        Task task(name, description);
        tasks.push_back(task);
    }

    if (result != SQLITE_DONE) {
        std::cerr << "Failed to retrieve data: " << sqlite3_errmsg(m_db) << std::endl;
    }

    sqlite3_finalize(stmt);
    return tasks;
}
