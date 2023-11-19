#include "texteditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextEditor w;
    a.setApplicationName("Text Editor");
    a.setApplicationVersion("0.1");
    a.setWindowIcon(QIcon(":/tables/t1_1.png"));
    a.setApplicationVersion("0.1");
    a.setOrganizationName("ExampleSoft");
    a.setOrganizationDomain("example.com");
    w.show();
    return a.exec();
}
