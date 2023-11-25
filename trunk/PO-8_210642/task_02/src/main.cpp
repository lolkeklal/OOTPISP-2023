#include "notepad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a210642(argc, argv);
    NotePad w210642;
    a210642.setApplicationName("Text Editor");
    a210642.setApplicationVersion("0.1");
    a210642.setOrganizationName("ExampleSoft");
    a210642.setOrganizationDomain("example.com");
    a210642.setWindowIcon(QIcon(":/icons/new.png"));
    w210642.show();
    return a210642.exec();
}
