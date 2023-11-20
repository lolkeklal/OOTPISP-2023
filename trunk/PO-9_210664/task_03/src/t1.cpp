#include "t1.h"
#include "./ui_t1.h"

#include <QVector>

t1::t1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::t1)
{
    ui->setupUi(this);
}

t1::~t1()
{
    delete ui;
}

void t1::on_lineEdit_textChanged(const QString &arg1)
{
    QVector<int> vec;
    int max_i = 0;

    bool is_alpha = false;
    int num;
    int i = 0;
    for (QString str : arg1.split(" ")) {
        num = str.toInt(&is_alpha);
        if (is_alpha) {
            vec.push_back(num);
            i++;
            if (vec[max_i] < num) {
                max_i = i-1;
            }
        }
        if (i == 3) {
            break;
        }
    }

    if (i < 3) {
        QString t("Detected %1 numbers");
        this->ui->label->setText(t.arg(i));
        return;
    }

    int maxIndex = vec.indexOf(qMax(qMax(vec[0], vec[1]), vec[2]));
    int diff = (vec[(maxIndex + 1) % 3] - vec[(maxIndex + 2) % 3]);

    vec.replace(maxIndex, diff);

    this->ui->label->setText(QString::number(vec[0]) + " "
                            + QString::number(vec[1]) + " "
                            + QString::number(vec[2]));
}
