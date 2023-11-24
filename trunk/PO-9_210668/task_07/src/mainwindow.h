#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class CustomWidget : public QWidget {
    Q_OBJECT

public:
    explicit CustomWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QTimer *timer;
    qreal x, y;
    qreal xDirection = 5;

private slots:
    void animate();
};

#endif
