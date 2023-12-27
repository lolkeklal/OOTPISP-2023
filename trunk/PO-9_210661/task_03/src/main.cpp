#include "t1.h"
#include "t2.h"
#include "t3.h"
#include "t4.h"
#include "t5.h"
#include "t6.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    t1 t1;
    t1.show();

    t2 t2;
    t2.show();

    t3 t3;
    t3.show();

    t4 t4;
    t4.show();

    t5 t5;
    t5.show();

    t6 t6;
    t6.show();
    return a.exec();
}
