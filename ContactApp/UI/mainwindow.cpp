#include "mainwindow.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QDir>

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent),
    contactDb("ContactApplication.db"),
    appointmentDb("ContactApplication.db"),
    taskDb("ContactApplication.db") {

    // Set the background image for the main window
    QPixmap bkgnd(":/resources/images/neowave.jpg");
    if (!bkgnd.isNull()) {
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        setPalette(palette);
    } else {
        qDebug() << "Error: Image not found!";
    }

    setFixedSize(800, 600);

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);


    setupDatabase();
    setupWidgets();
    setupConnections();
    loadSampleData();

    Center_Widget();
}


void mainwindow::setupWidgets() {
    loginWidget = new login();
    homeWidget = new home();
    contactWidget = new displayContacts();
    addContactWidget = new addContact();
    appointmentWidget = new displayAppointments();
    addAppointmentWidget = new addAppointment();
    taskWidget = new DisplayTasks();
    addTaskWidget = new AddTask();

    stackedWidget->addWidget(loginWidget);    // index 0
    stackedWidget->addWidget(homeWidget);     // index 1
    stackedWidget->addWidget(contactWidget);  // index 2
    stackedWidget->addWidget(addContactWidget);  // index 3
    stackedWidget->addWidget(appointmentWidget);  // index 4
    stackedWidget->addWidget(addAppointmentWidget);  // index 5
    stackedWidget->addWidget(taskWidget);  // index 6
    stackedWidget->addWidget(addTaskWidget);  // index 7

    if (!taskWidget) {
        qDebug() << "Task widget is null";
    }

    stackedWidget->setCurrentIndex(loginWidgetIndex);  // Show login widget initially

    Center_Widget();
}

