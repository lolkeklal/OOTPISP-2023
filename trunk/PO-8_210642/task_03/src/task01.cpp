#include "task01.h"

Task01Window::Task01Window(QWidget *parent)
    : QWidget(parent)
{
    lineEdit1 = new QLineEdit(this);
    lineEdit2 = new QLineEdit(this);
    lineEdit3 = new QLineEdit(this);
    resultLabel = new QLabel("Result: ", this);

    QLabel *label1 = new QLabel("Enter the first number:", this);
    QLabel *label2 = new QLabel("Enter the second number:", this);
    QLabel *label3 = new QLabel("Enter the third number:", this);

    QPushButton *calculateButton = new QPushButton("Calculate", this);
    connect(calculateButton, &QPushButton::clicked, this, &Task01Window::calculateResult);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label1);
    layout->addWidget(lineEdit1);
    layout->addWidget(label2);
    layout->addWidget(lineEdit2);
    layout->addWidget(label3);
    layout->addWidget(lineEdit3);
    layout->addWidget(calculateButton);
    layout->addWidget(resultLabel);

    setLayout(layout);
}

Task01Window::~Task01Window()
{
}

void Task01Window::calculateResult()
{
    // Получаем введенные числа
    double num1 = lineEdit1->text().toDouble();
    double num2 = lineEdit2->text().toDouble();
    double num3 = lineEdit3->text().toDouble();

    // Находим наименьшее из трех чисел
    double minNum = qMin(num1, qMin(num2, num3));

    // Вычисляем сумму двух других чисел
    double sum = (num1 + num2 + num3) - minNum;

    // Выводим результат
    resultLabel->setText("Result: " + QString::number(sum));
}
