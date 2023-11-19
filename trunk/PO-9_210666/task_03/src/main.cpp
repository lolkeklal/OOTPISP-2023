#include "choosetask.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChooseTask ct;
    ct.show();
    return a.exec();
}
