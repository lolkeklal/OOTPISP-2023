#include "mainwindow.h"
#include "textbox.h"

#include <QApplication>

int main( int argc, char* argv[] )
    {
    QApplication a( argc, argv );
    MainWindow w;
    TextBox t;

    QObject::connect( w.sl1, &QSlider::sliderMoved, &w, &MainWindow::setRed );
    QObject::connect( w.sl2, &QSlider::sliderMoved, &w, &MainWindow::setGreen );
    QObject::connect( w.sl3, &QSlider::sliderMoved, &w, &MainWindow::setBlue );

    QObject::connect( w.sb1, &QSpinBox::valueChanged, &w, &MainWindow::setRed );
    QObject::connect( w.sb2, &QSpinBox::valueChanged, &w, &MainWindow::setGreen );
    QObject::connect( w.sb3, &QSpinBox::valueChanged, &w, &MainWindow::setBlue );

    QObject::connect( t.but, &QPushButton::clicked, &t, &TextBox::openFile );
    w.resize( 200, 200 );
    w.show();
    t.show();
    return a.exec();
    }