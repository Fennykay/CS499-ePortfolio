#ifndef LOGIN_H
#define LOGIN_H

#include "UI/ui_login.h"
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

    // Customization methods
    void setWindowTitle(const QString &title);
    void setPlaceholderText(const QString &usernamePlaceholder, const QString &passwordPlaceholder);

signals:
    void loginSuccessful(const QString &username);
    void loginFailed(const QString &errorMessage);
    void loginCancelled();

private slots:
    void on_loginButton_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
