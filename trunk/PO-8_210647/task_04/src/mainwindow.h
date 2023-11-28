#ifndef MAINWINDOW_H//210674
#define MAINWINDOW_H//210674
//210674
#include <QMainWindow>//210674
//210674
QT_BEGIN_NAMESPACE//210674
namespace Ui { class MainWindow; }//210674
QT_END_NAMESPACE//210674
//210674
class MainWindow : public QMainWindow//210674
{//210674
    Q_OBJECT//210674
//210674
public://210674
    MainWindow(QWidget *parent = nullptr);//210674
    ~MainWindow();//210674
//210674
private://210674
    Ui::MainWindow *ui;//210674
};//210674
#endif // MAINWINDOW_H//210674
