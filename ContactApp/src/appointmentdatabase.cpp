#include "appointmentdatabase.h"
#include <iostream>
#include <ostream>

appointmentDatabase::appointmentDatabase(const string &dbFilePath)
    : m_db(nullptr), m_dbFilePath(dbFilePath){
    }

appointmentDatabase::~appointmentDatabase() {}

bool appointmentDatabase::openDatabase() {
    int rc = sqlite3_open(m_dbFilePath.c_str(), &m_db);
    if (rc) {
        std::cerr << "Error opening SQLite3 database: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    }
    return createContactTable();
}

bool appointmentDatabase::closeDatabase() {
    int rc = sqlite3_close(m_db);
    if (rc) {
        std::cerr << "Error closing SQLite3 database: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    }
    return true;
}

bool appointmentDatabase::createContactTable() {
    char* errMsg;
    const char* sql = "CREATE TABLE IF NOT EXISTS appointments ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "name TEXT NOT NULL,"
                      "date TEXT NOT NULL,"
                      "time TEXT NOT NULL,"
                      "notes TEXT NOT NULL);";
    int rc = sqlite3_exec(m_db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool appointmentDatabase::insertAppointment(const Appointment &appointment) {
    std::string sql = "INSERT INTO appointments (name, date, time, notes) VALUES ('" +
                      appointment.getName() + "', '" +
                      appointment.getDate() + "', '" +
                      appointment.getTime() + "', '" +
                      appointment.getNotes() + "');";
    char* errMsg;
    int rc = sqlite3_exec(m_db, sql.c_str(), NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error inserting appointment: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

std::vector<Appointment> appointmentDatabase::getAppointments() {
    std::vector<Appointment> appointments;
    const char* sql = "SELECT * FROM appointments;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(m_db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(m_db) << std::endl;
        return appointments;
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string time = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string notes = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        appointments.push_back(Appointment(name, date, time, notes));
    }
    sqlite3_finalize(stmt);
    return appointments;
}



