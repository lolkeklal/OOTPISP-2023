#ifndef SINUSOIDALMOVEMENTWIDGET_H
#define SINUSOIDALMOVEMENTWIDGET_H

#include <QWidget>
#include <QTimer>
#include <cmath>

class SinusoidalMovementWidget : public QWidget {
    Q_OBJECT
public:
    SinusoidalMovementWidget(QWidget *parent = nullptr);

private:
    struct Circle {
        int radius;
        QColor color;
        SinusoidalMovementWidget *parent;

        Circle();
        Circle(int r, const QColor &c, SinusoidalMovementWidget *p);

        void draw(int x, int y) const;
    };

    void paintEvent(QPaintEvent *event) override;
    void updateAnimation();
    void updateAnimation2();
    void updateAnimation3();
    void startTimer2();
    void startTimer3();

    double a, b, x, circleX[3];
    Circle circles[3];
    QTimer *timer[3];
};

#endif // SINUSOIDALMOVEMENTWIDGET_H
