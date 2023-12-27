#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(800, 600);


    rectX = 25;
    rectY = 25;
    ellipseX = 0;
    ellipseY = 0;
    rectWidth = 75;
    rectHeight = 50;
    ellipseWidth = 30;
    ellipseHeight = 30;
    rectXDirection = 1;
    ellipseXDirection = 1;
    animationTimer.setInterval(10);

    connect(&this->animationTimer, &QTimer::timeout, this, &MainWindow::updateImage);

    animationTimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    painter.fillRect(rectX, rectY, rectWidth, rectHeight, Qt::red);
    painter.setBrush(Qt::blue);
    painter.drawEllipse(rectX + rectWidth / 2 - ellipseWidth / 2, rectY + rectHeight / 2 - ellipseHeight / 2, ellipseHeight, ellipseHeight);

    QFont font("Fixedsys", 12);
    font.setBold(true);
    painter.setFont(font);

    QString text = "Графические примитивы в Qt";
    int x = 20;
    int y = height() / 2 + 130;

    painter.translate(x, y);
    painter.rotate(-90);

    painter.drawText(0, 10, text);
}

void MainWindow::updateImage(){
    rectX += rectXDirection;
    rectY = height() - 2 * rectHeight - calculateY(rectX - width() / 2) - height() / 2;

    if (rectX <= 0 || rectX + rectWidth >= width())
        rectXDirection *= -1;

//    if (rectY >= 0 || rectY + rectHeight <= -height())
//        rectXDirection *= -1;


    update();
}


int MainWindow::calculateY(int x){
    return (int) (0.000007 * pow(x, 3));
}
