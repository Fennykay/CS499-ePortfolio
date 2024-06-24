// contactdatabase.h
#ifndef CONTACTDATABASE_H
#define CONTACTDATABASE_H

#include "Contact.h"
#include "sqlite3.h" // Include SQLite header file
#include <string>
#include <vector>

using std::vector;

class ContactDatabase {
public:
    ContactDatabase(const std::string& dbFilePath);
    ~ContactDatabase();

    bool openDatabase();
    bool closeDatabase();
    bool createContactTable();
    bool insertContact(const Contact& contact);
    vector<Contact> getContacts();

private:
    sqlite3* m_db;
    std::string m_dbFilePath;
    vector<Contact> contactsList;
};

#endif // CONTACTDATABASE_H
