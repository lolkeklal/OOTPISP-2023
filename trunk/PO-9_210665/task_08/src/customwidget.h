#ifndef CUSTOMWIDGET_H//_8
#define CUSTOMWIDGET_H//_8
//210665
#include <QWidget>//210665
#include <QPainter>//210665
#include <QFont>//210665
#include <QTimer>//210665
class CustomWidget : public QWidget//210665
{
    Q_OBJECT//210665
public:
    static const QString label_;
    static const QFont serifFont;
    static const int timer_interval;
    static const qreal step;
    CustomWidget(QWidget *parent = nullptr);
signals:
private slots:
    void update_pos();
protected:
    void paintEvent(QPaintEvent*);//_8
private:
    qreal offX = 0;
    qreal offY = 0;
    qreal step_score = 0;
    QTimer* time;
};
//210665
//210665
#endif // CUSTOMWIDGET_H
