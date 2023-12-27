#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(0));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setMaximumHeight(330);
    w.setMaximumWidth(740);
    return a.exec();
}
