#include "task2.h"
#include "ui_task2.h"

Task2::Task2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Task2)
{
    ui->setupUi(this);

    setWindowTitle("Task 2");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    QRegularExpression exprNums("([1-9][0-9]*)|0");
    QValidator *validatorNums = new QRegularExpressionValidator(exprNums, this);
    ui->matrix1ColsLineEdit->setValidator(validatorNums);
    ui->matrix2ColsLineEdit->setValidator(validatorNums);
    ui->matrix2RowsLineEdit->setValidator(validatorNums);
}

void Task2::showEvent(QShowEvent *event){
    ui->matrix1ColsLineEdit->clear();
    ui->matrix1->setColumnCount(0);
    ui->evenElemsLabel->setText("even =");
    ui->oddElemsLabel->setText("odd =");

    ui->matrix2ColsLineEdit->clear();
    ui->matrix2RowsLineEdit->clear();
    ui->matrix2->setColumnCount(0);
    ui->matrix2->setRowCount(0);
    ui->matrix2SumLabel->setText("sum =");

    QWidget::showEvent(event);
}

Task2::~Task2()
{
    delete ui;
}

void Task2::on_regenerateMatrix1PushButton_clicked()
{
    ui->evenElemsLabel->setText("even =");
    ui->oddElemsLabel->setText("odd =");
    int colsCount = ui->matrix1ColsLineEdit->text().toInt();
    ui->matrix1->setColumnCount(colsCount);
    for (int i = 0; i < colsCount; ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(rand() % 10));
        ui->matrix1->setItem(0, i, item);
        ui->matrix1->setColumnWidth(i, 20);
    }

    QStringList evenElems;
    QStringList oddElems;
    for (int i = 1; i < colsCount; i+=2) {
        evenElems << ui->matrix1->item(0, i)->text();
        oddElems << ui->matrix1->item(0, i - 1)->text();
    }
    if (colsCount % 2 == 1)
        oddElems << ui->matrix1->item(0, colsCount - 1)->text();
    ui->evenElemsLabel->setText(QString("even = %1").arg(evenElems.join(", ")));
    ui->oddElemsLabel->setText(QString("odd = %1").arg(oddElems.join(", ")));
}


void Task2::on_regenerateMatrix2PushButton_clicked()
{
    ui->matrix2SumLabel->setText("sum =");
    int colsCount = ui->matrix2ColsLineEdit->text().toInt();
    int rowsCount = ui->matrix2RowsLineEdit->text().toInt();
    ui->matrix2->setColumnCount(colsCount);
    ui->matrix2->setRowCount(rowsCount);
    for (int i = 0; i < rowsCount; ++i) {
        for (int j = 0; j < colsCount; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(rand() % 10));
            ui->matrix2->setItem(i, j, item);
            ui->matrix2->setColumnWidth(j, 20);
        }
        ui->matrix2->setRowHeight(i, 20);
    }
}


void Task2::on_getMatrix2SumPushButton_clicked()
{
    int colsCount = ui->matrix2ColsLineEdit->text().toInt();
    int rowsCount = ui->matrix2RowsLineEdit->text().toInt();
    bool isOddColsSum = (ui->matrix2SumTypeComboBox->currentText() == "sum of odd cols");
    int firstCol = (isOddColsSum ? 0 : 1);
    int sum = 0;
    for (int i = 0; i < rowsCount; ++i) {
        for (int j = firstCol; j < colsCount; j+=2) {
            sum += ui->matrix2->item(i, j)->text().toInt();
        }
    }
    ui->matrix2SumLabel->setText(QString("sum = %1").arg(sum));
}

