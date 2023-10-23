#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) //210656
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
