#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(0));
    QApplication a(argc, argv);
    MainWindow w;
    w.setMaximumSize(QSize(200, 200));
    w.show();
    return a.exec();
}
