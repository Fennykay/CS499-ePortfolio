#include "appointment.h"

void Appointment::createAppointment(string name, string date, string time, string notes) {
    this->name = name;
    this->date = date;
    this->time = time;
    this->notes = notes;
}

void Appointment::setName(string name) {
    this->name = name;
}

string Appointment::getName() const {
    return name;
}

void Appointment::setDate(string date) {
    this->date = date;
}

string Appointment::getDate() const {
    return date;
}

void Appointment::setTime(string time) {
    this->time = time;
}

string Appointment::getTime() const {
    return time;
}

void Appointment::setNotes(string notes) {
    this->notes = notes;
}

string Appointment::getNotes() const {
    return notes;
}


