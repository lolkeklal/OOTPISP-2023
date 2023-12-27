#include "mainwindow.h"

#include <QApplication>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

int main(int argc, char *argv[]) //210647
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
