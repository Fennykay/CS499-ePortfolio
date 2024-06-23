#ifndef LOGIN_H
#define LOGIN_H

#include "UI/ui_login.h"
#include "../src/accountdatabase.h"
#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

signals:
    void loginSuccessful(const QString &username);
    void loginFailed(const QString &errorMessage);
    void loginCancelled();

    void createAccount();

private slots:
    void on_loginButton_clicked();
    void on_createAccountButton_clicked();

private:
    Ui::login *ui;
    AccountDatabase accountDb;
};

#endif // LOGIN_H
