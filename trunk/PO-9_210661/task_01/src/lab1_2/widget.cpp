#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    textEdit = new QTextEdit(this);
    button = new QPushButton("Открыть файл", this);

    connect(button, &QPushButton::clicked, this, &Widget::openFile);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);
    layout->addWidget(button);

    setLayout(layout);
}

void Widget::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Текстовые файлы (*.txt)");

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString fileContent = in.readAll();
        textEdit->setPlainText(fileContent);
        file.close();
    }
}

Widget::~Widget()
{
    delete ui;
}
