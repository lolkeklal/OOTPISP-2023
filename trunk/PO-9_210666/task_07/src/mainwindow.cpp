#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(800, 600);

    rect1X = 0;
    rect1Y = 0;
    rect2X = 25;
    rect2Y = 25;
    rectWidth = 75;
    rectHeight = 50;
    rect1XDirection = 1;
    rect2XDirection = 1;
    animationTimer.setInterval(1);

    connect(&this->animationTimer, &QTimer::timeout, this, &MainWindow::updateRect);

    animationTimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    painter.fillRect(rect1X, rect1Y, rectWidth, rectHeight, Qt::red);
    painter.fillRect(rect2X, rect2Y, rectWidth, rectHeight, Qt::blue);

    QFont font("Fixedsys", 12);
    painter.setFont(font);

    QString text = "Graphicheskiye primitivi v biblioteke Qt";
    int x = 20;
    int y = height() / 2 + 130;

    painter.translate(x, y);
    painter.rotate(-90);

    painter.drawText(0, 10, text);
}

void MainWindow::updateRect(){
    rect1X += rect1XDirection;
    rect1Y = height() - rectHeight - calculateY(rect1X);
    rect2X += rect2XDirection;
    rect2Y = height() - rectHeight - calculateY(rect2X);

    if (rect1X <= 0 || rect1X + rectWidth >= width())
        rect1XDirection *= -1;

    if (rect2X <= 0 || rect2X + rectWidth >= width())
        rect2XDirection *= -1;

    update();
}

int MainWindow::calculateY(int x){
//    return (int) (0.028 * sqrt(x*x*x));
//    return (int) (0.028 * pow(x, 3/2));
//    return (int) (0.028 * pow(x, 3./2));
    return (int) (0.029 * pow(x, (double) 3/2));
}
