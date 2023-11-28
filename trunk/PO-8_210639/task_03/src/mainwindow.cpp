#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task01.h"
#include "task02.h"
#include "task03.h"
#include "task04.h"
#include "task05.h"
#include "task06.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    

    task01Button = new QPushButton("task_01");
    task02Button = new QPushButton("task_02");
    task03Button = new QPushButton("task_03");
    task04Button = new QPushButton("task_04");
    task05Button = new QPushButton("task_05");
    task06Button = new QPushButton("task_06");

    connect(task01Button, &QPushButton::clicked, this, &MainWindow::createTask01Window);
    connect(task02Button, &QPushButton::clicked, this, &MainWindow::createTask02Window);
    connect(task03Button, &QPushButton::clicked, this, &MainWindow::createTask03Window);
    connect(task04Button, &QPushButton::clicked, this, &MainWindow::createTask04Window);
    connect(task05Button, &QPushButton::clicked, this, &MainWindow::createTask05Window);
    connect(task06Button, &QPushButton::clicked, this, &MainWindow::createTask06Window);

    QGridLayout* layout = new QGridLayout();

    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(2, 1);

    layout->addWidget(task01Button, 0, 1);
    layout->addWidget(task02Button, 1, 1);
    layout->addWidget(task03Button, 2, 1);
    layout->addWidget(task04Button, 3, 1);
    layout->addWidget(task05Button, 4, 1);
    layout->addWidget(task06Button, 5, 1);

    ui->centralwidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTask01Window() {
    task01* w = new task01();
    w->setMaximumSize(QSize(100, 100));
    w->show();
}

void MainWindow::createTask02Window() {
    task02* w = new task02();
    w->show();
}

void MainWindow::createTask03Window() {
    task03* w = new task03();
    w->show();
}

void MainWindow::createTask04Window() {
    task04* w = new task04();
    w->show();
}

void MainWindow::createTask05Window() {
    task05* w = new task05();
    w->show();
}

void MainWindow::createTask06Window() {
    task06* w = new task06();
    w->show();
}
