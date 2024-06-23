#include "addappointment.h"
#include "ui_addappointment.h"

addAppointment::addAppointment(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addAppointment)
{
    ui->setupUi(this);
    connect(ui->submit_appointment, &QPushButton::clicked, this, &addAppointment::on_submit_appointment);
    connect(ui->back_button, &QPushButton::clicked, this, &addAppointment::on_back_button);

    // Load the background image
    QPixmap bkgnd(":/resources/images/backButton.png");
    if (!bkgnd.isNull()) {
        QPixmap scaled = bkgnd.scaled(ui->back_button->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QIcon ButtonIcon(scaled);
        ui->back_button->setIcon(ButtonIcon);
        ui->back_button->setIconSize(ui->back_button->size());
    } else {
        qDebug() << "Error: Image not found!";
    }
}

addAppointment::~addAppointment()
{
    delete ui;
}

std::vector<QString> addAppointment::getAppointmentInfo()
{
    std::vector<QString> info;
    QString name = ui->name_entry->text();
    QDateTime dateTime = ui->date_time_entry->dateTime();
    QString notes = ui->notes_entry->text();

    QDate date = dateTime.date();
    QTime time = dateTime.time();

    QString dateStr = date.toString("d/M/yyyy");
    QString timeStr = time.toString("hh:mm:ss");

    info.push_back(name);
    info.push_back(dateStr);
    info.push_back(timeStr);
    info.push_back(notes);

    return info;
}

void addAppointment::on_submit_appointment()
{
    emit appointmentAdded();
}

void addAppointment::on_back_button()
{
    emit back();
}
