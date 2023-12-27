// t2.cpp
#include "t2.h"
#include "ui_t2.h"
#include <QDebug>


t2::t2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t2)
{
    ui->setupUi(this);
    setWindowTitle("t2");

    // Добавим элементы в QComboBox
    ui->columnTypeComboBox->addItem("Even");
    ui->columnTypeComboBox->addItem("Odd");

    // Connect button signals to slots
    connect(ui->processArrayButton, &QPushButton::clicked, this, &t2::on_processArrayButton_clicked);
    connect(ui->processMatrixButton, &QPushButton::clicked, this, &t2::on_processMatrixButton_clicked);
}

t2::~t2()
{
    delete ui;
}

void t2::on_processArrayButton_clicked()
{
    // Получаем массив из строки ввода
    QString arrayString = ui->arrayLineEdit->text();
    QStringList arrayStringList = arrayString.split(" ", Qt::SkipEmptyParts);
    QVector<int> array;
    for (const QString& num : arrayStringList) {
        array.append(num.toInt());
    }

    // Обрабатываем массив
    processArray(array);
}

void t2::on_processMatrixButton_clicked()
{
    // Получаем матрицу из строки ввода
    QString matrixString = ui->matrixTextEdit->toPlainText();
    QStringList rowStrings = matrixString.split("\n", Qt::SkipEmptyParts);
    QVector<QVector<int>> matrix;
    for (const QString& rowString : rowStrings) {
        QStringList colStrings = rowString.split(" ", Qt::SkipEmptyParts);
        QVector<int> row;
        for (const QString& num : colStrings) {
            row.append(num.toInt());
        }
        matrix.append(row);
    }

    // Обрабатываем матрицу
    processMatrix(matrix);
}

void t2::processArray(const QVector<int>& array)
{
    // Определяем, какие элементы нужно обрабатывать (четные или нечетные)
    bool processEvenColumns = ui->columnTypeComboBox->currentIndex() == 0;

    QVector<int> processedElements;

    for (int i = 0; i < array.size(); ++i) {
        if ((i % 2 == 0 && processEvenColumns) || (i % 2 != 0 && !processEvenColumns)) {
            processedElements.append(array[i]);
        }
    }

    // Собираем текст для вывода
    QString resultText = (processEvenColumns ? "Even" : "Odd") + QString(" indices: ") + QString::number(processedElements[0]);
    for (int i = 1; i < processedElements.size(); ++i) {
        resultText += ", " + QString::number(processedElements[i]);
    }

    // Выводим результат в QPlainTextEdit
    ui->outputPlainTextEdit->clear();
    ui->outputPlainTextEdit->appendPlainText(resultText);
}


void t2::processMatrix(const QVector<QVector<int>>& matrix)
{
    // Определяем, какие столбцы нужно обрабатывать (четные или нечетные)
    bool processEvenColumns = ui->columnTypeComboBox->currentIndex() == 0;

    QVector<int> columnSums(matrix[0].size(), 0);

    for (int j = 0; j < matrix[0].size(); ++j) {
        for (int i = 0; i < matrix.size(); ++i) {
            if ((j % 2 == 0 && processEvenColumns) || (j % 2 != 0 && !processEvenColumns)) {
                columnSums[j] += matrix[i][j];
            }
        }
    }

    // Собираем текст для вывода
    QString resultText = (processEvenColumns ? "Even" : "Odd") + QString(" column sums: ") + QString::number(columnSums[0]);
    for (int i = 1; i < columnSums.size(); ++i) {
        resultText += ", " + QString::number(columnSums[i]);
    }

    // Выводим результат в QPlainTextEdit
    ui->outputPlainTextEdit->clear();
    ui->outputPlainTextEdit->appendPlainText(resultText);
}
