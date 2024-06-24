#include "sqlite3.h"
#include <../UI/addcontact.h>
#include <QFontDatabase>
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QDebug>
#include <QString>  // Include QString header
#include "../UI/mainwindow.h"



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    mainwindow window;
    window.show();

    return app.exec();
}
