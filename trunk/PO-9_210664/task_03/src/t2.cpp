#include "t2.h"
#include "ui_t2.h"

#include <algorithm>

t2::t2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t2)
{
    ui->setupUi(this);
}

t2::~t2()
{
    delete ui;
}

// tab1
void t2::on_lineEdit_textChanged(const QString &arg1)
{
    QList<int> odd;
    QList<int> even;
    int max_i = 0;

    bool is_alpha = false;
    int num;
    int i = 0;
    for (QString str : arg1.split(" ")) {
        num = str.toInt(&is_alpha);
        if (is_alpha) {
            if (num % 2 == 0) {
                even.push_back(num);
            }
            else {
                odd.push_back(num);
            }
            i++;
        }
    }

    if (i == 0) {
        this->ui->label->setText("No numbers detected");
        return;
    }

    QString label;

    for (int num : even) {
        label += " " + QString::number(num);
    }
    for (int num : odd) {
        label += " " + QString::number(num);
    }

    this->ui->label->setText(label);
}

//tab2

void t2::on_spinBoxN_valueChanged(int arg1)
{
    this->ui->tableWidget->setRowCount(arg1);
}

void t2::on_spinBoxM_valueChanged(int arg1)
{
    this->ui->tableWidget->setColumnCount(arg1);
}

// on sort button click
void t2::on_pushButton_clicked()
{
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QList<int> rowList;

        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            int value = item ? item->text().toInt() : 0;
            rowList.append(value);
        }

        std::sort(rowList.begin(), rowList.end());

        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(rowList.at(col)));
            ui->tableWidget->setItem(row, col, item);
        }
    }

}
