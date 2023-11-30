#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TemperatureConverter converter;
    converter.setGeometry(0,0,200,100);
    converter.show();

    return app.exec();
}
