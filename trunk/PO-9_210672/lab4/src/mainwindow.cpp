#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(onShowClicked()));
    table = new QTableWidget;
    table->setColumnCount(5);
    table->setRowCount(102);
    table->setItem(0, 0, new QTableWidgetItem("Десятичная"));
    table->setItem(0, 1, new QTableWidgetItem("Двоичная"));
    table->setItem(0, 2, new QTableWidgetItem("Восьмиричная"));
    table->setItem(0, 3, new QTableWidgetItem("Шестнадцатеричная"));
    table->setItem(0, 4, new QTableWidgetItem("Двоично-десятичная"));
    ui->centralwidget->layout()->addWidget(table);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QTableWidgetItem * MainWindow::createItem(QString value) {
    QTableWidgetItem *item = new QTableWidgetItem(value);
    if (value.back() == QChar('0')) {
        item->setBackground(QColor(100, 100, 150));
        this->counter++;
    }
    return item;
}

void MainWindow::onShowClicked() {
    counter = 0;
    for (int i = 1; i <= 102; i++) {
        for (int j = 0; j < 5; j++)
        table->setItem(i, j, new QTableWidgetItem);
    }
    const int min = ui->spinBox->value();
    const int max = ui->spinBox_2->value();
    for (int i = min; i <= max; i++) {
        table->setItem(i - min + 1, 0, createItem(tr("%1").arg(i)));

        table->setItem(i - min + 1, 1, createItem(tr("%1").arg(QString::number(i, 2))));

        table->setItem(i - min + 1, 2, createItem(tr("%1").arg(QString::number(i, 8))));

        table->setItem(i - min + 1, 3, createItem(tr("%1").arg(QString::number(i, 16))));

        QByteArray data = QByteArray(tr("%1").arg(i).toLocal8Bit());
        QByteArray bcd = QByteArray::fromHex(data);
        table->setItem(i - min + 1, 4, createItem(tr("%1").arg(bcd.toHex())));
    }
    ui->label->setText(tr("%1").arg(counter));
}
