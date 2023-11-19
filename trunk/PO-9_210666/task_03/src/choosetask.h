#ifndef CHOOSETASK_H
#define CHOOSETASK_H

#include <QMainWindow>

namespace Ui {
class ChooseTask;
}

class ChooseTask : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseTask(QWidget *parent = nullptr);
    ~ChooseTask();

private slots:

private:
    Ui::ChooseTask *ui;
};

#endif // CHOOSETASK_H
