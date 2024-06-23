#include "addtask.h"
#include "ui_addtask.h"

AddTask::AddTask(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddTask)
{
    ui->setupUi(this);

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

    connect(ui->back_button, &QPushButton::clicked, this, &AddTask::on_back_button);
    connect(ui->submit_button, &QPushButton::clicked, this, &AddTask::on_submit_task);

}

AddTask::~AddTask()
{
    delete ui;
}

vector<QString> AddTask::getTaskInfo() {
    vector<QString> taskInfo;

    taskInfo.push_back(ui->task_name_entry->text());
    taskInfo.push_back(ui->task_desc_entry->text());

    return taskInfo;
}

void AddTask::on_submit_task() {
    emit taskAdded();
}

void AddTask::on_back_button() {
    emit back();
}


