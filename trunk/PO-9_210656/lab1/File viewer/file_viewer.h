#ifndef FILE_VIEWER_H
#define FILE_VIEWER_H

#include <QMainWindow>
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPlainTextEdit *text;

public slots:
    void openFile();

};
#endif // FILE_VIEWER_H
