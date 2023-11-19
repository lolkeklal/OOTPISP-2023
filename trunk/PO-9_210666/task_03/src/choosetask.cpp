#include "choosetask.h"
#include "ui_choosetask.h"

#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"

ChooseTask::ChooseTask(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseTask)
{
    ui->setupUi(this);

    setWindowTitle("Choose task");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    Task1* task1 = new Task1();
    connect(ui->task1PushButton, &QPushButton::clicked, task1, &Task1::show);
    Task2* task2 = new Task2();
    connect(ui->task2PushButton, &QPushButton::clicked, task2, &Task2::show);
    Task3* task3 = new Task3();
    connect(ui->task3PushButton, &QPushButton::clicked, task3, &Task3::show);
    Task4* task4 = new Task4();
    connect(ui->task4PushButton, &QPushButton::clicked, task4, &Task4::show);
    Task5* task5 = new Task5();
    connect(ui->task5PushButton, &QPushButton::clicked, task5, &Task5::show);
    Task6* task6 = new Task6();
    connect(ui->task6PushButton, &QPushButton::clicked, task6, &Task6::show);
}

ChooseTask::~ChooseTask()
{
    delete ui;
}
