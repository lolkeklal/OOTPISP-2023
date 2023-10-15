#include "fileviewer.h"
#include "ui_fileviewer.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>

FileViewer::FileViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileViewer)
{
    ui->setupUi(this);

    QVBoxLayout* VBLayout = new QVBoxLayout;
    ui->centralwidget->setLayout(VBLayout);

    text = new QPlainTextEdit;
    text->setReadOnly(true);
    QPushButton *button = new QPushButton("ChooseFile");

    VBLayout->addWidget(text);
    VBLayout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &FileViewer::openFile);
}

FileViewer::~FileViewer()
{
    delete ui;
}

void FileViewer::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        qDebug() << "Error";
    text->setPlainText(QString(file.readAll()));
}
