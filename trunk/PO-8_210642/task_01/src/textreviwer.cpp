#include "textreviwer.h"
#include "ui_textreviwer.h"

TextReviwer::TextReviwer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextReviwer)
{
    ui->setupUi(this);

    textEdit_210642 = new QTextEdit(this);
    openButton_210642 = new QPushButton("Open File", this);
    gridLayout_210642 = new QGridLayout;

    gridLayout_210642->addWidget(textEdit_210642, 0, 0, 1, 2);
    gridLayout_210642->addWidget(openButton_210642, 1, 0, 1, 2);
    ui->centralwidget->setLayout(gridLayout_210642);

    connect(openButton_210642, &QPushButton::clicked, this, &TextReviwer::openFile_210642);
}

TextReviwer::~TextReviwer()
{
    delete ui;
}

void TextReviwer::openFile_210642(){
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");

    if (!filePath.isEmpty())
    {
        QFile file(filePath);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            textEdit_210642->setPlainText(in.readAll());
            file.close();
        }
        else
        {
            QMessageBox::critical(this, "Error", "Could not open the file.");
        }
    }
}
