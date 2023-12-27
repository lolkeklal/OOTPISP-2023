// l7.h
#ifndef L7_H
#define L7_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class l7; }
QT_END_NAMESPACE

class l7 : public QMainWindow
{
    Q_OBJECT

public:
    l7(QWidget *parent = nullptr);
    ~l7();

private slots:
    void updateAnimation();

private:
    Ui::l7 *ui;
    QGraphicsScene *scene;
    QGraphicsItemGroup *groupItem;
    QTimer *timer;
    double phi;

    void drawText();
    void drawRectangleAndCircle();
};

#endif // L7_H
