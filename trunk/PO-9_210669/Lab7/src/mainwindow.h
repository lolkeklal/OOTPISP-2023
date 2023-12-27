#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTimer>

class CustomWidget : public QWidget {
    Q_OBJECT

public:
    explicit CustomWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void animate();

private:
    QTimer *timer;
    qreal t; // параметр для движения по отрезку
};

#endif
