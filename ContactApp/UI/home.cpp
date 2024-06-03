#include "home.h"
#include "ui_home.h"

home::home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::home)
{
    ui->setupUi(this);
    connect(ui->display_contacts, &QPushButton::clicked, this, &home::on_displayContactsButton_clicked);
    connect(ui->search_contact_button, &QPushButton::clicked, this, &home::on_searchContactButton_clicked);
}

home::~home()
{
    delete ui;
}

void home::on_displayContactsButton_clicked()
{
    emit displayContacts();
}

void home::on_addContactButton_clicked()
{
    emit addContact();
}

void home::on_addAppointmentButton_clicked()
{
    emit addAppointment();
}

void home::on_displayAppointmentsButton_clicked()
{
    emit displayAppointments();
}

void home::on_addTaskButton_clicked()
{
    emit addTask();
}

void home::on_displayTasksButton_clicked()
{
    emit displayTasks();
}

void home::on_searchContactButton_clicked()
{
    emit searchContact();
}

void home::on_searchAppointmentButton_clicked()
{
    emit searchAppointment();
}

void home::on_searchTaskButton_clicked()
{
    emit searchTask();
}

QString home::getSearchField()
{
    return ui->contact_search_entry->text();
}




