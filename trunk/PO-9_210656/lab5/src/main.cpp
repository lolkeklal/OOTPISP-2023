#include "databasewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DatabaseWindow window;
    window.show();
    return app.exec();
}
