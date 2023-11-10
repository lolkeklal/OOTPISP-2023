#include "mainwindow.h"// 210668_Подключаем библиотеку "mainwindow.h"
//210668
#include <QApplication>// 210668_Подключаем библиотеку QApplication
//210668
int main(int argc, char *argv[])// 210668
{ // 210668
    QApplication a(argc, argv);// 210668
    MainWindow w; // 210668
    w.show(); // 210668
    return a.exec(); // 210668
} // 210668
