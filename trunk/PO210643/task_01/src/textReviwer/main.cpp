#include "textreviwer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextReviwer w;
    w.show();
    return a.exec();
}
