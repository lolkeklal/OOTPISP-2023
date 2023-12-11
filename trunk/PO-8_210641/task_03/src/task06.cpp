#include "task06.h"
#include <QDebug>

Task06Window::Task06Window(QWidget *parent)
    : QWidget(parent)
{
    file1TextEdit = new QTextEdit(this);
    file2TextEdit = new QTextEdit(this);
    processButton = new QPushButton("Process Files", this);

    connect(processButton, &QPushButton::clicked, this, &Task06Window::processFiles);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *textEditLayout = new QHBoxLayout();
    textEditLayout->addWidget(file1TextEdit);
    textEditLayout->addWidget(file2TextEdit);

    mainLayout->addLayout(textEditLayout);
    mainLayout->addWidget(processButton);

    setLayout(mainLayout);
}

Task06Window::~Task06Window()
{
}

void Task06Window::processFiles()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Select Files", QDir::homePath(), "Text Files (*.txt)");

    if (fileNames.size() == 2)
    {
        displayFileContent(file1TextEdit, fileNames[0]);
        displayFileContent(file2TextEdit, fileNames[1]);

        QString initialFile1Content = file1TextEdit->toPlainText();
        QString initialFile2Content = file2TextEdit->toPlainText();

        swapFileContents(fileNames[0], fileNames[1]);

        displayFileContent(file1TextEdit, fileNames[0]);
        displayFileContent(file2TextEdit, fileNames[1]);

        file1TextEdit->setPlainText(initialFile2Content);
        file2TextEdit->setPlainText(initialFile1Content);

        qDebug() << "Files processed successfully.";
    }
    else
    {
        QMessageBox::critical(this, "Error", "Please select two text files.");
    }
}

void Task06Window::swapFileContents(const QString &filePath1, const QString &filePath2)
{
    QFile file1(filePath1);
    QFile file2(filePath2);

    if (file1.open(QIODevice::ReadWrite | QIODevice::Text) && file2.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug() << "Files opened successfully.";

        QString file1Content = QTextStream(&file1).readAll();
        QString file2Content = QTextStream(&file2).readAll();
        file1.resize(0);
        file2.resize(0);

        QTextStream(&file1) << file2Content;
        QTextStream(&file2) << file1Content;

        file1.close();
        file2.close();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Error opening files.");
    }
}

void Task06Window::displayFileContent(QTextEdit *textEdit, const QString &filePath)
{

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        textEdit->setPlainText(stream.readAll());
        file.close();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Error opening file: " + filePath);
    }
}
