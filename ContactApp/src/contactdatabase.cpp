#include "contactdatabase.h"
#include <iostream>
#include <ostream>

ContactDatabase::ContactDatabase(const std::string& dbFilePath)
    : m_db(nullptr), m_dbFilePath(dbFilePath) {
}

ContactDatabase::~ContactDatabase() {
    if (m_db != nullptr) {
        sqlite3_close(m_db);
    }
}

bool ContactDatabase::openDatabase() {
    // Open the SQLite database
    int rc = sqlite3_open(m_dbFilePath.c_str(), &m_db);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    }

    // Create the contacts table if it doesn't exist
    return createContactTable();
}

bool ContactDatabase::closeDatabase() {
    // Close the SQLite database
    int rc = sqlite3_close(m_db);
    m_db = nullptr;
    return rc == SQLITE_OK;
}

bool ContactDatabase::createContactTable() {
    const char* sql = "CREATE TABLE IF NOT EXISTS contacts ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "name TEXT NOT NULL, "
                      "phone_number TEXT NOT NULL);";
    char* errMsg = nullptr;
    int rc = sqlite3_exec(m_db, sql, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool ContactDatabase::insertContact(const Contact& contact) {
    std::string sql = "INSERT INTO contacts (name, phone_number) VALUES ('" + contact.getName() + "', '" + contact.getPhoneNumber() + "');";
    int rc = sqlite3_exec(m_db, sql.c_str(), nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error inserting contact: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    } else {
        std::cout << "Contact inserted successfully" << std::endl;
    }

    return true;
}

vector<Contact> ContactDatabase::getContacts() {
    std::vector<Contact> contactsList;
    // Query sql database for all available contacts
    std::string sql = "SELECT name, phone_number FROM contacts";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(m_db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(m_db) << std::endl;
        return contactsList;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        std::string phone(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        contactsList.emplace_back(name, phone);
    }

    sqlite3_finalize(stmt);
    return contactsList;
}
