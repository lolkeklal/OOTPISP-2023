#include "sortingtable.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SortingTable s;
    s.setFixedSize(1100,250);
    s.show();
    return a.exec();
}
