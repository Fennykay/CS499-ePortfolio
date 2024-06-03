#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <vector>


using std::vector;

namespace Ui {
class home;
}

class home : public QWidget
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    QString getSearchField();
    ~home();

signals:
    void displayContacts();
    void addContact();
    void searchContact();

    void displayAppointments();
    void addAppointment();
    void searchAppointment();

    void displayTasks();
    void addTask();
    void searchTask();

private slots:
    void on_displayContactsButton_clicked();
    void on_addContactButton_clicked();
    void on_searchContactButton_clicked();

    void on_addAppointmentButton_clicked();
    void on_displayAppointmentsButton_clicked();
    void on_searchAppointmentButton_clicked();

    void on_addTaskButton_clicked();
    void on_displayTasksButton_clicked();
    void on_searchTaskButton_clicked();
private:
    Ui::home *ui;
};

#endif // HOME_H
