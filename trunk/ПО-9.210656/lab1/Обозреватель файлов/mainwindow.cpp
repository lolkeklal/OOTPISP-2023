#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout* VBLayout = new QVBoxLayout;
    ui->centralwidget->setLayout(VBLayout);

    text = new QPlainTextEdit;
    text->setReadOnly(true);
    QPushButton *button = new QPushButton("ChooseFile");

    VBLayout->addWidget(text);
    VBLayout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &MainWindow::openFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        qDebug() << "Error";
    text->setPlainText(QString(file.readAll()));
}
