#include "t.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    t t;
    t.show();

    return a.exec();
}
