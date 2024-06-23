#ifndef DISPLAYTASKS_H
#define DISPLAYTASKS_H

#include "qstandarditemmodel.h"
#include <QWidget>
#include <vector>
#include "../src/task.h"

namespace Ui {
class DisplayTasks;
}

class DisplayTasks : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayTasks(QWidget *parent = nullptr);
    void populateTasks(const std::vector<Task> &tasks);
    void resetTableView();
    ~DisplayTasks();
private slots:
    void on_backButton_clicked();
signals:
    void back();
private:
    Ui::DisplayTasks *ui;
    QStandardItemModel *model;

    std::vector<Task> tasks;

    void setupTableView(const std::vector<Task> &tasks);
};

#endif // DISPLAYTASKS_H
