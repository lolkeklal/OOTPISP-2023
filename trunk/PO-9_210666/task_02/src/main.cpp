#include "texteditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setOrganizationDomain("example.com");
    app.setOrganizationName("ExampleSoft");
    app.setWindowIcon(QIcon(":/icons/images/new.png"));
    app.setApplicationVersion("0.1");
    app.setApplicationName("Text Editor");

    TextEditor txtEdit;
    txtEdit.show();
    return app.exec();
}
