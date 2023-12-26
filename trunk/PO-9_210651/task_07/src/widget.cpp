#include "widget.h"
const QString Widget::label = "Графические примитивы в библиотеке QT";
const QFont Widget::serifFont("Courier", 14);
const int Widget::timer_interval = 1;
const qreal Widget::step = 0.03;

Widget::Widget(QWidget *parent)
    : QWidget{parent}
{
    time = new QTimer(this);
    connect(time, SIGNAL(timeout()), this, SLOT(update_position()));
    time->start(timer_interval);
}
void Widget::paintEvent(QPaintEvent*)
{
    QPainter paint;
    paint.begin(this);
    int X0 = offX+ 150;
    int Y0 = offY + this->height()-50;
    paint.save();

    paint.setBrush(Qt::red);
    paint.drawEllipse(QPointF(X0-25, Y0+25),50,50);
    paint.setBrush(Qt::cyan);
    paint.drawEllipse(QPointF(X0+25, Y0+25),50,50);
    paint.setBrush(Qt::magenta);
    paint.drawEllipse(QPointF(X0, Y0-25),50,50);
    paint.restore();
    paint.save();
    paint.rotate(-90);
    int offset = -this->height();
    paint.translate(offset, 0);
    paint.setFont(serifFont);
    paint.drawText(0, 20, Widget::label);
    paint.restore();
    paint.end();
}

void Widget::update_position()
{
    step_score += step;
    offX = step_score+100;
    offY = -0.00007*pow(step_score,3);
    if(offY<(-this->height()))
        step_score=0;
    update();
}
