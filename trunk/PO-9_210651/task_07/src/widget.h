#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QFont>
#include <QTimer>
class Widget : public QWidget
{
    Q_OBJECT

public:
    static const QString label;
    static const QFont serifFont;
    static const int timer_interval;
    static const qreal step;
    Widget(QWidget *parent = nullptr);

signals:
private slots:
    void update_position();

protected:
    void paintEvent(QPaintEvent*);

private:
    qreal offX = 0;
    qreal offY = 0;
    qreal step_score = 0;
    QTimer* time;
};


#endif // WIDGET_H
