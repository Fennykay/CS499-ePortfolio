#ifndef APPOINTMENTDATABASE_H
#define APPOINTMENTDATABASE_H

#include "sqlite3.h" // Include SQLite header file
#include <string>
#include <vector>
#include "appointment.h"

using std::vector;

class appointmentDatabase
{
public:
    appointmentDatabase(const std::string& dbFilePath);
    ~appointmentDatabase();

    bool openDatabase();
    bool closeDatabase();
    bool createContactTable();
    bool insertAppointment(const Appointment& appointment);
    vector<Appointment> getAppointments();

private:
    sqlite3* m_db;
    std::string m_dbFilePath;
    vector<Appointment> appointmentList;
};

#endif // APPOINTMENTDATABASE_H
