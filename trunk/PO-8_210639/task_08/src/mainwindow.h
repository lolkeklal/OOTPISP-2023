#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTextLine>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsEllipseItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent*);
    void onTimeout();

private:
    QGraphicsScene* _scene;
    QGraphicsView* _view;
    QTimer* _timer;
    QRect* circle = new QRect(300, 400, 30, 30);
    QLine* line1 = new QLine(300, 415, 250, 415);
    QLine* line2 = new QLine(330, 415, 380, 415);
    QLine* line3 = new QLine(315, 400, 315, 350);
    QLine* line4 = new QLine(315, 430, 315, 480);
    QLine* line5 = new QLine(325, 425, 370, 470);
    QLine* line6 = new QLine(305, 405, 260, 360);
    QLine* line7 = new QLine(325, 405, 370, 360);
    QLine* line8 = new QLine(305, 425, 260, 470);
    QPoint circleCenterPoint = (QPoint(300, 400));

    QPoint line1p1 = line1->p1();
    QPoint line1p2 = line1->p2();

    QPoint line2p1 = line2->p1();
    QPoint line2p2 = line2->p2();

    QPoint line3p1 = line3->p1();
    QPoint line3p2 = line3->p2();

    QPoint line4p1 = line4->p1();
    QPoint line4p2 = line4->p2();

    QPoint line5p1 = line5->p1();
    QPoint line5p2 = line5->p2();

    QPoint line6p1 = line6->p1();
    QPoint line6p2 = line6->p2();

    QPoint line7p1 = line7->p1();
    QPoint line7p2 = line7->p2();

    QPoint line8p1 = line8->p1();
    QPoint line8p2 = line8->p2();
    Ui::MainWindow *ui;
    float a = 0;
    int r = 5;
};
#endif // MAINWINDOW_H
