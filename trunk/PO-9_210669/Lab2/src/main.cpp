#include "texteditor.h"//210669_main.cpp

#include <QApplication>//210669_main.cpp

int main(int argc, char *argv[])//210669_main.cpp
{
    QApplication a(argc, argv); //210669_main.cpp
    TextEditor w;//210669_main.cpp
    a.setApplicationName("Text Editor");//210669_main.cpp
    a.setApplicationVersion("0.1");//210669_main.cpp
    a.setWindowIcon(QIcon(":/tables/t1_1.png"));//210669_main.cpp
    a.setApplicationVersion("0.1");//210669_main.cpp
    a.setOrganizationName("ExampleSoft");//210669_main.cpp
    a.setOrganizationDomain("example.com");//210669_main.cpp
    w.show();//210669_main.cpp
    return a.exec();//210669_main.cpp
}
