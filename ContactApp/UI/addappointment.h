#ifndef ADDAPPOINTMENT_H
#define ADDAPPOINTMENT_H
#include <vector>
#include <QWidget>
#include <QPushButton>

namespace Ui {
class addAppointment;
}

class addAppointment : public QWidget
{
    Q_OBJECT

public:
    explicit addAppointment(QWidget *parent = nullptr);
    ~addAppointment();
    std::vector<QString> getAppointmentInfo();
private slots:
    void on_submit_appointment();
    void on_back_button();
signals:
    void back();
    void appointmentAdded();
private:
    Ui::addAppointment *ui;


};

#endif // ADDAPPOINTMENT_H
