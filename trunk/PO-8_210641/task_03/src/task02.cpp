#include "task02.h"

Task02Window::Task02Window(QWidget* parent)
    : QWidget(parent)
{
    inputLineEdit = new QLineEdit(this);
    outputLabel = new QLabel("Output: ", this);

    arrayButton = new QPushButton("Process Array", this);
    matrixButton = new QPushButton("Process Matrix", this);

    connect(arrayButton, &QPushButton::clicked, this, &Task02Window::processArray);
    connect(matrixButton, &QPushButton::clicked, this, &Task02Window::processMatrix);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("Enter integer array 10 elements):", this));
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

    QList<int> intList;
    for (const QString& str : stringList)
    {
        bool ok;
        int num = str.toInt(&ok);
        if (ok)
            intList.append(num);
    }

    QString result1 = "<b>Result for Array:</b><br>";

    for (int i = 0; i < intList.size(); i += 2)
    {
        result1 += QString("<span style='color: blue;'>%1</span> ").arg(intList[i]);
    }

    result1 += "<br>";

    for (int i = 1; i < intList.size(); i += 2)
    {
        result1 += QString("<span style='color: red;'>%1</span> ").arg(intList[i]);
    }

    displayResult(result1);
}

void Task02Window::processMatrix()
{
    int rows = QInputDialog::getInt(this, "Enter Rows", "Rows:", 3, 1, 100, 1);
    int cols = QInputDialog::getInt(this, "Enter Columns", "Columns:", 3, 1, 100, 1);

    QVector<QVector<int>> matrix = getMatrixFromUser(rows, cols);

    QStringList options;
    options << "Even Columns" << "Odd Columns";

    bool ok;
    QString choice = QInputDialog::getItem(this, "Choose Column Type", "Select Column Type:", options, 0, false, &ok);

    if (!ok)
        return;

    int sum = 0;
    for (int j = (choice == "Even Columns" ? 0 : 1); j < cols; j += 2)
    {
        for (int i = 0; i < rows; ++i)
        {
            sum += matrix[i][j];
        }
    }

    displayMatrix(matrix, choice == "Even Columns");
    displayResult(QString("Result for Matrix: Sum of %1: %2").arg(choice).arg(sum));
}

void Task02Window::displayMatrix(const QVector<QVector<int>>& matrix, bool highlightEven)
{
    QString matrixString = "<b>Matrix:</b><br>";

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            QString colorStyle = highlightEven ? "color: blue;" : "color: red;";
            matrixString += QString("<span style='%1'>%2</span> ").arg(colorStyle, QString::number(matrix[i][j]));
        }
        matrixString += "<br>";
    }

    outputLabel->setText(matrixString);
}

void Task02Window::displayResult(const QString& result)
{
    outputLabel->setText(result);
}


QVector<QVector<int>> Task02Window::getMatrixFromUser(int rows, int cols)
{
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

    return matrix;
}
