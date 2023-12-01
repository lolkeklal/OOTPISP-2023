    #include "mainwindow.h"
    #include "./ui_mainwindow.h"
    #include <QPainter>
    #include <QPen>
    #include <QLineF>

    MyWidget::MyWidget(QWidget *parent) : QWidget(parent), frame(0) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MyWidget::animate);
        timer->start(25);
    }

    void MyWidget::paintEvent(QPaintEvent *event) {
        QPainter paint(this);


        paint.save();
        paint.translate(width(), height());
        paint.rotate(-90);
        QFont font("Gothic", 18);
        paint.setFont(font);
        paint.drawText(130, -770, "Графические примитивы в библиотеке QT");
        paint.restore();

        paint.setPen(QPen(Qt::red, 2, Qt::SolidLine));
        paint.setBrush(Qt::green);

        int rectSize = 60;

        int x1 = frame * (width() - rectSize);
        int y1 = frame * (height() - rectSize);

        int x2 = x1 + rectSize;
        int y2 = y1 + rectSize;

        paint.drawRect(x1, y1, rectSize, rectSize);
        paint.drawRect(x2, y1, rectSize, rectSize);
    }

    void MyWidget::animate() {
        frame += 0.01;

        if (frame >= 1) {
            frame = 0;
        }

        update();
    }
