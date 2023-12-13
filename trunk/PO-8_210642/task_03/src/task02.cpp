#include "task02.h"

Task02Window::Task02Window(QWidget *parent)
    : QWidget(parent)
{
    inputLineEdit = new QLineEdit(this);
    outputLabel = new QLabel("Output: ", this);

    arrayButton = new QPushButton("Process Array", this);
    matrixButton = new QPushButton("Process Matrix", this);

    connect(arrayButton, &QPushButton::clicked, this, &Task02Window::processArray);
    connect(matrixButton, &QPushButton::clicked, this, &Task02Window::processMatrix);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("Enter integer array elements A[1] < A[i] < A[10] (separated by space, 10 elements):", this));
    mainLayout->addWidget(inputLineEdit);
    mainLayout->addWidget(arrayButton);
    mainLayout->addWidget(matrixButton);
    mainLayout->addWidget(outputLabel);

    setLayout(mainLayout);
}

Task02Window::~Task02Window()
{
}

void Task02Window::processArray()
{
    QString inputText = inputLineEdit->text();
    QStringList stringList = inputText.split(' ');

    // Преобразование строк в целые числа
    QList<int> intList;
    for (const QString &str : stringList)
    {
        bool ok;
        int num = str.toInt(&ok);
        if (ok)
            intList.append(num);
    }

    // Задание 1: Найти номер первого элемента, удовлетворяющего двойному неравенству
    int result1 = 0;
    for (int i = 0; i < intList.size(); ++i)
    {
        if (intList[0] < intList[i] && intList[i] < intList[9])
        {
            result1 = i + 1;
            break;
        }
    }

    outputLabel->setText("Result for Array: " + QString::number(result1));
}

void Task02Window::processMatrix()
{
    int rows = QInputDialog::getInt(this, "Enter Rows", "Rows:", 3, 1, 100, 1);
    int cols = QInputDialog::getInt(this, "Enter Columns", "Columns:", 3, 1, 100, 1);

    // Создание и заполнение матрицы значениями, заданными пользователем
    QVector<QVector<int>> matrix(rows, QVector<int>(cols));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = QInputDialog::getInt(this, QString("Enter Matrix Element (%1, %2)").arg(i + 1).arg(j + 1),
                                                QString("Matrix Element (%1, %2):").arg(i + 1).arg(j + 1),
                                                0, -1000, 1000, 1);
        }
    }

    // Задание 2: Найти минимальное и максимальное значение в каждой строке
    QString result2 = "Result for Matrix: \n";
    for (int i = 0; i < rows; ++i)
    {
        int minVal = matrix[i][0];
        int maxVal = matrix[i][0];

        for (int j = 1; j < cols; ++j)
        {
            if (matrix[i][j] < minVal)
                minVal = matrix[i][j];

            if (matrix[i][j] > maxVal)
                maxVal = matrix[i][j];
        }

        result2 += QString("Row %1: Min=%2, Max=%3\n").arg(i + 1).arg(minVal).arg(maxVal);
    }

    outputLabel->setText(result2);
}
