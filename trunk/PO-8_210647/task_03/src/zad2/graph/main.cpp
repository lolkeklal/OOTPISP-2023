#include "mainwindow.h"
#include <QApplication>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setGeometry(100, 100, 400, 300);

    int m = 3; // количество строк
    int n = 4; // количество столбцов

    std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}, {2, 3, 1, 8}, {9, 10, 11, 12}}; //1

    QVBoxLayout *layout = new QVBoxLayout(&window);
    QTableWidget *table = new QTableWidget(&window);
    table->setRowCount(m);
    table->setColumnCount(n + 1);

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(matrix[i][j]));
            table->setItem(i, j, item);
        }
        double average = static_cast<double>(sum) / n;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > average) {
                count++;
            }
        }
        QTableWidgetItem *item = new QTableWidgetItem("= " + QString::number(count));
        item->setBackground(Qt::gray);
        table->setItem(i, n, item);
    }

    layout->addWidget(table);
    window.setLayout(layout);
    window.show();

    return app.exec();
}

