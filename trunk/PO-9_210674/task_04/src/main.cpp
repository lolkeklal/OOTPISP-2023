#include "mainwindow.h"
#include <QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QGridLayout>
#include <QTime>
#include <QRandomGenerator>
#include <QHeaderView>
#include <map>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;

    QTableWidget tableWidget(3, 10);

    QPushButton updateButton("Update numbers");
    QObject::connect(&updateButton, &QPushButton::clicked, [&tableWidget]() {
        QTime time = QTime::currentTime();
        srand(static_cast<uint>(time.msec()));
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 10; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(QRandomGenerator::global()->bounded(100)));
                tableWidget.setItem(row, col, item);
            }
        }
    });
    std::map<int, Qt::SortOrder> sortOrderMap;

    QPushButton toggleButton("Toggle ASCII Sorting", &tableWidget);
    toggleButton.move(10, 10);
    bool asciiSortingEnabled = false;

    QObject::connect(&toggleButton, &QPushButton::clicked, [&tableWidget, &asciiSortingEnabled]() {
        asciiSortingEnabled = !asciiSortingEnabled;

        for (int row = 0; row < tableWidget.rowCount(); ++row) {
            for (int col = 0; col < tableWidget.columnCount(); ++col) {
                QTableWidgetItem *item = tableWidget.item(row, col);
                if (item) {
                    QString text = item->text();
                    if (asciiSortingEnabled) {
                        QString asciiText;
                        for (const QChar &ch : text) {
                            asciiText += QString::number(ch.toLatin1()) + " ";
                        }
                        item->setText(asciiText);
                    } else {
                       
                        item->setText(QString::number(text.remove(' ').toInt()));
                    }
                }
            }
        }
    });



    QObject::connect(tableWidget.horizontalHeader(), &QHeaderView::sectionClicked, [&](int logicalIndex) {
        if (tableWidget.horizontalHeader()->sortIndicatorSection() != logicalIndex) {
            sortOrderMap[logicalIndex] = Qt::AscendingOrder;
        } else {
            sortOrderMap[logicalIndex] = (sortOrderMap[logicalIndex] == Qt::AscendingOrder) ? Qt::DescendingOrder : Qt::AscendingOrder;
        }

        QList<QTableWidgetItem *> items;
        for (int i = 0; i < tableWidget.rowCount(); ++i) {
            items.append(tableWidget.takeItem(i, logicalIndex));
        }

        std::sort(items.begin(), items.end(), [&](const QTableWidgetItem *a, const QTableWidgetItem *b) {
            if (asciiSortingEnabled) {
                if (sortOrderMap[logicalIndex] == Qt::AscendingOrder) {
                    return a->text().toLatin1() < b->text().toLatin1();
                } else {
                    return a->text().toLatin1() > b->text().toLatin1();
                }
            } else {
                if (sortOrderMap[logicalIndex] == Qt::AscendingOrder) {
                    return a->text() < b->text();
                } else {
                    return a->text() > b->text();
                }
            }
        });

        for (int i = 0; i < items.size(); ++i) {
            tableWidget.setItem(i, logicalIndex, items.at(i));
        }

        tableWidget.horizontalHeader()->setSortIndicator(logicalIndex, sortOrderMap[logicalIndex]);
    });


    QGridLayout *layout = new QGridLayout;
    layout->addWidget(&tableWidget, 0, 0);
    layout->addWidget(&updateButton, 1, 0);
    layout->addWidget(&toggleButton, 2, 0);

    window.setLayout(layout);
    window.show();

    return a.exec();
}

