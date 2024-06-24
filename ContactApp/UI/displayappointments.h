#ifndef DISPLAYAPPOINTMENTS_H
#define DISPLAYAPPOINTMENTS_H

#include <QWidget>
#include <QListWidget>
#include "../src/appointment.h"
#include "qcalendarwidget.h"

using std::vector;

namespace Ui {
class displayAppointments;
}

class displayAppointments : public QWidget
{
    Q_OBJECT

public:
    explicit displayAppointments(const vector<Appointment> &appointments = {}, QWidget *parent = nullptr);
    void populateAppointments(vector<Appointment> appointments);
    void resetTableView();
    ~displayAppointments();

private slots:
    void on_backButton_clicked();
    void onDateClicked(const QDate &date);

signals:
    void back();

private:
    Ui::displayAppointments *ui;
    QCalendarWidget *calendar;

    vector<Appointment> appointments;

    QListWidget *appointmentListWidget;

    void clearList();
    void setAppointments(vector<Appointment> appointments) {this->appointments = appointments;}
};

#endif // DISPLAYAPPOINTMENTS_H
