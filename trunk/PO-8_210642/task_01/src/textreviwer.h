#ifndef TEXTREVIWER_H
#define TEXTREVIWER_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QByteArray>


namespace Ui {
class TextReviwer;
}

class TextReviwer : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextReviwer(QWidget *parent = nullptr);
    ~TextReviwer();
    QTextEdit *textEdit_210642;
    QPushButton *openButton_210642;
    QGridLayout *gridLayout_210642;

public slots:
    void openFile_210642();

private:
    Ui::TextReviwer *ui;
};

#endif // TEXTREVIWER_H
