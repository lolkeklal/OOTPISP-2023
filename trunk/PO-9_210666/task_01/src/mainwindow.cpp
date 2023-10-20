#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGridLayout* grid_layout = new QGridLayout;
    this->centralWidget()->setLayout(grid_layout);

    QVBoxLayout* v_box_layout1 = new QVBoxLayout;
    QVBoxLayout* v_box_layout2 = new QVBoxLayout;
    QVBoxLayout* v_box_layout3 = new QVBoxLayout;
    QVBoxLayout* v_box_layout4 = new QVBoxLayout;
    grid_layout->addLayout(v_box_layout1, 0, 0);
    grid_layout->addLayout(v_box_layout2, 0, 1);
    grid_layout->addLayout(v_box_layout3, 0, 2);
    grid_layout->addLayout(v_box_layout4, 0, 3);

    QLabel* sb_label1 = new QLabel;
    QLabel* sb_label2 = new QLabel;
    QLabel* sb_label3 = new QLabel;
    sb_label1->setText("Red");
    sb_label2->setText("Green");
    sb_label3->setText("Blue");
    v_box_layout1->addWidget(sb_label1, Qt::AlignCenter);
    v_box_layout1->addWidget(sb_label2, Qt::AlignCenter);
    v_box_layout1->addWidget(sb_label3, Qt::AlignCenter);

    sb1 = new QSpinBox;
    sb2 = new QSpinBox;
    sb3 = new QSpinBox;
    sb1->setMaximum(255);
    sb2->setMaximum(255);
    sb3->setMaximum(255);
    v_box_layout2->addWidget(sb1, Qt::AlignCenter);
    v_box_layout2->addWidget(sb2, Qt::AlignCenter);
    v_box_layout2->addWidget(sb3, Qt::AlignCenter);

    sl1 = new QSlider(Qt::Orientation::Horizontal);
    sl2 = new QSlider(Qt::Orientation::Horizontal);
    sl3 = new QSlider(Qt::Orientation::Horizontal);
    sl1->setMinimumWidth(250);
    sl2->setMinimumWidth(250);
    sl3->setMinimumWidth(250);
    sl1->setMaximum(255);
    sl2->setMaximum(255);
    sl3->setMaximum(255);
    v_box_layout3->addWidget(sl1, Qt::AlignCenter);
    v_box_layout3->addWidget(sl2, Qt::AlignCenter);
    v_box_layout3->addWidget(sl3, Qt::AlignCenter);

    txtEdit = new QPlainTextEdit;
    txtEdit->setEnabled(false);
    txtEdit->setStyleSheet("background: #000000;");
    v_box_layout4->addWidget(txtEdit);

    this->resize(450, 200);

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

void MainWindow::setRed(int r_){
    this->r = r_;
    sl1->setValue(r_);
    sb1->setValue(r_);
    setColor();
}
void MainWindow::setGreen(int g_){
    this->g = g_;
    sl2->setValue(g_);
    sb2->setValue(g_);
    setColor();
}
void MainWindow::setBlue(int b_){
    this->b = b_;
    sl3->setValue(b_);
    sb3->setValue(b_);
    setColor();
}
void MainWindow::setColor(){
    this->txtEdit->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(r).arg(g).arg(b));
}
