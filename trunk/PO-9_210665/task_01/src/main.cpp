#include "gg.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mw;
    gg GG;
    mw.show();
    GG.show();
    return app.exec();
}
