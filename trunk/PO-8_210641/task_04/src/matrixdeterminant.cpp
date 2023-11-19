#include "matrixdeterminant.h"
#include "ui_matrixdeterminant.h"

MatrixDeterminant::MatrixDeterminant(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MatrixDeterminant)
{
    ui->setupUi(this);

    matrixTable = new QTableWidget(3, 3);

    step1Button = new QPushButton("First step");
    step2Button = new QPushButton("Second step");
    step3Button = new QPushButton("Third step");
    step4Button = new QPushButton("Fourth step");
    generateMatrixButton = new QPushButton("Generate a new matrix");

    resultLabel = new QLabel("Result: ");

    QGridLayout *layout = new QGridLayout();

    layout->addWidget(matrixTable, 0, 0, 4, 4);
    layout->addWidget(step1Button, 0, 4, Qt::AlignTop);
    layout->addWidget(step2Button, 1, 4, Qt::AlignTop);
    layout->addWidget(step3Button, 2, 4, Qt::AlignTop);
    layout->addWidget(step4Button, 3, 4, Qt::AlignTop);
    layout->addWidget(generateMatrixButton, 5, 0, 1, 4, Qt::AlignTop);
    layout->addWidget(resultLabel, 6, 0, 1, 4);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(layout);

    setCentralWidget(centralWidget);
    resize(450, 300);

    generateMatrix();

    connect(step1Button, &QPushButton::clicked, this, &MatrixDeterminant::step1);
    connect(step2Button, &QPushButton::clicked, this, &MatrixDeterminant::step2);
    connect(step3Button, &QPushButton::clicked, this, &MatrixDeterminant::step3);
    connect(step4Button, &QPushButton::clicked, this, &MatrixDeterminant::step4);
    connect(generateMatrixButton, &QPushButton::clicked, this, &MatrixDeterminant::generateMatrixAndReset);
}

MatrixDeterminant::~MatrixDeterminant()
{
    delete ui;
}

void MatrixDeterminant::generateMatrix()
{
    srand(QTime::currentTime().msec());

    matrixTable->clearSelection();
    matrixTable->setMaximumSize(318, 125);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int randomNumber = rand() % 10;
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(randomNumber));
            matrixTable->setItem(i, j, item);
            item->setBackground(QColor("white"));
        }
    }

    matrixTable->viewport()->update();
    resultLabel->setText("Result: ");
}

void MatrixDeterminant::highlightElements(int row1, int col1, int row2, int col2, int row3, int col3, QColor color)
{
    matrixTable->item(row1, col1)->setBackground(color);
    matrixTable->item(row2, col2)->setBackground(color);
    matrixTable->item(row3, col3)->setBackground(color);
}

void MatrixDeterminant::resetHighlight()
{
    matrixTable->clearSelection();
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            matrixTable->item(row, col)->setBackground(QColor("white"));
        }
    }
}

void MatrixDeterminant::calculateDeterminant()
{
    int a = matrixTable->item(0, 0)->text().toInt();
    int b = matrixTable->item(0, 1)->text().toInt();
    int c = matrixTable->item(0, 2)->text().toInt();
    int d = matrixTable->item(1, 0)->text().toInt();
    int e = matrixTable->item(1, 1)->text().toInt();
    int f = matrixTable->item(1, 2)->text().toInt();
    int g = matrixTable->item(2, 0)->text().toInt();
    int h = matrixTable->item(2, 1)->text().toInt();
    int i = matrixTable->item(2, 2)->text().toInt();

    int determinant = a * e * i + b * f * g + c * d * h -
        g * e * c - h * f * a - i * d * b;

    resultLabel->setText("Result: " + QString::number(determinant));
}

void MatrixDeterminant::step1()
{
    resetHighlight();
    highlightElements(0, 0, 1, 1, 2, 2, QColor(173, 216, 230));

    int a = matrixTable->item(0, 0)->text().toInt();
    int b = matrixTable->item(1, 1)->text().toInt();
    int c = matrixTable->item(2, 2)->text().toInt();

    resultLabel->setText("Result: " + QString::number(a * b * c));
}

void MatrixDeterminant::step2()
{
    resetHighlight();
    highlightElements(0, 2, 1, 0, 2, 1, QColor(144, 238, 144));

    int a = matrixTable->item(0, 2)->text().toInt();
    int b = matrixTable->item(1, 0)->text().toInt();
    int c = matrixTable->item(2, 1)->text().toInt();

    resultLabel->setText("Result: " + QString::number(a * b * c));
}

void MatrixDeterminant::step3()
{
    resetHighlight();
    highlightElements(0, 1, 1, 2, 2, 0, QColor(255, 182, 193));

    int a = matrixTable->item(0, 1)->text().toInt();
    int b = matrixTable->item(1, 2)->text().toInt();
    int c = matrixTable->item(2, 0)->text().toInt();

    resultLabel->setText("Result: " + QString::number(a * b * c));
}

void MatrixDeterminant::step4()
{
    resetHighlight();

    QColor color1 = QColor(173, 216, 230);
    QColor color2 = QColor(144, 238, 144);
    QColor color3 = QColor(255, 182, 193);

    highlightElements(0, 0, 1, 1, 2, 2, color1);
    highlightElements(0, 2, 1, 0, 2, 1, color2);
    highlightElements(0, 1, 1, 2, 2, 0, color3);

    calculateDeterminant();
    highlightColors.clear();
}
void MatrixDeterminant::generateMatrixAndReset()
{
    generateMatrix();
    resetHighlight();
    resultLabel->setText("Result: ");
}