#include "textbox.h"
#include "ui_textbox.h"

TextBox::TextBox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextBox)
{
    ui->setupUi(this);

    te = new QTextEdit("file text", this);
    but = new QPushButton("open file", this);
    layout = new QGridLayout;

    layout->addWidget(te, 0, 0, 3, 3);
    layout->addWidget(but, 3, 1);

    ui->centralwidget->setLayout(layout);
}

TextBox::~TextBox()
{
    delete ui;
}

void TextBox::openFile(){
    QString fileName;
    fileName=QFileDialog::getOpenFileName();
    QFile file(fileName);
    QByteArray text;
    if (!file.open(QIODevice::ReadOnly))
        return;
    text = file.readAll();
    te->setText(QString(text));
}
