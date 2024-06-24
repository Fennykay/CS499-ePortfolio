#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "../src/contactdatabase.h"
#include "../src/appointmentdatabase.h"
#include "../src/taskdatabase.h"
#include "../src/appointment.h"
#include "../src/displayContacts.h"
#include "../src/Contact.h"
#include "../src/Task.h"
#include "displayappointments.h"
#include "displaytasks.h"
#include "login.h"
#include "home.h"
#include "addcontact.h"
#include "addappointment.h"
#include "addtask.h"
#include "qstackedwidget.h"
#include <vector>


using std::vector;


class mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    mainwindow(QWidget *parent = nullptr);


private:
    QStackedWidget *stackedWidget;
    login *loginWidget;
    home *homeWidget;
    displayContacts *contactWidget;
    addContact *addContactWidget;
    displayAppointments *appointmentWidget;
    addAppointment *addAppointmentWidget;
    DisplayTasks *taskWidget;
    AddTask *addTaskWidget;


    ContactDatabase contactDb;
    appointmentDatabase appointmentDb;
    TaskDatabase taskDb;

    void setupWidgets();
    void setupConnections();
    void setupDatabase();
    void loadSampleData();

    size_t loginWidgetIndex = 0;
    size_t homeWidgetIndex = 1;
    size_t contactWidgetIndex = 2;
    size_t addContactWidgetIndex = 3;
    size_t appointmentWidgetIndex = 4;
    size_t addAppointmentWidgetIndex = 5;
    size_t taskWidgetIndex = 6;
    size_t addTaskWidgetIndex = 7;

    vector<Contact> searchContacts(const vector<Contact>& list, home* homeWidget);
    vector<Appointment> searchAppointments(const vector<Appointment>& list, home* homeWidget);
    vector<Task> searchTasks(const vector<Task>& list, home* homeWidget);

    bool findSubStringInString(const string& str, const string& substr);

    void Center_Widget();

};

#endif // MAINWINDOW_H
