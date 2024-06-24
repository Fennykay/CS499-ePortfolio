#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>


using std::string;

class Appointment
{
public:
    Appointment(
        string name = "",
        string date = "",
        string time = "",
        string notes = ""
        ) : name(name), date(date), time(time), notes(notes) {};
    void createAppointment(string name, string date, string time, string notes);

    void setName(string name);
    string getName() const;

    void setDate(string date);
    string getDate() const;

    void setTime(string time);
    string getTime() const;

    void setNotes(string notes);
    string getNotes() const;


private:
    string name;
    string date;
    string time;
    string notes;
};

#endif // APPOINTMENT_H
