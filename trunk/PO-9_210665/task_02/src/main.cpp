#include "texteditor.h" //210665
#include <QApplication>  //210665
int main(int argc, char *argv[]) //210665
{
    QApplication a(argc, argv); //210665
    TextEditor w; //210665
    w.show(); //210665
    return a.exec(); //210665
}
