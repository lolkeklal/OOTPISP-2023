#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QFont>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(800, 600);

    // Инициализация параметров для фигуры и движения по спирали
    spiralRadius = 10;
    spiralAngle = 0;
    animationTimer.setInterval(10);

    connect(&this->animationTimer, &QTimer::timeout, this, &MainWindow::updateSpiral);

    animationTimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Рисование цветной фигуры на пьедестале с учетом спирали
    drawShape(painter, width() / 2 + rectanglePosX, height() / 2 + rectanglePosY, Qt::magenta);


    // Вывод наименования лабораторной работы
    QFont font("Arial", 14, QFont::Bold);
    painter.setFont(font);
    drawText(painter, QString::fromUtf8("Графические примитивы в библиотеке Qt"), 20, height() / 2 + 130, -90);
}

void MainWindow::drawShape(QPainter &painter, int x, int y, Qt::GlobalColor color)
{
    // Размеры пьедестала
    int pedestalWidth = 100;
    int pedestalHeight = 20;

    // Рисование пьедестала
    painter.fillRect(x - pedestalWidth / 2, y + rectangleHeight, pedestalWidth, pedestalHeight, Qt::darkGray);

    // Рисование прямоугольника на пьедестале
    painter.fillRect(x - rectangleWidth / 2, y, rectangleWidth, rectangleHeight, color);
}

void MainWindow::drawText(QPainter &painter, const QString &text, int x, int y, int rotation)
{
    painter.save();
    painter.translate(x, y);
    painter.rotate(rotation);
    painter.drawText(0, 0, text);
    painter.restore();
}

void MainWindow::updateSpiral()
{
    // Update coordinates for the coiling spiral motion
    double spiralTurns = 3;  // Количество витков спирали
    double spiralStep = 0.05;  // Плотность спирали

    // Update angle and convert to polar coordinates
    spiralAngle += spiralStep;  // Сохраняем знак для того, чтобы спираль закручивалась внутрь
    rectanglePosX = spiralRadius * (spiralTurns * 2 * M_PI - spiralAngle) * cos(spiralAngle);
    rectanglePosY = spiralRadius * (spiralTurns * 2 * M_PI - spiralAngle) * sin(spiralAngle);

    if (spiralAngle >= 2 * M_PI * spiralTurns)
    {
        spiralAngle = 0; 
        animationTimer.start(); 
    }

    update();
}


