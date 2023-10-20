#include "textreviwer.h"
#include "ui_textreviwer.h"

TextReviwer::TextReviwer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextReviwer)
{
    ui->setupUi(this);

    textEdit = new QTextEdit(this);
    openButton = new QPushButton("Open File", this);
    gridLayout = new QGridLayout;

    gridLayout->addWidget(textEdit, 0, 0, 1, 2);
    gridLayout->addWidget(openButton, 1, 0, 1, 2);
    ui->centralwidget->setLayout(gridLayout);

    connect(openButton, &QPushButton::clicked, this, &TextReviwer::openFile);
}

TextReviwer::~TextReviwer()
{
    delete ui;
}

void TextReviwer::openFile(){
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");

    if (!filePath.isEmpty())
    {
        QFile file(filePath);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            textEdit->setPlainText(in.readAll());
            file.close();
        }
        else
        {
            QMessageBox::critical(this, "Error", "Could not open the file.");
        }
    }
}
