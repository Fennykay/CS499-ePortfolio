#include "displayContacts.h"
#include <QStandardItem>
#include <QVBoxLayout>
#include <QDebug>

displayContacts::displayContacts(const std::vector<Contact> &contacts, QWidget *parent)
    : QWidget(parent), model(new QStandardItemModel(this)) {
    ui.setupUi(this);
    connect(ui.back_button, &QPushButton::clicked, this, &displayContacts::on_backButton_clicked);
    setupTableView(contacts);

    // Load the background image
    QPixmap bkgnd(":/resources/images/backButton.png");
    if (!bkgnd.isNull()) {
        QPixmap scaled = bkgnd.scaled(ui.back_button->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QIcon ButtonIcon(scaled);
        ui.back_button->setIcon(ButtonIcon);
        ui.back_button->setIconSize(ui.back_button->size());
    } else {
        qDebug() << "Error: Image not found!";
    }
}

displayContacts::~displayContacts() {
    delete model;
}

void displayContacts::setupTableView(const std::vector<Contact> &contacts) {
    model->setHorizontalHeaderLabels({"Name", "Phone Number", "Email", "Address", "City", "State", "Zip Code", "Country", "Notes"});

    for (const auto &contact : contacts) {
        QList<QStandardItem*> items;
        items.append(new QStandardItem(QString::fromStdString(contact.getName())));
        items.append(new QStandardItem(QString::fromStdString(contact.getPhoneNumber())));
        items.append(new QStandardItem(QString::fromStdString(contact.getEmail())));
        items.append(new QStandardItem(QString::fromStdString(contact.getStreetAddress())));
        items.append(new QStandardItem(QString::fromStdString(contact.getCity())));
        items.append(new QStandardItem(QString::fromStdString(contact.getState())));
        items.append(new QStandardItem(QString::fromStdString(contact.getZipCode())));
        items.append(new QStandardItem(QString::fromStdString(contact.getCountry())));
        items.append(new QStandardItem(QString::fromStdString(contact.getNotes())));
        model->appendRow(items);

        // resize columns to fit content
        ui.contactTable->resizeColumnsToContents();
    }

    ui.contactTable->setModel(model);
    ui.contactTable->resizeColumnsToContents();
    ui.contactTable->resizeRowsToContents();
    ui.contactTable->setSortingEnabled(true);
}

void displayContacts::populateContacts(const std::vector<Contact> &contacts) {
    setupTableView(contacts);
}

void displayContacts::on_backButton_clicked() {
    qDebug() << "Back button clicked";
    emit back();
}

void displayContacts::resetTableView() {
    model->clear();
}
