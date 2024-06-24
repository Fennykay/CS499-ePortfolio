#ifndef APPOINTMENTCARD_H
#define APPOINTMENTCARD_H

#include <QWidget>
#include "../src/appointment.h"

namespace Ui {
class AppointmentCard;
}

class AppointmentCard : public QWidget
{
    Q_OBJECT

public:
    explicit AppointmentCard(const Appointment &appointment, QWidget *parent = nullptr);
    ~AppointmentCard();

private:
    Ui::AppointmentCard *ui;
};

#endif // APPOINTMENTCARD_H
