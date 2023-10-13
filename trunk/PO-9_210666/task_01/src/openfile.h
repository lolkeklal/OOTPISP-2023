#ifndef OPENFILE_H
#define OPENFILE_H

#include <QMainWindow>
#include "QPushButton"
#include "QPlainTextEdit"
#include "QFormLayout"
#include "QFileDialog"
#include "QFile"
#include "QByteArray"

namespace Ui {
class OpenFile;
}

class OpenFile : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpenFile(QWidget *parent = nullptr);
    ~OpenFile();

private:
    Ui::OpenFile *ui;
    QPlainTextEdit* txtEdit;

public slots:
    void openFile();
};

#endif // OPENFILE_H
