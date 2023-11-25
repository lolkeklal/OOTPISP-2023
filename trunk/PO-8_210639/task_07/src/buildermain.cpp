#include <QCoreApplication>
#include <qDebug>
#include "uglyfacebuilder.h"
#include "faceDirector.h"

using namespace std;

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    uglyFaceBuilder* b = new uglyFaceBuilder;
    faceDirector* director = new faceDirector;
    director->construct(b);


    delete b;
    delete director;
    return a.exec();

}
