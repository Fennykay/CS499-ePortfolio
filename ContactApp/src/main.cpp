#include "contactdatabase.h"
#include "displayContacts.h"
#include "Contact.h"
#include "taskservice.h"
#include "sqlite3.h"
#include "../UI/login.h"
#include "../UI/home.h"
#include <vector>
#include <string>
#include <QFontDatabase>
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QDebug>
#include <QString>  // Include QString header

using std::vector;
using std::string;

constexpr int loginWidgetIndex = 0;
constexpr int homeWidgetIndex = 1;
constexpr int contactWidgetIndex = 2;

const std::string DATABASE_NAME = "contacts.db";

bool findSubStringInString(const string& str, const string& substr);



// Define a structure to hold widget pointers
struct WidgetSet {
    login *loginWidget;
    displayContacts *contactWidget;
    home *homeWidget;
};

// Setup widgets and add them to the stacked widget
WidgetSet setupWidgets(QStackedWidget &stackedWidget) {
    // Create the widgets
    displayContacts *contactWidget = new displayContacts();
    login *loginWidget = new login();
    home *homeWidget = new home();

    // Add the widgets to the stacked widget
    stackedWidget.addWidget(loginWidget);    // index 0
    stackedWidget.addWidget(homeWidget);     // index 1
    stackedWidget.addWidget(contactWidget);  // index 2

    // Return the widgets
    return { loginWidget, contactWidget, homeWidget };
}

vector<Contact> searchContacts(const vector<Contact>& list, home* homeWidget) {
    // Get the search field from the home widget
    QString searchField = homeWidget->getSearchField().trimmed();
    vector<Contact> results;

    if (searchField.isEmpty()) {
        return results;
    }

    // Convert search field to lowercase for case-insensitive search
    QString lowerSearchField = searchField.toLower();

    for (const auto &contact : list) {
        QString contactName = QString::fromStdString(contact.getName()).toLower();

        if (findSubStringInString(contactName.toStdString(), lowerSearchField.toStdString())) {
            results.push_back(contact);
        }
    }

    return results;
}
// custom search algorithm to find substring in string
bool findSubStringInString(const string& str, const string& substr) {
    // get lengths of both strings
    size_t subStrLength = substr.length();
    size_t strLength = str.length();
    // if the substring is longer than the string, return false
    if (subStrLength > strLength) {
        return false;
    }
    // loop through the string, making sure to not go past the end of the string
    for (int i = 0; i <= (strLength - subStrLength); i++) {
        int j = 0;
        //
        for (; j < subStrLength; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }

        if (j == subStrLength) {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    // Set the background image for the main window
    QPixmap bkgnd(":/resources/images/background.jpg");
    if (!bkgnd.isNull()) {
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        window.setPalette(palette);
    } else {
        qDebug() << "Error: Image not found!";
    }

    window.setFixedSize(800, 600);

    // Create the stacked widget
    QStackedWidget *stackedWidget = new QStackedWidget();

    // Create and set up the contact database
    ContactDatabase db(DATABASE_NAME);
    if (!db.openDatabase()) {
        qDebug() << "Failed to open database";
        return 1;
    }

    Contact contact1("John Doe", "1234567890");
    db.insertContact(contact1);

    // Setup widgets and get the widget set
    WidgetSet widgets = setupWidgets(*stackedWidget);

    vector<Contact> contactList = db.getContacts();

    // Set the login widget as the initial widget
    window.setCentralWidget(stackedWidget);
    stackedWidget->setCurrentIndex(loginWidgetIndex);  // Show login widget initially
    qDebug() << "Initial widget set to login widget";

    // Connect login signals
    QObject::connect(widgets.loginWidget, &login::loginSuccessful, [=]() {
        qDebug() << "Login successful, transitioning to home screen";
        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
        qDebug() << "Current widget index after login: " << stackedWidget->currentIndex();
    });

    // Connect home signals to display contacts
    QObject::connect(widgets.homeWidget, &home::displayContacts, [=]() {
        widgets.contactWidget->populateContacts(contactList);
        qDebug() << "Displaying contacts";
        stackedWidget->setCurrentIndex(contactWidgetIndex);  // Switch to the displayContacts widget
        qDebug() << "Current widget index after displaying contacts: " << stackedWidget->currentIndex();
    });

    // Connect search contacts signal
    QObject::connect(widgets.homeWidget, &home::searchContact, [=]() {
        vector<Contact> searchResults = searchContacts(contactList, widgets.homeWidget);
        widgets.contactWidget->populateContacts(searchResults);
        qDebug() << "Displaying search results";
        stackedWidget->setCurrentIndex(contactWidgetIndex);  // Switch to the displayContacts widget
        qDebug() << "Current widget index after search: " << stackedWidget->currentIndex();
    });

    QObject::connect(widgets.contactWidget, &displayContacts::back, [=]() {
        // reset table widget
        widgets.contactWidget->resetTableView();
        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
        qDebug() << "Current widget index after back button clicked: " << stackedWidget->currentIndex();
    });

    window.show();

    return app.exec();
}
