#ifndef SNOWMANWIDGET_H
#define SNOWMANWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

namespace Ui {
class CustomWidget;
}

class SnowmanWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SnowmanWidget(QWidget *parent = nullptr);
    ~SnowmanWidget();


protected:
    void paintEvent(QPaintEvent *event) override;
    void drawSnowman(QPainter &painter, int x, int y, int radius, QColor color);

public slots:
    void updateAnimation();

private:
    Ui::CustomWidget *ui;
    QTimer *timer;
    double angle;
    int shift{0};
};

#endif // SNOWMANWIDGET_H
