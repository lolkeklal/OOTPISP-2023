#include "mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QGridLayout>
#include <QLabel>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    table = new QTableWidget(10, 10, this);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    resultLabel = new QLabel(this);
    resultLabel->setAlignment(Qt::AlignCenter);

    QWidget *centralWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(centralWidget);
    layout->addWidget(table, 0, 0);
    layout->addWidget(resultLabel, 1, 0);

    setCentralWidget(centralWidget);

    connect(table, &QTableWidget::cellClicked, this, &MainWindow::handleCellClick);

    // Заполнение таблицы случайными числами
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            int value = rand() % 100; // Генерация случайного числа от 0 до 99
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(value));
            table->setItem(row, col, item);
        }
    }
}

MainWindow::~MainWindow()
{
}

void MainWindow::handleCellClick(int row, int column)
{
    QTableWidgetItem *item = table->item(row, column);
    int value = item->text().toInt();
    int index = row * 10 + column;
    int square = value * value;
    int cube = value * value * value;

    resultLabel->setText(QString("Координаты: (%1, %2)\n"
                                 "Порядковый номер: %3\n"
                                 "Квадрат: %4\n"
                                 "Куб: %5").arg(row+1).arg(column+1).arg(index+1).arg(square).arg(cube));
}
