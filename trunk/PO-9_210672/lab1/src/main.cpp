#include "widget.h"

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QSpinBox>
#include <QLabel>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QSlider>
#include "textedit.h"
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPlainTextEdit plain_text_edit;
    Widget widget(0, &plain_text_edit);
    QGridLayout grid_layout;
    widget.setLayout(&grid_layout);

    // task 1
    QLabel red_label("Red"), green_label("Green"), blue_label("Blue");

    grid_layout.addWidget(&red_label, 0, 0);
    grid_layout.addWidget(&green_label, 1, 0);
    grid_layout.addWidget(&blue_label, 2, 0);

    QSpinBox red_sb, green_sb, blue_sb;

    grid_layout.addWidget(&red_sb, 0, 1);
    grid_layout.addWidget(&green_sb, 1, 1);
    grid_layout.addWidget(&blue_sb, 2, 1);

    QSlider red_slider(Qt::Horizontal), green_slider(Qt::Horizontal), blue_slider(Qt::Horizontal);

    grid_layout.addWidget(&red_slider, 0, 2);
    grid_layout.addWidget(&green_slider, 1, 2);
    grid_layout.addWidget(&blue_slider, 2, 2);

    grid_layout.addWidget(&plain_text_edit, 0, 3, 3, 1);

    // task 2
    red_sb.setMinimum(0);
    red_sb.setMaximum(255);
    green_sb.setMinimum(0);
    green_sb.setMaximum(255);
    blue_sb.setMinimum(0);
    blue_sb.setMaximum(255);

    red_slider.setMinimum(0);
    red_slider.setMaximum(255);
    green_slider.setMinimum(0);
    green_slider.setMaximum(255);
    blue_slider.setMinimum(0);
    blue_slider.setMaximum(255);

    plain_text_edit.setEnabled(false);

    QObject::connect(&red_slider, &QSlider::sliderMoved, &red_sb, &QSpinBox::setValue);
    QObject::connect(&red_sb, &QSpinBox::valueChanged, &red_slider, &QSlider::setValue);
    QObject::connect(&red_sb, &QSpinBox::valueChanged, &widget, &Widget::setRed);

    QObject::connect(&green_slider, &QSlider::sliderMoved, &green_sb, &QSpinBox::setValue);
    QObject::connect(&green_sb, &QSpinBox::valueChanged, &green_slider, &QSlider::setValue);
    QObject::connect(&green_sb, &QSpinBox::valueChanged, &widget, &Widget::setGreen);

    QObject::connect(&blue_slider, &QSlider::sliderMoved, &blue_sb, &QSpinBox::setValue);
    QObject::connect(&blue_sb, &QSpinBox::valueChanged, &blue_slider, &QSlider::setValue);
    QObject::connect(&blue_sb, &QSpinBox::valueChanged, &widget, &Widget::setBlue);


    widget.setWindowTitle("My program - my rules");
    widget.resize(500, 400);
    widget.show();

    // task 3
    QWidget dialog_widget(0);
    QGridLayout dialog_grid_layout;
    dialog_widget.setLayout(&dialog_grid_layout);

    TextEdit dialog_text_edit(&dialog_widget);
    dialog_grid_layout.addWidget(&dialog_text_edit, 0, 0);
    QPushButton file_button("Open file");
    dialog_grid_layout.addWidget(&file_button, 0, 1);

    QObject::connect(&file_button, &QPushButton::clicked, &dialog_text_edit, &TextEdit::openFile);


    dialog_widget.setWindowTitle("File open dialog");
    dialog_widget.resize(300, 300);
    dialog_widget.show();


    return app.exec();
}
