#include "addcontact.h"
#include "ui_addcontact.h"

addContact::addContact(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addContact)
{
    ui->setupUi(this);
    connect(ui->submit_button, &QPushButton::clicked, this, &addContact::on_submit_contact);
    connect(ui->back_button, &QPushButton::clicked, this, &addContact::on_back_button);

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

addContact::~addContact()
{
    delete ui;
}

std::vector<QString> addContact::getContactInfo() {
    std::vector<QString> contactInfo;

    contactInfo.push_back(ui->name_entry->text());
    contactInfo.push_back(ui->phone_number_entry->text());
    contactInfo.push_back(ui->email_entry->text());
    contactInfo.push_back(ui->address_entry->text());
    contactInfo.push_back(ui->city_entry->text());
    contactInfo.push_back(ui->state_entry->text());
    contactInfo.push_back(ui->zip_entry->text());
    contactInfo.push_back(ui->country_entry->text());
    contactInfo.push_back(ui->notes_entry->text());

    return contactInfo;
}

void addContact::on_submit_contact() {
    emit contactAdded();
}

void addContact::on_back_button() {
    emit back();
}
