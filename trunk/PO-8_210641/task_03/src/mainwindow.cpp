// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task01.h"
#include "task02.h"
#include "task03.h"
#include "task04.h"
#include "task05.h"
#include "task06.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
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

    resize(400, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTask01Window() {
    Task01Window *w = new Task01Window();
    w->show();
}

void MainWindow::createTask02Window() {
    Task02Window *w = new Task02Window();
    w->show();
}

void MainWindow::createTask03Window() {
    Task03Window *w = new Task03Window();
    w->show();
}

void MainWindow::createTask04Window() {
    Task04Window *w = new Task04Window();
    w->show();
}

void MainWindow::createTask05Window() {
    Task05Window *w = new Task05Window();
    w->show();
}

void MainWindow::createTask06Window() {
    Task06Window *w = new Task06Window();
    w->show();
}
