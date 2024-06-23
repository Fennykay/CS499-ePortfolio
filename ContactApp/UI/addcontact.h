#ifndef ADDCONTACT_H
#define ADDCONTACT_H

#include <QWidget>
#include <vector>
#include <QString>
#include <QPixmap>
#include <QIcon>
#include <QDebug>

namespace Ui {
class addContact;
}

class addContact : public QWidget
{
    Q_OBJECT

public:
    explicit addContact(QWidget *parent = nullptr);
    ~addContact();
    std::vector<QString> getContactInfo();

signals:
    void contactAdded();
    void back();

private slots:
    void on_submit_contact();
    void on_back_button();

private:
    Ui::addContact *ui;
};

#endif // ADDCONTACT_H
