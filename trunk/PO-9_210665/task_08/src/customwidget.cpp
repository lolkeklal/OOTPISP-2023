#include "customwidget.h"//_8
const QString CustomWidget::label_ = "Граф. примитивы в библиотеке QT";
const QFont CustomWidget::serifFont("Times", 10, QFont::Bold);
const int CustomWidget::timer_interval = 9; // milisec
const qreal CustomWidget::step = 0.02;
CustomWidget::CustomWidget(QWidget *parent)
    : QWidget{parent}
{
    time = new QTimer(this);
    connect(time, SIGNAL(timeout()), this, SLOT(update_pos()));
    time->start(timer_interval);
}
void CustomWidget::paintEvent(QPaintEvent*)
{
    QPainter painte;
    painte.begin(this);
    int X0 = offX+ 150;
    int Y0 = offY + this->height()-50;
    painte.save();
    painte.setBrush(Qt::blue);
    painte.drawEllipse(QPointF(X0-25, Y0+25),50,50);
    painte.setBrush(Qt::red);
    painte.drawEllipse(QPointF(X0+25, Y0+25),50,50);
    painte.setBrush(Qt::green);
    painte.drawEllipse(QPointF(X0, Y0-25),50,50);
    painte.restore();
    painte.save();
    painte.rotate(-90);
    int offset = -this->height();
    painte.translate(offset, 0);
    painte.setFont(serifFont);
    painte.drawText(0, 20, CustomWidget::label_);
    painte.restore();
    painte.end();
}

void CustomWidget::update_pos()
{
    step_score += step;
    offX = step_score+5;
    offY = -0.1*step_score *step_score * step_score;
    if(offY<(-this->height()))
        step_score=0;
    update(); // redraw
}
