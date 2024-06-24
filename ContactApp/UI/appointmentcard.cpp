#include "appointmentcard.h"
#include "UI/ui_appointmentcard.h"

AppointmentCard::AppointmentCard(const Appointment &appointment, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppointmentCard)
{
    ui->setupUi(this);

    ui->name_label->setText(QString::fromStdString(appointment.getName()));
    ui->date_label->setText(QString::fromStdString(appointment.getDate()));
    ui->time_label->setText(QString::fromStdString(appointment.getTime()));
    ui->notes_label->setText(QString::fromStdString(appointment.getNotes()));

}

AppointmentCard::~AppointmentCard()
{
    delete ui;
}
