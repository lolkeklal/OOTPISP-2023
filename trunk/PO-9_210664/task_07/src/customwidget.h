#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QFont>
#include <QTimer>

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    static const QString label_text;
    static const QFont gotic;
    static const int radius_inner;
    static const int radius_outer;
    static const int timer_interval;
    static const qreal spiral_radius;
    static const qreal spiral_step;

    CustomWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent*);

private:
    qreal offsetX = 0;
    qreal offsetY = 0;
    qreal spiral_angle = 0;
    QTimer* timer;

public:
signals:

private slots:
    void update_position();
};

#endif // CUSTOMWIDGET_H
