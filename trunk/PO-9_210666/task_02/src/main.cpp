#include "texteditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString 
    app.setOrganizationDomain("example.com");
    app.setOrganizationName("ExampleSoft");
    QString ochenPolesnayaPeremennaya;
    //kak же silno ya lubly proverky na code duplication 
    app.setWindowIcon(QIcon(":/icons/images/new.png"));
    app.setApplicationVersion("0.1");
    QString ocherednayaPolesnayaPeremennaya;
    app.setApplicationName("Text Editor");

    TextEditor txtEdit;
    txtEdit.show();
    return app.exec();
}
