#include "mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QFont>

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent), x(0), y(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CustomWidget::animate);
    timer->start(50);
}

void CustomWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));
    painter.drawRect(this->rect());

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    painter.setBrush(Qt::blue);

    qreal sinY = 50 * sin(x * 0.1);
    y = height() / 2 - 25 + sinY;

    QRectF rect(x, y, 50, 50);
    painter.drawRect(rect);

    QRectF circle(x + 10, y - 30, 30, 30);
    painter.drawEllipse(circle);

    QFont font("Book Antiqua", 12);
    painter.setFont(font);
    painter.translate(20, height() - 20);
    painter.rotate(-90);
    painter.drawText(0, 0, "Графические примитивы в библиотеке QT");
}

void CustomWidget::animate() {
    x += xDirection;

    if (x >= width() - 50 || x <= 0) {
        xDirection *= -1;
    }

    update();
}
