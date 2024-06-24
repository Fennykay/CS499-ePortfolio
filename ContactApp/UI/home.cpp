#include "home.h"
#include "ui_home.h"

home::home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::home)
{
    ui->setupUi(this);


    connect(ui->display_contacts, &QPushButton::clicked, this, &home::on_displayContactsButton_clicked);
    connect(ui->search_contact_button, &QPushButton::clicked, this, &home::on_searchContactButton_clicked);
    connect(ui->create_contact, &QPushButton::clicked, this, &home::on_addContactButton_clicked);

    connect(ui->display_appointments, &QPushButton::clicked, this, &home::on_displayAppointmentsButton_clicked);
    connect(ui->search_appointments, &QPushButton::clicked, this, &home::on_searchAppointmentButton_clicked);
    connect(ui->add_appointment, &QPushButton::clicked, this, &home::on_addAppointmentButton_clicked);

    connect(ui->display_tasks, &QPushButton::clicked, this, &home::on_displayTasksButton_clicked);
    connect(ui->search_tasks, &QPushButton::clicked, this, &home::on_searchTaskButton_clicked);
    connect(ui->add_task, &QPushButton::clicked, this, &home::on_addTaskButton_clicked);
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

QString home::getContactSearchField()
{
    QString search_content = ui->contact_search_entry->text();
    ui->contact_search_entry->clear();
    return search_content;
}

QString home::getAppointmentSearchField()
{
    QString search_content = ui->appointment_search_entry->text();
    ui->appointment_search_entry->clear();
    return search_content;
}

QString home::getTaskSearchField()
{
    QString search_content = ui->task_search_entry->text();
    ui->task_search_entry->clear();
    return search_content;
}






