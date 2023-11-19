#include "customwidget.h"

const QString CustomWidget::label_text = "Графические примитивы в библиотеке QT";
const QFont CustomWidget::gotic("MS Gothic", 11, QFont::ExtraBold);
const int CustomWidget::radius_inner = 15; // px
const int CustomWidget::radius_outer = 60; // px
const int CustomWidget::timer_interval = 10; // miliseconds
const qreal CustomWidget::spiral_radius = 10; // px
const qreal CustomWidget::spiral_step = 0.02;

CustomWidget::CustomWidget(QWidget *parent)
    : QWidget{parent}
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_position()));
    timer->start(timer_interval);
}

void CustomWidget::paintEvent(QPaintEvent*)
{
    QPainter painter;

    painter.begin(this);

    // Colorful moving figure
    int centerX = offsetX + this->width() / 2;
    int centerY = offsetY + this->height() / 2;
    painter.save();

    painter.setBrush(Qt::blue);
    QPolygonF snowflake;
    int n = 24;
    for (int i = 0; i < n; i++) {
        qreal fAngle = ::qDegreesToRadians(360.0 * i / n);
        qreal x = centerX + cos(fAngle) * ( i % 4 < 2 ? radius_outer : radius_inner);
        qreal y = centerY + sin(fAngle) * ( i % 4 < 2 ? radius_outer : radius_inner);
        snowflake << QPointF(x, y);
    }
    painter.drawPolygon(snowflake);
    painter.drawEllipse(QPointF(centerX, centerY), radius_inner, radius_inner);

    painter.restore();

    // Vertical text
    painter.save();

    painter.rotate(-90);
    int offset = -this->height();
    painter.translate(offset, 0);

    painter.setFont(gotic);
    painter.drawText(0, 20, CustomWidget::label_text);

    painter.restore();
    painter.end();
}

void CustomWidget::update_position()
{
    spiral_angle += spiral_step;
    offsetX = spiral_radius * spiral_angle * cos(spiral_angle);
    offsetY = spiral_radius * spiral_angle * sin(spiral_angle);

    update(); // redraw widget
}
