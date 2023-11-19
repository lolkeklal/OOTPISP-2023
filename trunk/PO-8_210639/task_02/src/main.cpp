#include "texteditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a210639(argc, argv);
    textEditor210639 w210639;
    a210639.setApplicationName("Text Editor");
    a210639.setApplicationVersion("0.1");
    a210639.setOrganizationName("ExampleSoft");
    a210639.setOrganizationDomain("example.com");
    a210639.setWindowIcon(QIcon(":/icons/new.png"));
    w210639.show();
    return a210639.exec();
}
