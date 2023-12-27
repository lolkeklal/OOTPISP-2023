// task06.h
#ifndef TASK06_H
#define TASK06_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

class Task06Window : public QWidget
{
    Q_OBJECT

public:
    explicit Task06Window(QWidget *parent = nullptr);
    ~Task06Window();

private slots:
    void processFiles();
    void displayFileContent(QTextEdit *textEdit, const QString &filePath);

private:
    QTextEdit *file1TextEdit;
    QTextEdit *file2TextEdit;
    QPushButton *processButton;

    // Helper function to swap contents of two files
    void swapFileContents(const QString &filePath1, const QString &filePath2);
};

#endif // TASK06_H
