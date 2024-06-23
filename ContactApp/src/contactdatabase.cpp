#include "contactdatabase.h"
#include <iostream>
#include <QDir>

ContactDatabase::ContactDatabase(const std::string& dbFilePath)
    : m_db(nullptr), m_dbFilePath(dbFilePath) {
}

ContactDatabase::~ContactDatabase() {
    if (m_db != nullptr) {
        sqlite3_close(m_db);
    }
}

bool ContactDatabase::openDatabase() {
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
                      "name TEXT, "
                      "phone_number TEXT, "
                      "email TEXT, "
                      "street_address TEXT, "
                      "city TEXT, "
                      "state TEXT, "
                      "zip_code TEXT, "
                      "country TEXT, "
                      "notes TEXT );";
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
    std::string sql = "INSERT INTO contacts (name, phone_number, email, street_address, city, state, zip_code, country, notes) VALUES ('" +
                      contact.getName() + "', '" +
                      contact.getPhoneNumber() + "', '" +
                      contact.getEmail() + "', '" +
                      contact.getStreetAddress() + "', '" +
                      contact.getCity() + "', '" +
                      contact.getState() + "', '" +
                      contact.getZipCode() + "', '" +
                      contact.getCountry() + "', '" +
                      contact.getNotes() + "');";

    int rc = sqlite3_exec(m_db, sql.c_str(), nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error inserting contact: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    } else {
        std::cout << "Contact inserted successfully" << std::endl;
    }

    return true;
}

std::vector<Contact> ContactDatabase::getContacts() {
    std::vector<Contact> contactsList;
    // Query sql database for all available contacts
    std::string sql = "SELECT name, phone_number, email, street_address, city, state, zip_code, country, notes FROM contacts";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(m_db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(m_db) << std::endl;
        return contactsList;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        std::string phone(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        std::string email(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        std::string streetAddress(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        std::string city(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        std::string state(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        std::string zipCode(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        std::string country(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7)));
        std::string notes(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8)));
        contactsList.emplace_back(name, phone, email, streetAddress, city, state, zipCode, country, notes);
    }

    sqlite3_finalize(stmt);
    return contactsList;
}
