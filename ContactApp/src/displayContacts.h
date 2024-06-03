#ifndef DISPLAYCONTACTS_H
#define DISPLAYCONTACTS_H

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include "Contact.h"
#include "../UI/ui_displayContacts.h"
#include <vector>


class displayContacts : public QWidget
{
    Q_OBJECT

public:
    displayContacts(const std::vector<Contact> &contacts, QWidget *parent = nullptr);
    displayContacts(QWidget *parent = nullptr);
    void populateContacts(const std::vector<Contact> &contacts);
    void resetTableView();
    ~displayContacts();
private slots:
    void on_backButton_clicked();
signals:
    void back();
private:
    QStandardItemModel *model;
    Ui::displayContacts ui;

    std::vector<Contact> contacts;

    void setupTableView(const std::vector<Contact> &contacts);

};



#endif // DISPLAYCONTACTS_H