void mainwindow::setupConnections() {
    connect(loginWidget, &login::loginSuccessful, this, [=]() {
        qDebug() << "Login successful, transitioning to home screen";
        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
        qDebug() << "Current widget index after login: " << stackedWidget->currentIndex();
    });

    connect(loginWidget, &login::createAccount, this, [=]() {
        qDebug() << "Creating account";
        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
        qDebug() << "Current widget index after creating account: " << stackedWidget->currentIndex();
    });

    connect(homeWidget, &home::displayContacts, this, [=]() {
        std::vector<Contact> contactList = contactDb.getContacts();
        contactWidget->populateContacts(contactList);
        qDebug() << "Displaying contacts";
        stackedWidget->setCurrentIndex(contactWidgetIndex);  // Switch to the displayContacts widget
        qDebug() << "Current widget index after displaying contacts: " << stackedWidget->currentIndex();
    });

    connect(homeWidget, &home::searchContact, this, [=]() {
        std::vector<Contact> contactList = contactDb.getContacts();
        std::vector<Contact> searchResults = searchContacts(contactList, homeWidget);
        contactWidget->populateContacts(searchResults);
        qDebug() << "Displaying search results";
        stackedWidget->setCurrentIndex(contactWidgetIndex);  // Switch to the displayContacts widget
        qDebug() << "Current widget index after search: " << stackedWidget->currentIndex();
    });

    connect(contactWidget, &displayContacts::back, this, [=]() {
        contactWidget->resetTableView();
        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
        qDebug() << "Current widget index after back button clicked: " << stackedWidget->currentIndex();
    });

    connect(homeWidget, &home::addContact, this, [=]() {
        stackedWidget->setCurrentIndex(addContactWidgetIndex);  // Switch to the addContact widget
        qDebug() << "Current widget index after addContact: " << stackedWidget->currentIndex();
    });

    connect(addContactWidget, &addContact::back, this, [=]() {
        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
        qDebug() << "Current widget index after back button clicked: " << stackedWidget->currentIndex();
    });

    connect(addContactWidget, &addContact::contactAdded, this, [=]() {
        std::vector<QString> contactData = addContactWidget->getContactInfo();
        for (const auto &data : contactData) {
            qDebug() << data;
        }
        qDebug() << "Done";

        Contact newContact(contactData[0].toStdString(),
                           contactData[1].toStdString(),
                           contactData[2].toStdString(),
                           contactData[3].toStdString(),
                           contactData[4].toStdString(),
                           contactData[5].toStdString(),
                           contactData[6].toStdString(),
                           contactData[7].toStdString(),
                           contactData[8].toStdString());
        qDebug() << " created contact";
        contactDb.insertContact(newContact);
        std::vector<Contact> contactList = contactDb.getContacts();
        contactWidget->populateContacts(contactList);
        qDebug() << "New contact added";
        stackedWidget->setCurrentIndex(contactWidgetIndex);  // Switch to the displayContacts widget
    });

    connect(homeWidget, &home::displayAppointments, this, [=]() {
        std::vector<Appointment> appointmentList = appointmentDb.getAppointments();

        for (auto &appointment : appointmentList) {
            qDebug() << appointment.getDate().c_str();
            QDate date = QDate::fromString(appointment.getDate().c_str(), "d/M/yyyy");
            qDebug() << date;
        }
        appointmentWidget->populateAppointments(appointmentList);
        qDebug() << "Displaying appointments";
        stackedWidget->setCurrentIndex(appointmentWidgetIndex);  // Switch to the displayAppointments widget
        qDebug() << "Current widget index after displaying appointments: " << stackedWidget->currentIndex();
    });

    connect(appointmentWidget, &displayAppointments::back, this, [=]() {
        appointmentWidget->resetTableView();
        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
        qDebug() << "Current widget index after back button clicked: " << stackedWidget->currentIndex();
    });

    connect(homeWidget, &home::searchAppointment, this, [=]() {
        std::vector<Appointment> appointmentList = appointmentDb.getAppointments();
        std::vector<Appointment> searchResults = searchAppointments(appointmentList, homeWidget);
        for (auto &appointment : searchResults) {
            if (searchResults.empty()) {
                qDebug() << "No appointments found";
                break;
            } else {
            qDebug() << appointment.getName().c_str();
            }
        }
        appointmentWidget->populateAppointments(searchResults);
        stackedWidget->setCurrentIndex(appointmentWidgetIndex);  // Switch to the displayAppointments widget
    });

    connect(homeWidget, &home::addAppointment, this, [=]() {
        stackedWidget->setCurrentIndex(addAppointmentWidgetIndex);  // Switch to the addAppointment widget
        qDebug() << "Current widget index after addAppointment: " << stackedWidget->currentIndex();
    });

    connect(addAppointmentWidget, &addAppointment::back, this, [=]() {
        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
        qDebug() << "Current widget index after back button clicked: " << stackedWidget->currentIndex();
    });

    connect(addAppointmentWidget, &addAppointment::appointmentAdded, this, [=]() {
        std::vector<QString> appointmentData = addAppointmentWidget->getAppointmentInfo();
        for (const auto &data : appointmentData) {
            qDebug() << data;
        }
        appointmentDb.insertAppointment(Appointment(appointmentData[0].toStdString(),
                                                    appointmentData[1].toStdString(),
                                                    appointmentData[2].toStdString(),
                                                    appointmentData[3].toStdString()));

        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
    });

    connect(homeWidget, &home::displayTasks, this, [=]() {
        std::vector<Task> taskList = taskDb.getTasks();
        taskWidget->populateTasks(taskList);
        qDebug() << "Displaying tasks";
        stackedWidget->setCurrentIndex(taskWidgetIndex);  // Switch to the displayTasks widget
        qDebug() << "Current widget index after displaying tasks: " << stackedWidget->currentIndex();
    });

    connect(taskWidget, &DisplayTasks::back, this, [=]() {
        taskWidget->resetTableView();
        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
        qDebug() << "Current widget index after back button clicked: " << stackedWidget->currentIndex();
    });

    connect(homeWidget, &home::searchTask, this, [=]() {
        std::vector<Task> taskList = taskDb.getTasks();
        std::vector<Task> searchResults = searchTasks(taskList, homeWidget);
        taskWidget->populateTasks(searchResults);
        qDebug() << "Displaying search results";
        stackedWidget->setCurrentIndex(taskWidgetIndex);  // Switch to the displayTasks widget
        qDebug() << "Current widget index after search: " << stackedWidget->currentIndex();
    });

    connect(homeWidget, &home::addTask, this, [=]() {
        stackedWidget->setCurrentIndex(addTaskWidgetIndex);  // Switch to the addTask widget
        qDebug() << "Current widget index after addTask: " << stackedWidget->currentIndex();
    });

    connect(addTaskWidget, &AddTask::back, this, [=]() {
        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
        qDebug() << "Current widget index after back button clicked: " << stackedWidget->currentIndex();
    });

    connect(addTaskWidget, &AddTask::taskAdded, this, [=]() {
        std::vector<QString> taskData = addTaskWidget->getTaskInfo();
        taskDb.insertTask(Task(taskData[0].toStdString(), taskData[1].toStdString()));
        stackedWidget->setCurrentIndex(homeWidgetIndex);  // Switch to the home widget
    });
}

