#include "displaytasks.h"
#include "ui_displaytasks.h"

DisplayTasks::DisplayTasks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayTasks),
    model(new QStandardItemModel(this))
{
    ui->setupUi(this);

    // Set up the table view with an empty task list initially
    setupTableView(tasks);

    // Connect the back button signal to the slot
    connect(ui->back_button, &QPushButton::clicked, this, &DisplayTasks::on_backButton_clicked);

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

DisplayTasks::~DisplayTasks() {
    delete ui;
}

void DisplayTasks::setupTableView(const std::vector<Task> &tasks) {
    // Define column headers
    model->setColumnCount(2);
    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "Description");

    // Populate the table view with tasks
    populateTasks(tasks);

    // Set the model for the table view
    ui->tasksDisplay->setModel(model);
}

void DisplayTasks::populateTasks(const std::vector<Task> &tasks) {
    model->removeRows(0, model->rowCount()); // Clear existing rows

    for (const Task &task : tasks) {
        QList<QStandardItem*> row;
        row.append(new QStandardItem(QString::fromStdString(task.getTaskName())));
        row.append(new QStandardItem(QString::fromStdString(task.getDescription())));
        model->appendRow(row);
        // resize columns to fit content
        ui->tasksDisplay->resizeColumnsToContents();
    }
}

void DisplayTasks::resetTableView() {
    model->removeRows(0, model->rowCount()); // Clear existing rows
    tasks.clear(); // Clear the tasks vector
}

void DisplayTasks::on_backButton_clicked() {
    emit back(); // Emit the back signal
}
