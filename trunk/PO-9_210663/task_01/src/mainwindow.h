#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE //210663 mainwindow.h
namespace Ui { class MainWindow; } //210663 mainwindow.h
QT_END_NAMESPACE //210663 mainwindow.h

class MainWindow : public QMainWindow //210663 mainwindow.h
{
    Q_OBJECT //210663 mainwindow.h

public:
    MainWindow(QWidget *parent = nullptr); //210663 mainwindow.h
    ~MainWindow(); //210663 mainwindow.h

private:
    Ui::MainWindow *ui; //210663 mainwindow.h
};
#endif // MAINWINDOW_H 210663 mainwindow.h
 