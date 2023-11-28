#include "texteditor.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Text Editor"); //1
    a.setApplicationVersion("0.1");


    a.setOrganizationName("ExampleSoft");
    a.setOrganizationDomain("example.com");
    QIcon icon(":/Users/dashubaa/univer/3kurs/oop/OOTPISP-2023/tasks/task_02/images/tables/t1_1.png");
    a.setWindowIcon(icon);
   TextEditor w("example.txt");
    w.show();
    return a.exec();
}
