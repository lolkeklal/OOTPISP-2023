// task06.cpp
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
    // Dialog for selecting files
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Select Files", QDir::homePath(), "Text Files (*.txt)");

    // If two files are selected, swap their contents
    if (fileNames.size() == 2)
    {
        // Display initial file content
        displayFileContent(file1TextEdit, fileNames[0]);
        displayFileContent(file2TextEdit, fileNames[1]);

        // Save the initial content
        QString initialFile1Content = file1TextEdit->toPlainText();
        QString initialFile2Content = file2TextEdit->toPlainText();

        // Swap file contents
        swapFileContents(fileNames[0], fileNames[1]);

        // Display updated file content
        displayFileContent(file1TextEdit, fileNames[0]);
        displayFileContent(file2TextEdit, fileNames[1]);

        // Show results in the text fields
        file1TextEdit->setPlainText(initialFile2Content);
        file2TextEdit->setPlainText(initialFile1Content);

        qDebug() << "Files processed successfully.";
    }
    else
    {
        // Show an error message if files are not selected
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

        // Read contents of the files
        QString file1Content = QTextStream(&file1).readAll();
        QString file2Content = QTextStream(&file2).readAll();

        // Clear the files
        file1.resize(0);
        file2.resize(0);

        // Swap contents
        QTextStream(&file1) << file2Content;
        QTextStream(&file2) << file1Content;

        // Close files
        file1.close();
        file2.close();
    }
    else
    {
        // Show an error message if files cannot be opened
        QMessageBox::critical(this, "Error", "Error opening files.");
    }
}

void Task06Window::displayFileContent(QTextEdit *textEdit, const QString &filePath)
{
    // Display the content of the file in the given QTextEdit
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        textEdit->setPlainText(stream.readAll());
        file.close();
    }
    else
    {
        // Show an error message if the file cannot be opened
        QMessageBox::critical(this, "Error", "Error opening file: " + filePath);
    }
}
