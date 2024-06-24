#include "accountdatabase.h"
#include <iostream>
#include <ostream>

AccountDatabase::AccountDatabase(const std::string &dbFilePath)
        : m_dbFilePath(dbFilePath), m_db(nullptr){
}

bool AccountDatabase::openDatabase() {
    int rc = sqlite3_open(m_dbFilePath.c_str(), &m_db);
    if (rc) {
        std::cerr << "Error opening SQLite3 database: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    }
    return createAccountTable();
}

bool AccountDatabase::closeDatabase() {
    int rc = sqlite3_close(m_db);
    if (rc) {
        std::cerr << "Error closing SQLite3 database: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    }
    return true;
}

bool AccountDatabase::createAccountTable() {
    char* errMsg;
    const char* sql = "CREATE TABLE IF NOT EXISTS accounts ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "username TEXT NOT NULL,"
                      "password TEXT NOT NULL);";
    int rc = sqlite3_exec(m_db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

void AccountDatabase::addAccount(const std::string &username, const std::string &password) {
    std::string sql = "INSERT INTO accounts (username, password) VALUES ('" +
                      username + "', '" +
                      password + "');";
    char* errMsg;
    int rc = sqlite3_exec(m_db, sql.c_str(), NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error inserting account: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

bool AccountDatabase::validateLogin(const std::string &username, const std::string &password) {
    std::string sql = "SELECT * FROM accounts WHERE username = '" + username + "' AND password = '" + password + "';";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(m_db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    }
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc == SQLITE_ROW;
}




