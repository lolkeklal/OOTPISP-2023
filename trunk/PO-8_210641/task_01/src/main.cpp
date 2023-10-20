#include "mainwindow.h"
#include "textreviwer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    TextReviwer t;
    w.resize( 400, 200 );
    w.show();
    t.resize( 600, 600 );
    t.show();
    return a.exec();
}
