#include "bd.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BD w;
    w.show();
    return a.exec();
}
