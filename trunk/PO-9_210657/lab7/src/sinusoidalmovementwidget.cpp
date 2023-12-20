#include "sinusoidalmovementwidget.h"
#include <QPainter>

SinusoidalMovementWidget::SinusoidalMovementWidget(QWidget *parent)
    : QWidget(parent), a(50), b(0), x(0), circleX{0, 0, 0} {

    setFixedSize(600, 200);

    circles[0] = Circle(20, Qt::red, this);
    circles[1] = Circle(20, Qt::green, this);
    circles[2] = Circle(20, Qt::blue, this);

    timer[0] = new QTimer(this);
    connect(timer[0], &QTimer::timeout, this, &SinusoidalMovementWidget::updateAnimation);
    timer[0]->start(16);

    timer[1] = new QTimer(this);
    connect(timer[1], &QTimer::timeout, this, &SinusoidalMovementWidget::updateAnimation2);
    QTimer::singleShot(1000, this, &SinusoidalMovementWidget::startTimer2);

    timer[2] = new QTimer(this);
    connect(timer[2], &QTimer::timeout, this, &SinusoidalMovementWidget::updateAnimation3);
    QTimer::singleShot(2000, this, &SinusoidalMovementWidget::startTimer3);
}

SinusoidalMovementWidget::Circle::Circle() {}

SinusoidalMovementWidget::Circle::Circle(int r, const QColor &c, SinusoidalMovementWidget *p)
    : radius(r), color(c), parent(p) {}

void SinusoidalMovementWidget::Circle::draw(int x, int y) const {
    QPainter painter(parent);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(color);
    painter.drawEllipse(x - radius, y - radius, 2 * radius, 2 * radius);
}

void SinusoidalMovementWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setPen(Qt::black);
    for (int i = 0; i < width(); ++i) {
        int y = height() / 2 - a * std::sin(std::pow(i / 30.0 - x, 2) + b);
        painter.drawPoint(i, y);
    }

    for (int i = 0; i < 3; ++i) {
        int y = height() / 2 - a * std::sin(std::pow(circleX[i], 2) + b);
        circles[i].draw(circleX[i] * 30, y);
    }
}

void SinusoidalMovementWidget::updateAnimation() {
    circleX[0] += 0.05;
    if (circleX[0] > width() / 30.0) {
        circleX[0] = 0;
        timer[0]->stop();
    }
    update();
}

void SinusoidalMovementWidget::updateAnimation2() {
    circleX[1] += 0.05;
    if (circleX[1] > width() / 30.0) {
        circleX[1] = 0;
        timer[1]->stop();
    }
    update();
}

void SinusoidalMovementWidget::updateAnimation3() {
    circleX[2] += 0.05;
    if (circleX[2] > width() / 30.0) {
        circleX[2] = 0;
        timer[2]->stop();
    }
    update();
}

void SinusoidalMovementWidget::startTimer2() {
    timer[1]->start(16);
}

void SinusoidalMovementWidget::startTimer3() {
    timer[2]->start(16);
}
