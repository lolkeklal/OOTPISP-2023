#include "mainwindow.h"
#include "textreviwer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainwindow;
    TextReviwer text;
    mainwindow.resize( 400, 200 );
    mainwindow.show();
    text.resize( 600, 600 );
    text.show();
    return a.exec();
}
