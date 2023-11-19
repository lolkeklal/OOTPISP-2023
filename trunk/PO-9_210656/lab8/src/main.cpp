#include <QApplication>
#include "snowmanwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SnowmanWidget w;
    w.show();
    return a.exec();
}
