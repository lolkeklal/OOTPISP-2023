#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("lab4");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    model = new QStandardItemModel(3, 3, this);

    ui->matrix->setModel(model);
    ui->matrix->horizontalHeader()->hide();
    ui->matrix->verticalHeader()->hide();
    ui->matrix->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->matrix->setDisabled(true);


    ui->matrix->setColumnWidth(0, 50);
    ui->matrix->setColumnWidth(1, 50);
    ui->matrix->setColumnWidth(2, 50);

    this->regenerateMatrix();

    connect(ui->actionFirstStep, SIGNAL(triggered()), this, SLOT(on_pushButton_1_clicked()));
    connect(ui->actionSecondStep, SIGNAL(triggered()), this, SLOT(on_pushButton_2_clicked()));
    connect(ui->actionThirdStep, SIGNAL(triggered()), this, SLOT(on_pushButton_3_clicked()));
    connect(ui->actionRegenerateMatrix, SIGNAL(triggered()), this, SLOT(on_pushButton_4_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    this->regenerateMatrix();
    ui->label->setText(QString("Positive part = "));
    ui->label_2->setText(QString("Negative part = "));
    ui->label_3->setText(QString("Determinate = "));
}

void MainWindow::regenerateMatrix(){
    QModelIndex index;
    srand(QTime::currentTime().msec());
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = rand() % 10;
            index = model->index(i, j);
            model->setData(index, matrix[i][j]);
            model->item(i, j)->setBackground(QColor("white"));
        }
    }
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
}

void MainWindow::on_pushButton_1_clicked()
{
    this->positivePart = matrix[0][0] * matrix[1][1] * matrix[2][2] +
                         matrix[0][1] * matrix[1][2] * matrix[2][0] +
                         matrix[1][0] * matrix[2][1] * matrix[0][2];
    ui->label->setText(QString("Positive part = %1 * %2 * %3 + %4 * %5 * %6 + %7 * %8 * %9 = %10")
                           .arg(matrix[0][0]).arg(matrix[1][1]).arg(matrix[2][2])
                           .arg(matrix[0][1]).arg(matrix[1][2]).arg(matrix[2][0])
                           .arg(matrix[1][0]).arg(matrix[2][1]).arg(matrix[0][2])
                           .arg(this->positivePart));
    ui->pushButton_2->setDisabled(false);

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; ++j) {
            model->item(i, j)->setBackground(QColor("white"));
        }
    }

    model->item(0, 0)->setBackground(QColor(0, 0, 255, 100));
    model->item(1, 1)->setBackground(QColor(0, 0, 255, 100));
    model->item(2, 2)->setBackground(QColor(0, 0, 255, 100));
    model->item(0, 1)->setBackground(QColor(255, 0, 0, 100));
    model->item(1, 2)->setBackground(QColor(255, 0, 0, 100));
    model->item(2, 0)->setBackground(QColor(255, 0, 0, 100));
    model->item(1, 0)->setBackground(QColor(255, 255, 0, 100));
    model->item(2, 1)->setBackground(QColor(255, 255, 0, 100));
    model->item(0, 2)->setBackground(QColor(255, 255, 0, 100));
}


void MainWindow::on_pushButton_2_clicked()
{
    this->negativePart = matrix[0][2] * matrix[1][1] * matrix[2][0] +
                         matrix[0][1] * matrix[1][0] * matrix[2][2] +
                         matrix[0][0] * matrix[1][2] * matrix[2][1];
    ui->label_2->setText(QString("Negative part = %1 * %2 * %3 + %4 * %5 * %6 + %7 * %8 * %9 = %10")
                             .arg(matrix[0][2]).arg(matrix[1][1]).arg(matrix[2][0])
                             .arg(matrix[0][1]).arg(matrix[1][0]).arg(matrix[2][2])
                             .arg(matrix[0][0]).arg(matrix[1][2]).arg(matrix[2][1])
                             .arg(this->negativePart));
    ui->pushButton_3->setDisabled(false);

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; ++j) {
            model->item(i, j)->setBackground(QColor("white"));
        }
    }

    model->item(0, 2)->setBackground(QColor(0, 0, 255, 100));
    model->item(1, 1)->setBackground(QColor(0, 0, 255, 100));
    model->item(2, 0)->setBackground(QColor(0, 0, 255, 100));
    model->item(0, 1)->setBackground(QColor(255, 0, 0, 100));
    model->item(1, 0)->setBackground(QColor(255, 0, 0, 100));
    model->item(2, 2)->setBackground(QColor(255, 0, 0, 100));
    model->item(0, 0)->setBackground(QColor(255, 255, 0, 100));
    model->item(1, 2)->setBackground(QColor(255, 255, 0, 100));
    model->item(2, 1)->setBackground(QColor(255, 255, 0, 100));
}


void MainWindow::on_pushButton_3_clicked()
{
    this->determinate = this->positivePart - this->negativePart;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; ++j) {
            model->item(i, j)->setBackground(QColor("white"));
        }
    }
    ui->label_3->setText(QString("Determinate = %1 - %2 = %3").
                         arg(this->positivePart).arg(this->negativePart).arg(this->determinate));
}

