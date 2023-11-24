#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <cmath>

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    CustomWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        setFixedSize(500, 500);
        angle = 0;
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, QOverload<>::of(&CustomWidget::updateAnimation));
        timer->start(10); // Интервал таймера для обновления анимации
    }


protected:
    void paintEvent(QPaintEvent *event) override
    {
        QPainter painter(this);


        QFont font("Literaturnaya Medium", 24);
        painter.setFont(font);

        painter.translate(width(), 0);
        painter.rotate(90);


        painter.drawText(0, 0, height(), width(), Qt::TextWordWrap, "Графические примитивы в библиотеке QT");


        painter.setFont(font);

        int centerX = width() / 2;
        int centerY = height() / 2;

        // Рисование удлиненной циклоиды
        painter.setPen(Qt::black);
        painter.setBrush(Qt::NoBrush);
        int a = 50; // Параметр удлиненной циклоиды
        int b = 30; // Параметр удлиненной циклоиды
        for (double t = -2 * M_PI; t <= 2 * M_PI; t += 0.01)
        {
            int x = centerX + (a * t - b * sin(t));
            int y = centerY - (a - b * cos(t));
        }
            double circle1X = centerX + 50 * cos(angle);
            double circle1Y = centerY + 50 * sin(angle) ;
            double circle2X = centerX + 100 * cos(angle);
            double circle2Y = centerY + 100 * sin(angle);
            double circle3X = centerX + 150 * cos(angle) ;
            double circle3Y = centerY + 150 * sin(angle);

            painter.setPen(Qt::black);
            painter.setBrush(Qt::red);
            painter.drawEllipse(QPointF(circle1X, circle1Y), 10, 10);

            painter.setBrush(Qt::green);
            painter.drawEllipse(QPointF(circle2X, circle2Y), 10, 10);

            painter.setBrush(Qt::blue);
            painter.drawEllipse(QPointF(circle3X, circle3Y), 10, 10);

            painter.drawLine(QPointF(circle1X, circle1Y), QPointF(circle2X, circle2Y));
            painter.drawLine(QPointF(circle2X, circle2Y), QPointF(circle3X, circle3Y));

    }

public slots:
    void updateAnimation()
    {

        angle += 0.01;
        if (angle > 2 * M_PI)
        {
            angle -= 2 * M_PI;
        }
        update();
    }

private:
    QTimer *timer;
    double angle;
};

#include "main.moc"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CustomWidget widget;
    widget.show();

    return a.exec();
}
