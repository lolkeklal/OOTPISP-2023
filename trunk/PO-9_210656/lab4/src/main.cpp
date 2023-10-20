#include "mainwindow.h" //210656

#include <QApplication> //210656

int main(int argc, char *argv[]) //210656
{
    QApplication a(argc, argv); //210656
    MainWindow w; //210656
    w.show(); //210656
    return a.exec(); //210656
}
