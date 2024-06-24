#ifndef ADDTASK_H
#define ADDTASK_H

#include <QWidget>
#include <vector>

using std::vector;

namespace Ui {
class AddTask;
}

class AddTask : public QWidget
{
    Q_OBJECT

public:
    explicit AddTask(QWidget *parent = nullptr);
    ~AddTask();

    vector<QString> getTaskInfo();
signals:
    void taskAdded();
    void back();

private slots:
    void on_submit_task();
    void on_back_button();
private:
    Ui::AddTask *ui;
};

#endif // ADDTASK_H
