#include "mainwindow.h" //210664

#include <QApplication> //210664

int main(int argc, char *argv[]) //210664
{
    QApplication a(argc, argv); //210664
    MainWindow w; //210664
    w.show(); //210664
    return a.exec(); //210664
}
