#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    l1 = new QLabel("Red");
    l2 = new QLabel("Green");
    l3 = new QLabel("Blue");

    sb1 = new QSpinBox(this);
    sb2 = new QSpinBox(this);
    sb3 = new QSpinBox(this);

    sb1->setMinimum(0);
    sb1->setMaximum(255);
    sb1->setValue(0);
    sb1->setFixedWidth(50);

    sb2->setMinimum(0);
    sb2->setMaximum(255);
    sb2->setValue(0);
    sb2->setFixedWidth(50);

    sb3->setMinimum(0);
    sb3->setMaximum(255);
    sb3->setValue(0);
    sb3->setFixedWidth(50);

    sl1 = new QSlider(Qt::Horizontal, this);
    sl2 = new QSlider(Qt::Horizontal, this);
    sl3 = new QSlider(Qt::Horizontal, this);

    sl1->setMinimum(0);
    sl1->setMaximum(255);
    sl1->setValue(0);
    sl1->setFixedWidth(256);

    sl2->setMinimum(0);
    sl2->setMaximum(255);
    sl2->setValue(0);
    sl2->setFixedWidth(256);

    sl3->setMinimum(0);
    sl3->setMaximum(255);
    sl3->setValue(0);
    sl3->setFixedWidth(256);

    pte = new QPlainTextEdit(this);

    pte->setFixedWidth(75);
    pte->setEnabled(false);

    layout = new QGridLayout;
    layout->addWidget(l1, 0, 0);
    layout->addWidget(sb1, 0, 1);
    layout->addWidget(sl1, 0, 2);
    layout->addWidget(l2, 1, 0);
    layout->addWidget(sb2, 1, 1);
    layout->addWidget(sl2, 1, 2);
    layout->addWidget(l3, 2, 0);
    layout->addWidget(sb3, 2, 1);
    layout->addWidget(sl3, 2, 2);
    layout->addWidget(pte, 0, 3, 3, 1);
    ui->centralwidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRed(int red){
    sb1->setValue(red);
    sl1->setValue(red);
    setColor();
}

void MainWindow::setGreen(int green){
    sb2->setValue(green);
    sl2->setValue(green);
    setColor();
}

void MainWindow::setBlue(int blue){
    sb3->setValue(blue);
    sl3->setValue(blue);
    setColor();
}

void MainWindow::setColor(){
    QString style="QPlainTextEdit { background: #";
    QString temp;
    temp = QString::number(sb1->value(), 16);
    style += temp;
    temp = QString::number(sb2->value(), 16);
    style += temp;
    temp = QString::number(sb3->value(), 16);
        style += temp;
    style += "; }";
    pte->setStyleSheet(style);
}
