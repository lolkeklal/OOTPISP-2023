#include "database.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase data;
    data.show();
    return a.exec();
}
