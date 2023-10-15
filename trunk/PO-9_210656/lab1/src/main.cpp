#include <QApplication>
#include "colorchanger.h"
#include "fileviewer.h"

int main (int argc, char **argv)
{
    QApplication app(argc, argv);
    FileViewer temp;
    temp.show();
    ColorChanger temp2;
    temp2.show();
    return app.exec();
}

