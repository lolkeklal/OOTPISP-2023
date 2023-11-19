#include "matrixdeterminant.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MatrixDeterminant matrix_210641;
    matrix_210641.show();
    return a.exec();
}
