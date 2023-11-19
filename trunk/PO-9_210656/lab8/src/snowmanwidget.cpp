#include "snowmanwidget.h"
#include "ui_snowmanwidget.h"

SnowmanWidget::SnowmanWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomWidget)
{
    ui->setupUi(this);
    setFixedSize(500, 500);
    angle = 0;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&SnowmanWidget::updateAnimation));
    timer->start(10); // Интервал таймера для обновления анимации
}

SnowmanWidget::~SnowmanWidget()
{
    delete ui;
}

void SnowmanWidget::updateAnimation(){
    angle += 0.05;
    if (angle > 2 * M_PI) {
        angle -= 2 * M_PI;
    }

    static bool direction = true;
    if (shift == 150)
        direction = false;
    if (shift == -150)
        direction = true;
    shift += (direction ? 1 : -1);
    update();
}

void SnowmanWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    drawSnowman(painter, width() / 2 + shift, height() / 2 + 50 + 50 * std::cos(angle+0.4), 50, Qt::red);
    drawSnowman(painter, width() / 2 + shift, height() / 2 + 50 * std::cos(angle+0.4), 40, Qt::yellow);
    drawSnowman(painter, width() / 2 + shift, height() / 2 - 50 + 50 * std::cos(angle+0.4), 30, Qt::green);
    QFont font("Courier New", 24);
    painter.setFont(font);
    painter.translate(0, height());
    painter.rotate(270);
    painter.drawText(0, 0, height(), width(), Qt::TextWordWrap, "Графические примитивы в библиотеке QT");

}

void SnowmanWidget::drawSnowman(QPainter &painter, int x, int y, int radius, QColor color) {
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(color);
    painter.drawEllipse(x - radius, y - radius, 2 * radius, 2 * radius);

}
