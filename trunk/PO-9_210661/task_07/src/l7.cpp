#include "l7.h"
#include "ui_l7.h"
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>
#include <cmath>

l7::l7(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::l7),
    phi(0)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    drawText();
    drawRectangleAndCircle();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateAnimation()));
    timer->start(20);
}

l7::~l7()
{
    delete ui;
}

void l7::drawText()
{
    QGraphicsTextItem *textItem = new QGraphicsTextItem("Графические примитивы в библиотеке Qt");
    QFont font("Courier", 14, QFont::Bold);
    textItem->setFont(font);
    scene->addItem(textItem);
}

void l7::drawRectangleAndCircle()
{
    QPen pen(Qt::black);

    QGraphicsRectItem *rectItem = new QGraphicsRectItem(0, 0, 40, 20);
    rectItem->setPen(pen);
    rectItem->setBrush(Qt::red);

    QGraphicsEllipseItem *circleItem = new QGraphicsEllipseItem(0, 0, 20, 20);
    circleItem->setPen(pen);
    circleItem->setBrush(Qt::green);

    QGraphicsItemGroup *group = new QGraphicsItemGroup();
    group->addToGroup(rectItem);
    group->addToGroup(circleItem);

    group->setPos(0, 0);

    scene->addItem(group);

    groupItem = group;
}

void l7::updateAnimation()
{
    double a = 50;

    double x = a * (phi - sin(phi));
    double y = a * (1 - cos(phi));

    groupItem->setPos(x, y);

    phi += 0.02;
}
