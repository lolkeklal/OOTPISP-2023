#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label1 = new QLabel("Red:");
    label2 = new QLabel("Green:");
    label3 = new QLabel("Blue:");

    spinBox1 = new QSpinBox();
    slider1 = new QSlider(Qt::Horizontal);
    spinBox1->setMinimum(0);
    spinBox1->setMaximum(255);
    slider1->setMinimum(0);
    slider1->setMaximum(255);

    spinBox2 = new QSpinBox();
    slider2 = new QSlider(Qt::Horizontal);
    spinBox2->setMinimum(0);
    spinBox2->setMaximum(255);
    slider2->setMinimum(0);
    slider2->setMaximum(255);

    spinBox3 = new QSpinBox();
    slider3 = new QSlider(Qt::Horizontal);
    spinBox3->setMinimum(0);
    spinBox3->setMaximum(255);
    slider3->setMinimum(0);
    slider3->setMaximum(255);

    textEdit = new QPlainTextEdit();
    textEdit->setFixedSize(100, 150);
    textEdit->setEnabled(false);

    gridLayout = new QGridLayout();
    gridLayout->addWidget(label1, 0, 0);
    gridLayout->addWidget(spinBox1, 0, 1);
    gridLayout->addWidget(slider1, 0, 2);
    gridLayout->addWidget(label2, 1, 0);
    gridLayout->addWidget(spinBox2, 1, 1);
    gridLayout->addWidget(slider2, 1, 2);
    gridLayout->addWidget(label3, 2, 0);
    gridLayout->addWidget(spinBox3, 2, 1);
    gridLayout->addWidget(slider3, 2, 2);
    gridLayout->addWidget(textEdit, 0, 3, 3, 1);

    connect(slider1, &QSlider::valueChanged, this, &MainWindow::setRed);
    connect(slider2, &QSlider::valueChanged, this, &MainWindow::setGreen);
    connect(slider3, &QSlider::valueChanged, this, &MainWindow::setBlue);

    connect(spinBox1, &QSpinBox::valueChanged, this, &MainWindow::setRed);
    connect(spinBox2, &QSpinBox::valueChanged, this, &MainWindow::setGreen);
    connect(spinBox3, &QSpinBox::valueChanged, this, &MainWindow::setBlue);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(gridLayout);
    setCentralWidget(centralWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setColor() {
    int red = spinBox1->value();
    int green = spinBox2->value();
    int blue = spinBox3->value();

    QColor color(red, green, blue);
    QPalette palette = textEdit->palette();
    palette.setColor(QPalette::Base, color);
    textEdit->setPalette(palette);

    slider1->setValue(red);
    slider2->setValue(green);
    slider3->setValue(blue);
}

void MainWindow::setRed(int value) {
    spinBox1->setValue(value);
    setColor();
}

void MainWindow::setGreen(int value) {
    spinBox2->setValue(value);
    setColor();
}

void MainWindow::setBlue(int value) {
    spinBox3->setValue(value);
    setColor();
}

