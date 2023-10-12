#include "colorchanger.h"
#include "ui_colorchanger.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>

ColorChanger::ColorChanger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ColorChanger)
{
    ui->setupUi(this);
    QGridLayout* layout = new QGridLayout;
    ui->centralwidget->setLayout(layout);

    this->resize(450, 100);

    QVBoxLayout* VBL1 = new QVBoxLayout;
    QVBoxLayout* VBL2 = new QVBoxLayout;
    QVBoxLayout* VBL3 = new QVBoxLayout;
    QVBoxLayout* VBL4 = new QVBoxLayout;
    layout->addLayout(VBL1, 0, 0);
    layout->addLayout(VBL2, 0, 1);
    layout->addLayout(VBL3, 0, 2);
    layout->addLayout(VBL4, 0, 3);

    sliders = new QSlider[3];
    spinBoxes = new QSpinBox[3];


    QLabel* labels = new QLabel[3];
    labels[0].setText("Red");
    labels[1].setText("Green");
    labels[2].setText("Blue");


    for (int i = 0; i < 3; i++) {
        VBL1->addWidget(&labels[i], Qt::AlignCenter);
        spinBoxes[i].setMaximum(255);
        VBL2->addWidget(&spinBoxes[i], Qt::AlignCenter);
        sliders[i].setOrientation(Qt::Orientation::Horizontal);
        sliders[i].setMinimumWidth(255);
        sliders[i].setMaximum(255);
        VBL3->addWidget(&sliders[i], Qt::AlignCenter);
    }


    textEdit = new QPlainTextEdit;
    textEdit->setEnabled(false);
    textEdit->setStyleSheet("background: #000000;");
    VBL4->addWidget(textEdit);

    connect(&sliders[0], &QSlider::valueChanged, this, &ColorChanger::setRed);
    connect(&sliders[1], &QSlider::valueChanged, this, &ColorChanger::setGreen);
    connect(&sliders[2], &QSlider::valueChanged, this, &ColorChanger::setBlue);
    connect(&spinBoxes[0], &QSpinBox::valueChanged, this, &ColorChanger::setRed);
    connect(&spinBoxes[1], &QSpinBox::valueChanged, this, &ColorChanger::setGreen);
    connect(&spinBoxes[2], &QSpinBox::valueChanged, this, &ColorChanger::setBlue);

}

ColorChanger::~ColorChanger()
{
    delete ui;
}


void ColorChanger::setRed(int red_){
    this->red = red_;
    sliders[0].setValue(red_);
    spinBoxes[0].setValue(red_);
    setColor();
}
void ColorChanger::setGreen(int green_){
    this->green = green_;
    sliders[1].setValue(green_);
    spinBoxes[1].setValue(green_);
    setColor();
}
void ColorChanger::setBlue(int blue_){
    this->blue = blue_;
    sliders[2].setValue(blue_);
    spinBoxes[2].setValue(blue_);
    setColor();
}
void ColorChanger::setColor(){
    this->textEdit->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(red).arg(green).arg(blue));
}
