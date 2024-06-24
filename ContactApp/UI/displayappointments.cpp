#include "displayappointments.h"
#include "qboxlayout.h"
#include "qtextformat.h"
#include "ui_displayappointments.h"
#include "appointmentcard.h" // Assuming you want to keep using AppointmentCard for display purposes
#include <QListWidgetItem>

displayAppointments::displayAppointments(const vector<Appointment> &appointments, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displayAppointments)
{
    ui->setupUi(this);
    calendar = ui->appointment_calendar;
    populateAppointments(appointments); // Populate appointments during initialization

    connect(ui->back_button, &QPushButton::clicked, this, &displayAppointments::on_backButton_clicked);
    connect(calendar, &QCalendarWidget::clicked, this, &displayAppointments::onDateClicked);

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

    // Initialize the QListWidget
    appointmentListWidget = ui->appointment_list;

    QFont font = appointmentListWidget->font();
    font.setPointSize(40);
    appointmentListWidget->setFont(font);

}

displayAppointments::~displayAppointments()
{
    delete ui;
}

void displayAppointments::populateAppointments(vector<Appointment> appointments) {
    setAppointments(appointments);
    QColor appointmentColor = Qt::red;
    appointmentColor.setAlpha(128);
    if (calendar) {
        for (const Appointment &appointment : appointments) {
            QDate date = QDate::fromString(QString::fromStdString(appointment.getDate()), "d/M/yyyy");
            if (date.isValid()) {
                QTextCharFormat format;
                format.setBackground(appointmentColor);
                calendar->setDateTextFormat(date, format);
            }
        }
    }
}

void displayAppointments::resetTableView()
{
    // Reset the calendar to its default state
    if (calendar) {
        calendar->setDateTextFormat(QDate(), QTextCharFormat()); // Reset all date formats
    }
}

void displayAppointments::clearList()
{
    appointmentListWidget->clear();
}

void displayAppointments::onDateClicked(const QDate &date)
{
    QString dateStr = date.toString("d/M/yyyy");

    // Clear the existing list
    clearList();

    // Add new appointment cards
    for (const Appointment &appointment : appointments) {
        if (appointment.getDate() == dateStr.toStdString()) {
            QListWidgetItem *item = new QListWidgetItem(appointmentListWidget);
            AppointmentCard *card = new AppointmentCard(appointment);

            QMargins margins (100,100,100,100);
            QVBoxLayout *layout = new QVBoxLayout();
            layout->setContentsMargins(margins);
            card->setLayout(layout);

            item->setSizeHint(card->sizeHint());
            appointmentListWidget->setItemWidget(item, card);
        }
    }

    // Ensure the list widget is properly updated
    appointmentListWidget->update();
}

void displayAppointments::on_backButton_clicked()
{
    emit back();
}

