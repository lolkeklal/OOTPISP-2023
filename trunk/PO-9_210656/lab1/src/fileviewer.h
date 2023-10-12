#ifndef FILEVIEWER_H
#define FILEVIEWER_H

#include <QMainWindow>
#include <QPlainTextEdit>

namespace Ui {
class FileViewer;
}

class FileViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileViewer(QWidget *parent = nullptr);
    ~FileViewer();

private:
    Ui::FileViewer *ui;
    QPlainTextEdit *text;

public slots:
    void openFile();
};

#endif // FILEVIEWER_H
