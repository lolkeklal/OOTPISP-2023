#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget* widget = new QWidget();
    this->setCentralWidget(widget);

    QGridLayout* grid_layout = new QGridLayout;
    widget->setLayout(grid_layout);

    QVBoxLayout* layout1 = new QVBoxLayout;
    QVBoxLayout* layout2 = new QVBoxLayout;
    QVBoxLayout* layout3 = new QVBoxLayout;
    QVBoxLayout* layout4 = new QVBoxLayout;
    grid_layout->addLayout(layout1, 0, 0);
    grid_layout->addLayout(layout2, 0, 1);
    grid_layout->addLayout(layout3, 0, 2);
    grid_layout->addLayout(layout4, 0, 3);

    QLabel* sb_label1 = new QLabel;
    QLabel* sb_label2 = new QLabel;
    QLabel* sb_label3 = new QLabel;
    sb_label1->setText("Red");
    sb_label2->setText("Green");
    sb_label3->setText("Blue");
    layout1->addWidget(sb_label1, Qt::AlignCenter);
    layout1->addWidget(sb_label2, Qt::AlignCenter);
    layout1->addWidget(sb_label3, Qt::AlignCenter);

    this->sb1 = new QSpinBox;
    this->sb2 = new QSpinBox;
    this->sb3 = new QSpinBox;
    sb1->setMaximum(255);
    sb2->setMaximum(255);
    sb3->setMaximum(255);
    layout2->addWidget(sb1, Qt::AlignCenter);
    layout2->addWidget(sb2, Qt::AlignCenter);
    layout2->addWidget(sb3, Qt::AlignCenter);


    this->sl1 = new QSlider(Qt::Orientation::Horizontal);
    this->sl2 = new QSlider(Qt::Orientation::Horizontal);
    this->sl3 = new QSlider(Qt::Orientation::Horizontal);

    sl1->setMinimumWidth(250);
    sl2->setMinimumWidth(250);
    sl3->setMinimumWidth(250);
    sl1->setMaximum(255);
    sl2->setMaximum(255);
    sl3->setMaximum(255);
    layout3->addWidget(sl1, Qt::AlignCenter);
    layout3->addWidget(sl2, Qt::AlignCenter);
    layout3->addWidget(sl3, Qt::AlignCenter);

    txtEdit = new QPlainTextEdit;
    txtEdit->setReadOnly(true);
    txtEdit->setStyleSheet("background: #000000;");
    layout4->addWidget(txtEdit);

    this->resize(450, 200);
    this->setWindowTitle("task_01");

    connect(sl1, &QSlider::valueChanged, this, &MainWindow::setRed);
    connect(sl2, &QSlider::valueChanged, this, &MainWindow::setGreen);
    connect(sl3, &QSlider::valueChanged, this, &MainWindow::setBlue);

    connect(sb1, &QSpinBox::valueChanged, this, &MainWindow::setRed);
    connect(sb2, &QSpinBox::valueChanged, this, &MainWindow::setGreen);
    connect(sb3, &QSpinBox::valueChanged, this, &MainWindow::setBlue);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setRed(int r){
    this->sb1->setValue(r);
    this->sl1->setValue(r);
    this->r_=r;
    this->setColor();
}
void MainWindow::setGreen(int g){
    this->sb2->setValue(g);
    this->sl2->setValue(g);
    this->g_=g;
    this->setColor();
}
void MainWindow::setBlue(int b){
    this->sb3->setValue(b);
    this->sl3->setValue(b);
    this->b_=b;
    this->setColor();
}
void MainWindow::setColor(){
    this->txtEdit->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(this->r_).arg(this->g_).arg(this->b_));
}
