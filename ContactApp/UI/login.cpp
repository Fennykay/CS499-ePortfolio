#include "login.h"
#include <iostream>

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    connect(ui->Submit_login, &QPushButton::clicked, this, &login::on_loginButton_clicked);
}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()
{
    QString username = ui->Username_entry->text();
    QString password = ui->Password_entry->text();

    if (username == "admin" && password == "admin")
    {
        emit loginSuccessful(username);
        std::cout << "Login successful" << std::endl;
    }
    else
    {
        emit loginFailed("Invalid username or password");
        std::cout << "Login failed" << std::endl;
    }
}

