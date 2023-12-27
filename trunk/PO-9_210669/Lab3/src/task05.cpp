#include "task05.h"
#include "ui_task05.h"
#include <QGridLayout>
#include <QLabel>
#include <QList>
#include <QSet>

task05::task05(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::task05)
{
    ui->setupUi(this);

    QLabel* label1 = new QLabel("fisher 1");
    QLabel* label2 = new QLabel("fisher 2");
    QLabel* label3 = new QLabel("fisher 3");
    QLabel* label4 = new QLabel("all fishes");
    QLabel* label5 = new QLabel("equal fishes");
    QLabel* label6 = new QLabel("not caught fishes");

    firstFisher = new QTableWidget();
    secondFisher = new QTableWidget();
    thirdFisher = new QTableWidget();
    fishes = new QTableWidget();
    notCaughtFishes = new QTableWidget();
    equalFishes = new QTableWidget();

    generateButton = new QPushButton("generate");

    connect(generateButton, &QPushButton::clicked, this, &task05::generateTables);

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(label1, 0, 0);
    layout->addWidget(label2, 0, 1);
    layout->addWidget(label3, 0, 2);
    layout->addWidget(firstFisher, 1, 0);
    layout->addWidget(secondFisher, 1, 1);
    layout->addWidget(thirdFisher, 1, 2);
    layout->addWidget(label4, 2, 0);
    layout->addWidget(label5, 2, 1);
    layout->addWidget(label6, 2, 2);
    layout->addWidget(fishes, 3, 0);
    layout->addWidget(equalFishes, 3, 1);
    layout->addWidget(notCaughtFishes, 3, 2);
    layout->addWidget(generateButton, 4, 1);

    ui->centralwidget->setLayout(layout);
}

task05::~task05()
{
    delete ui;
}

void task05::generateTables() {

    fv.clear();
    sv.clear();
    tv.clear();
    allFishesSize = v.size();
    fishes->setColumnCount(1);
    fishes->setRowCount(allFishesSize);
    for (int i = 0; i < allFishesSize; i++) {
        QTableWidgetItem* Item = new QTableWidgetItem(v[i]);
        this->fishes->setItem(i, 0, Item);
    }

    size1 = rand() % 5 + 1;
    firstFisher->setColumnCount(1);
    firstFisher->setRowCount(size1);
    for (int i = 0; i < size1; i++) {
        int index = rand() % allFishesSize;
        fv.push_back(v[index]);
        QTableWidgetItem* Item = new QTableWidgetItem(v[index]);
        this->firstFisher->setItem(i, 0, Item);
    }

    size2 = rand() % 5 + 1;
    secondFisher->setColumnCount(1);
    secondFisher->setRowCount(size2);
    for (int i = 0; i < size2; i++) {
        int index = rand() % allFishesSize;
        sv.push_back(v[index]);
        QTableWidgetItem* Item = new QTableWidgetItem(v[index]);
        this->secondFisher->setItem(i, 0, Item);
    }

    size3 = rand() % 5 + 1;
    thirdFisher->setColumnCount(1);
    thirdFisher->setRowCount(size3);
    for (int i = 0; i < size3; i++) {
        int index = rand() % allFishesSize;
        tv.push_back(v[index]);
        QTableWidgetItem* Item = new QTableWidgetItem(v[index]);
        this->thirdFisher->setItem(i, 0, Item);
    }



    QVector<QString> tempV;
    QVector<QString> resultV;

    std::sort(fv.begin(), fv.end());
    std::sort(sv.begin(), sv.end());


    std::set_intersection(fv.begin(), fv.end(), sv.begin(), sv.end(), std::back_inserter(tempV));

    std::sort(tv.begin(), tv.end());
    std::sort(tempV.begin(), tempV.end());

    std::set_intersection(tv.begin(), tv.end(), tempV.begin(), tempV.end(), std::back_inserter(resultV));

    equalFishes->setColumnCount(1);
    equalFishes->setRowCount(resultV.size());

    for (int i = 0; i < resultV.size(); i++) {
        QTableWidgetItem* Item = new QTableWidgetItem(resultV[i]);
        this->equalFishes->setItem(i, 0, Item);
    }


    tempV.clear();
    tempV += fv + sv + tv;
    std::sort(tempV.begin(), tempV.end());
    QVector<QString>::iterator it;
    it = std::unique(tempV.begin(), tempV.end());
    tempV.resize(std::distance(tempV.begin(), it));

    resultV.clear();

    resultV = v;

    for (int i = 0; i < tempV.size(); i++) {
        QVector<QString>::iterator it = std::find(resultV.begin(), resultV.end(), tempV[i]);
        resultV.erase(it);
    }

    notCaughtFishes->setColumnCount(1);
    notCaughtFishes->setRowCount(resultV.size());

    for (int i = 0; i < resultV.size(); i++) {
        QTableWidgetItem* Item = new QTableWidgetItem(resultV[i]);
        this->notCaughtFishes->setItem(i, 0, Item);
    }

}
