#include <QApplication>
#include "textwidget.h"
#include "sinusoidalmovementwidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TextWidget w;
    w.resize(400, 300);
    w.show();

    SinusoidalMovementWidget widget;
    widget.show();

    return app.exec();
}
