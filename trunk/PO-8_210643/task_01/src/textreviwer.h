#ifndef TEXTREVIWER_H
#define TEXTREVIWER_H

#include <QMainWindow>
#include "QPushButton"
#include "QPlainTextEdit"
#include "QFormLayout"
#include "QFileDialog"
#include "QFile"
#include "QByteArray"

namespace Ui {
class TextReviwer;
}

class TextReviwer : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextReviwer(QWidget *parent = nullptr);
    ~TextReviwer();

private:
    Ui::TextReviwer *ui;
    QPlainTextEdit* txtEdit;

public slots:
    void textreviwer();
};

#endif
