#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QFont>
#include <QFontMetrics>
#include <cmath>
////
class LabWorkWidget : public QWidget {
public:
    explicit LabWorkWidget(QWidget *parent = nullptr) : QWidget(parent), time(0) {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &LabWorkWidget::animate);
        timer->start(16); // 60 FPS
    }

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);

        // Устанавливаем черный фон
        painter.setBrush(QColor(Qt::black));
        painter.drawRect(rect());

        // Выводим наименование лабораторной работы по центру
        painter.setPen(QColor(Qt::white)); // Устанавливаем цвет текста
        painter.setFont(QFont("Arial", 10, QFont::Light)); // Используем Light вместо Normal

        QString text = "Лабораторная работа";
        QFontMetrics fm(painter.font());
        int textWidth = fm.horizontalAdvance(text);
        int textHeight = fm.height();

        painter.rotate(-90);
        painter.drawText(-height() / 2 + textHeight / 2, 10 + textWidth / 2, text);

        // Рисуем цветную фигуру
        painter.resetTransform();
        drawColorfulFigure(&painter);
    }

private:
    void drawColorfulFigure(QPainter *painter) {
        // Определяем цвета для окружностей
        QColor colors[] = {Qt::red, Qt::green, Qt::blue};

        // Рисуем 3 окружности по горизонтали с движением вправо
        int radius = 30;
        for (int i = 0; i < 3; ++i) {
            painter->setBrush(colors[i]);
            qreal x = fmod(50 + i * 70 + 100 * time, width()); // Используем остаток от деления на ширину окна
            qreal y = height() / 2 - radius + 50 * qSin(2 * M_PI * time + i * M_PI / 2); // Движение по синусоидальной траектории
            painter->drawEllipse(x - radius, y, 2 * radius, 2 * radius);
        }
    }

    void animate() {
        time += 0.05;
        update(); // Перерисовываем окно
    }

private:
    qreal time;
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    LabWorkWidget labWorkWidget;
    labWorkWidget.setWindowTitle("Lab Work");
    labWorkWidget.resize(800, 600);
    labWorkWidget.show();

    return a.exec();
}
