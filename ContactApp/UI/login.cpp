#include "login.h"

login::login(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::login)
    , accountDb("accountdatabase.db")
{
    ui->setupUi(this);
    // initialize the database
    accountDb.openDatabase();

    // Set style sheets for rounded edges
    QString lineEditStyle = "QLineEdit {"
                            "border: 1px solid gray;"
                            "border-radius: 10px;"
                            "padding: 5px;"
                            "}";

    ui->Username_entry->setStyleSheet(lineEditStyle);
    ui->Password_entry->setStyleSheet(lineEditStyle);

    connect(ui->Submit_login, &QPushButton::clicked, this, &login::on_loginButton_clicked);
    connect(ui->create_account_button, &QPushButton::clicked, this, &login::on_createAccountButton_clicked);
}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()
{
    QString username = ui->Username_entry->text();
    QString password = ui->Password_entry->text();

    if (accountDb.validateLogin(username.toStdString(), password.toStdString())) {
        emit loginSuccessful(username);
    } else {
        emit loginFailed("Invalid username or password");
    }
}

void login::on_createAccountButton_clicked()
{
    QString username = ui->Username_entry->text();
    QString password = ui->Password_entry->text();

    if (username.isEmpty() || password.isEmpty()) {
        emit loginFailed("Username and password cannot be empty");
        return;
    }

    accountDb.addAccount(username.toStdString(), password.toStdString());
    emit createAccount();
}


