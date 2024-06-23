#ifndef ACCOUNTDATABASE_H
#define ACCOUNTDATABASE_H

#include <string>
#include "sqlite3.h"


class AccountDatabase
{
public:
    AccountDatabase(const std::string& dbFilePath);

    bool openDatabase();
    bool closeDatabase();
    bool createAccountTable();

    void addAccount(const std::string& username, const std::string& password);
    bool validateLogin(const std::string& username, const std::string& password);
private:
    std::string m_dbFilePath;
    sqlite3* m_db;
};

#endif // ACCOUNTDATABASE_H
