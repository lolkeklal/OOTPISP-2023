#include "task01.h"
#include "ui_task01.h"
#include <QGridLayout>
#include <string>
#include <cstdlib>
#include <numeric>

task01::task01(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::task01)
{
    ui->setupUi(this);

    edit1 = new QLineEdit();
    edit2 = new QLineEdit();
    edit3 = new QLineEdit();

    compareButton = new QPushButton("Compare");

    resultLabel = new QLabel("Result: ");

    connect(compareButton, &QPushButton::clicked, this, &task01::compareValues);

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(edit1, 0, 0);
    layout->addWidget(edit2, 0, 1);
    layout->addWidget(edit3, 0, 2);
    layout->addWidget(compareButton, 1, 1);
    layout->addWidget(resultLabel, 2, 1);

    ui->centralwidget->setLayout(layout);

}

task01::~task01()
{
    delete ui;
}

void task01::compareValues() {
    QVector<float> v;
    v.push_back(edit1->text().toFloat());
    v.push_back(edit2->text().toFloat());
    v.push_back(edit3->text().toFloat());

    sortFromMinToMax(v, 0, 2);
    float result = abs(v[0] - v[1]);

    resultLabel->setText("Result: " + QString::number(result));
}

void task01::sortFromMinToMax(QVector<float>& Arr, int first, int last)
{
    int i = first;
    int j = last;
    int x = Arr[std::midpoint(first, last)];
    do {
        while (Arr[i] < x) i++;
        while (Arr[j] > x) j--;
        if (i <= j) {
            if (Arr[i] > Arr[j]) std::swap(Arr[i], Arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i < last) sortFromMinToMax(Arr, i, last);
    if (first < j) sortFromMinToMax(Arr, first, j);
}
