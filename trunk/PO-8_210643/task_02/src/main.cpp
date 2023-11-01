#include "texteditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TextEditor widgets;
    widgets.show();
    return app.exec();
}
