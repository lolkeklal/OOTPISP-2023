#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent, QPlainTextEdit *textEdit)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->textEdit = textEdit;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setColor() {
    this->textEdit->setStyleSheet(QString("background: rgb(%1, %2, %3);").arg(this->red).arg(this->green).arg(this->blue));
}

void Widget::setRed(int value) {
    this->red = value;
    setColor();
}
void Widget::setGreen(int value) {
    this->green = value;
    setColor();
}
void Widget::setBlue(int value) {
    this->blue = value;
    setColor();
}
