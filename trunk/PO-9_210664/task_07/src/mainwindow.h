#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> //210664
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } //210664
QT_END_NAMESPACE

class MainWindow : public QMainWindow //210664
{ //210664
    Q_OBJECT

public: //210664
    MainWindow(QWidget *parent = nullptr); //210664
    ~MainWindow(); //210664
 //210664
private: //210664
    Ui::MainWindow *ui; //210664
}; //210664
#endif // MAINWINDOW_H //210664
