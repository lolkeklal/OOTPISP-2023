// t1.cpp
#include "t1.h"
#include "ui_t1.h"

t1::t1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t1)
{
    ui->setupUi(this);
    setWindowTitle("t1");

    // Создаем QLineEdit для ввода переменных X, Y, Z
    lineEditX = new QLineEdit(this);
    lineEditY = new QLineEdit(this);
    lineEditZ = new QLineEdit(this);

    // Создаем кнопку для выполнения сортировки
    sortButton = new QPushButton("Sort", this);

    // Размещаем элементы на форме
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(lineEditX);
    layout->addWidget(lineEditY);
    layout->addWidget(lineEditZ);
    layout->addWidget(sortButton);

    // Подключаем сигнал к слоту для выполнения сортировки
    connect(sortButton, &QPushButton::clicked, this, &t1::sortVariables);
}

t1::~t1()
{
    delete ui;
}

void t1::sortVariables()
{
    // Получаем значения переменных X, Y, Z из lineEdit
    int x = lineEditX->text().toInt();
    int y = lineEditY->text().toInt();
    int z = lineEditZ->text().toInt();

    // Сортируем переменные по убыванию
    QVector<int> variables = {x, y, z};
    std::sort(variables.begin(), variables.end(), std::greater<int>());

    // Устанавливаем отсортированные значения обратно в lineEdit
    lineEditX->setText(QString::number(variables[0]));
    lineEditY->setText(QString::number(variables[1]));
    lineEditZ->setText(QString::number(variables[2]));
}
