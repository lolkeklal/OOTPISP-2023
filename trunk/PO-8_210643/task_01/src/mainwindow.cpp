#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QGridLayout* grid = new QGridLayout;
    this->centralWidget()->setLayout(grid);

    QVBoxLayout* vBoxLayout1 = new QVBoxLayout;
    QVBoxLayout* vBoxLayout2 = new QVBoxLayout;
    QVBoxLayout* vBoxLayout3 = new QVBoxLayout;
    QVBoxLayout* vBoxLayout4 = new QVBoxLayout;
    grid->addLayout(vBoxLayout1, 0, 0);
    grid->addLayout(vBoxLayout2, 0, 1);
    grid->addLayout(vBoxLayout3, 0, 2);
    grid->addLayout(vBoxLayout4, 0, 3);

    QLabel* colorLabel1 = new QLabel;
    QLabel* colorLabel2 = new QLabel;
    QLabel* colorLabel3 = new QLabel;
    colorLabel1->setText("Red");
    colorLabel1->setStyleSheet("color:red");
    colorLabel2->setText("Green");
    colorLabel2->setStyleSheet("color:green");
    colorLabel3->setText("Blue");
    colorLabel3->setStyleSheet("color:blue");

    vBoxLayout1->addWidget(colorLabel1, Qt::AlignCenter);
    vBoxLayout1->addWidget(colorLabel2, Qt::AlignCenter);
    vBoxLayout1->addWidget(colorLabel3, Qt::AlignCenter);

    sBox1 = new QSpinBox;
    sBox2 = new QSpinBox;
    sBox3 = new QSpinBox;

    sBox1->setMaximum(255);
    sBox2->setMaximum(255);
    sBox3->setMaximum(255);
    vBoxLayout2->addWidget(sBox1, Qt::AlignCenter);
    vBoxLayout2->addWidget(sBox2, Qt::AlignCenter);
    vBoxLayout2->addWidget(sBox3, Qt::AlignCenter);


    slider1 = new QSlider(Qt::Orientation::Horizontal);
    slider2 = new QSlider(Qt::Orientation::Horizontal);
    slider3 = new QSlider(Qt::Orientation::Horizontal);


    slider1->setMinimumWidth(250);
    slider2->setMinimumWidth(250);
    slider3->setMinimumWidth(250);
    slider1->setMaximum(255);
    slider2->setMaximum(255);
    slider3->setMaximum(255);
    vBoxLayout3->addWidget(slider1, Qt::AlignCenter);
    vBoxLayout3->addWidget(slider2, Qt::AlignCenter);
    vBoxLayout3->addWidget(slider3, Qt::AlignCenter);

    txtEdit = new QPlainTextEdit;
    txtEdit->setEnabled(false);
    vBoxLayout4->addWidget(txtEdit);

    this->resize(450, 200);

    connect(slider1, &QSlider::valueChanged, this, &MainWindow::setRed);
    connect(slider2, &QSlider::valueChanged, this, &MainWindow::setGreen);
    connect(slider3, &QSlider::valueChanged, this, &MainWindow::setBlue);

    connect(sBox1, &QSpinBox::valueChanged, this, &MainWindow::setRed);
    connect(sBox2, &QSpinBox::valueChanged, this, &MainWindow::setGreen);
    connect(sBox3, &QSpinBox::valueChanged, this, &MainWindow::setBlue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRed(int r_){
    this->r = r_;
    slider1->setValue(r_);
    sBox1->setValue(r_);
    setColor();
}
void MainWindow::setGreen(int g_){
    this->g = g_;
    slider2->setValue(g_);
    sBox2->setValue(g_);
    setColor();
}
void MainWindow::setBlue(int b_){
    this->b = b_;
    slider3->setValue(b_);
    sBox3->setValue(b_);
    setColor();
}
void MainWindow::setColor(){
    this->txtEdit->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(r).arg(g).arg(b));
}