void mainwindow::setupDatabase() {
    if (!contactDb.openDatabase()) {
        qDebug() << "Failed to open contact database";
        exit(1);
    }

    if (!appointmentDb.openDatabase()) {
        qDebug() << "Failed to open appointment database";
        exit(1);
    }

    if (!taskDb.openDatabase()) {
        qDebug() << "Failed to open user database";
        exit(1);
    } else {
        qDebug() << "Database opened successfully";
    }
}

void mainwindow::loadSampleData() {
    Appointment appointment2("searc", "17/6/2024", "13:00", "TESTING2");
    appointmentDb.insertAppointment(appointment2);

    Contact contact1("TESTING", "1234567890");
    Contact contact2("TESTING2", "0987654321");
    contactDb.insertContact(contact1);
    contactDb.insertContact(contact2);

    Task task1("Clean Room", "Properly vacuum and clean room");
    Task task2("Do Laundry", "Wash and fold clothes");
    taskDb.insertTask(task1);
    taskDb.insertTask(task2);
}

vector<Contact> mainwindow::searchContacts(const vector<Contact>& list, home* homeWidget) {
    // Get the search field from the home widget
    QString searchField = homeWidget->getContactSearchField().trimmed();
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

vector<Appointment> mainwindow::searchAppointments(const vector<Appointment>& list, home* homeWidget) {
    // Get the search field from the home widget
    QString searchField = homeWidget->getAppointmentSearchField().trimmed();
    qDebug() << searchField;
    vector<Appointment> results;

    if (searchField.isEmpty()) {
        return results;
    }

    // Convert search field to lowercase for case-insensitive search
    QString lowerSearchField = searchField.toLower();
    qDebug() << lowerSearchField;

    for (const auto &appointment : list) {
        QString appointmentDate = QString::fromStdString(appointment.getDate()).toLower();

        // Check if the search field is a substring of the appointment date
        if (appointmentDate.contains(lowerSearchField)) {
            results.push_back(appointment);
        }
    }

    return results;
}

vector<Task> mainwindow::searchTasks(const vector<Task>& list, home* homeWidget) {
    // Get the search field from the home widget
    QString searchField = homeWidget->getTaskSearchField().trimmed();
    vector<Task> results;

    if (searchField.isEmpty()) {
        return results;
    }

    // Convert search field to lowercase for case-insensitive search
    QString lowerSearchField = searchField.toLower();

    for (const auto &task : list) {
        QString taskName = QString::fromStdString(task.getTaskName()).toLower();

        if (findSubStringInString(taskName.toStdString(), lowerSearchField.toStdString())) {
            results.push_back(task);
        }
    }

    return results;
}
// custom search algorithm to find substring in string
bool mainwindow::findSubStringInString(const string& str, const string& substr) {
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

void mainwindow::Center_Widget() {
    if (!stackedWidget) return;

    QSize mainSize = size();
    QSize stackSize = stackedWidget->sizeHint();

    int x = (mainSize.width() - stackSize.width()) / 2;
    int y = (mainSize.height() - stackSize.height()) / 2;

    stackedWidget->setGeometry(x, y, stackSize.width(), stackSize.height());
}
