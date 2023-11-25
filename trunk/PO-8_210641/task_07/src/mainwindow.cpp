#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(800, 600);

    rectangle1PosX = 0;
    rectangle1PosY = 0;
    rectangle2PosX = 25;
    rectangle2PosY = 25;
    rectangleWidth = 75;
    rectangleHeight = 50;
    rectangle1XDirection = 1;
    rectangle2XDirection = 1;
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

    drawShape(painter, rectangle1PosX, height() - rectangleHeight - calculateY(rectangle1PosX), Qt::magenta);
    drawShape(painter, rectangle2PosX, height() - rectangleHeight - calculateY(rectangle2PosX), Qt::blue);

    QFont font("Fixedsys", 12);
    painter.setFont(font);
    drawText(painter, QString::fromUtf8("Графические примитивы в библиотеке Qt"), 20, height() / 2 + 130, -90);
}

void MainWindow::drawShape(QPainter &painter, int x, int y, Qt::GlobalColor color){
    painter.fillRect(x, y, rectangleWidth, rectangleHeight, color);
}

void MainWindow::drawText(QPainter &painter, const QString &text, int x, int y, int rotation){
    painter.save();
    painter.translate(x, y);
    painter.rotate(rotation);
    painter.drawText(0, 0, text);
    painter.restore();
}

void MainWindow::updateRect(){
    rectangle1PosX += rectangle1XDirection;
    rectangle2PosX += rectangle2XDirection;

    rectangle1PosY = height() - rectangleHeight - calculateY(rectangle1PosX);
    rectangle2PosY = height() - rectangleHeight - calculateY(rectangle2PosX);

    if (rectangle1PosX <= 0 || rectangle1PosX + rectangleWidth >= width())
        rectangle1XDirection *= -1;

    if (rectangle2PosX <= 0 || rectangle2PosX + rectangleWidth >= width())
        rectangle2XDirection *= -1;

    update();
}

int MainWindow::calculateY(int x){
    return (int) (0.029 * pow(x, (double) 3/2));
}
