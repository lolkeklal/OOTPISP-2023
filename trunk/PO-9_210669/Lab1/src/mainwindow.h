#ifndef MAINWINDOW_H //210669_1
#define MAINWINDOW_H //210669_1

#include <QMainWindow> //210669_1

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } //210669_1
QT_END_NAMESPACE

class MainWindow : public QMainWindow //210669_1
{
    Q_OBJECT //210669_1

public:
    MainWindow(QWidget *parent = nullptr); //210669_1
    ~MainWindow(); //210669_1

private:
    Ui::MainWindow *ui; //210669_1
};
#endif // MAINWINDOW_H //210669_1
