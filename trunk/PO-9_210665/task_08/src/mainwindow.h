#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow> //210665//_8
#include <QVBoxLayout>//210665//_8
QT_BEGIN_NAMESPACE//210665
namespace Ui { class MainWindow; } //210665//_8
QT_END_NAMESPACE//210665
class MainWindow : public QMainWindow //210665//_8
{ //210665//_8
    Q_OBJECT//_8
public: //210665
    MainWindow(QWidget *parent = nullptr); //210665//_8
    ~MainWindow(); //210665//_8
private: //210665//_8
    Ui::MainWindow *ui; //210665//_8
}; //210665//_8
#endif // MAINWINDOW_H //210665//_8
