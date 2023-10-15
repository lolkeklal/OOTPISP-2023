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
    QTextEdit *textEdit;
    QPushButton *openButton;
    QGridLayout *gridLayout;

public slots:
    void openFile();

private:
    Ui::TextReviwer *ui;
};

#endif // TEXTREVIWER_H
