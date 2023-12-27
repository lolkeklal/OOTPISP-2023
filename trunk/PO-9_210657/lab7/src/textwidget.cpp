#include "textwidget.h"
#include <QPainter>

TextWidget::TextWidget(QWidget *parent) : QWidget(parent) {}

void TextWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QFont font;
    font.setPointSize(14);
    font.setWeight(QFont::Light);
    painter.setFont(font);
    painter.rotate(-90);
    painter.drawText(-400, 100, QString::fromUtf8("Графические примитивы библиотеки QT"));
}
