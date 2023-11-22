#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <locale>
#include <QLabel>
#include <QTextCodec>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &MainWindow::onTimeout);
    _timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{

    QString str;
    QTextCodec* codec = QTextCodec::codecForName("CP1251");
    assert(codec);
    str = codec->toUnicode("Графические примитивы в библиотеке QT");

    QPainter painter(this);
    QFont font("Gothic", 14, QFont::Bold);
    painter.setFont(font);
    painter.translate(0, height());
    painter.rotate(-90);
    painter.drawText(0, 0, height(), width(), Qt::TextWordWrap, str);

    painter.setBrush(Qt::blue);

    painter.drawEllipse(*circle);
    painter.drawLine(*line1);
    painter.drawLine(*line2);
    painter.drawLine(*line3);
    painter.drawLine(*line4);
    painter.drawLine(*line5);
    painter.drawLine(*line6);
    painter.drawLine(*line7);
    painter.drawLine(*line8);

}

void MainWindow::onTimeout()
{
    QPoint newPos = QPoint(circleCenterPoint.x() + (r * cos(a)), circleCenterPoint.y() + (r * sin(a)));
    circle->moveTo(newPos);

    newPos = QPoint(line1p1.x() + (r * cos(a)), line1p1.y() + (r * sin(a)));
    line1->setP1(newPos);
    newPos = QPoint(line1p2.x() + (r * cos(a)), line1p2.y() + (r * sin(a)));
    line1->setP2(newPos);

    newPos = QPoint(line2p1.x() + (r * cos(a)), line2p1.y() + (r * sin(a)));
    line2->setP1(newPos);
    newPos = QPoint(line2p2.x() + (r * cos(a)), line2p2.y() + (r * sin(a)));
    line2->setP2(newPos);

    newPos = QPoint(line3p1.x() + (r * cos(a)), line3p1.y() + (r * sin(a)));
    line3->setP1(newPos);
    newPos = QPoint(line3p2.x() + (r * cos(a)), line3p2.y() + (r * sin(a)));
    line3->setP2(newPos);

    newPos = QPoint(line4p1.x() + (r * cos(a)), line4p1.y() + (r * sin(a)));
    line4->setP1(newPos);
    newPos = QPoint(line4p2.x() + (r * cos(a)), line4p2.y() + (r * sin(a)));
    line4->setP2(newPos);

    newPos = QPoint(line5p1.x() + (r * cos(a)), line5p1.y() + (r * sin(a)));
    line5->setP1(newPos);
    newPos = QPoint(line5p2.x() + (r * cos(a)), line5p2.y() + (r * sin(a)));
    line5->setP2(newPos);

    newPos = QPoint(line6p1.x() + (r * cos(a)), line6p1.y() + (r * sin(a)));
    line6->setP1(newPos);
    newPos = QPoint(line6p2.x() + (r * cos(a)), line6p2.y() + (r * sin(a)));
    line6->setP2(newPos);

    newPos = QPoint(line7p1.x() + (r * cos(a)), line7p1.y() + (r * sin(a)));
    line7->setP1(newPos);
    newPos = QPoint(line7p2.x() + (r * cos(a)), line7p2.y() + (r * sin(a)));
    line7->setP2(newPos);

    newPos = QPoint(line8p1.x() + (r * cos(a)), line8p1.y() + (r * sin(a)));
    line8->setP1(newPos);
    newPos = QPoint(line8p2.x() + (r * cos(a)), line8p2.y() + (r * sin(a)));
    line8->setP2(newPos);

    a += 0.4;
    r += 5;

    update();
}

