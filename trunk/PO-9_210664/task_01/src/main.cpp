//#include "mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QPlainTextEdit>

#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>

QPlainTextEdit* pte;
int pte_red = 0;
int pte_green = 0;
int pte_blue = 0;

QSpinBox* sp_red;
QSpinBox* sp_green;
QSpinBox* sp_blue;
QSlider* s_red;
QSlider* s_green;
QSlider* s_blue;

QTextEdit *text_edit;

void populate_window(QWidget* widget);
void setColor();

void setRed(int color);
void setGreen(int color);
void setBlue(int color);

void openFile();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w(0);
    QMainWindow w(0);

    QWidget *centralWidget = new QWidget(&w);
    w.setCentralWidget(centralWidget);

    populate_window(centralWidget);

    // ---------------------------------------

    QWidget *dialog_widget = new QWidget(&w);
    dialog_widget->resize(500, 200);

    QHBoxLayout dialog_layout;
    dialog_widget->setLayout(&dialog_layout);

    text_edit = new QTextEdit();
    dialog_layout.addWidget(text_edit);

    QPushButton *btn = new QPushButton();
    dialog_widget->connect(btn, &QPushButton::clicked, dialog_widget, openFile);
    btn->setText("Button");
    dialog_layout.addWidget(btn);

    // ---------------------------------------

    w.show();
    w.resize(500, 300);
    return a.exec();
}

void populate_window(QWidget* widget) {
    QGridLayout *grid_layout = new QGridLayout(widget);

    QLabel *l_red = new QLabel("Red");
    QLabel *l_green = new QLabel("Green");
    QLabel *l_blue = new QLabel("Blue");
    grid_layout->addWidget(l_red, 0, 0);
    grid_layout->addWidget(l_green, 1, 0);
    grid_layout->addWidget(l_blue, 2, 0);

    sp_red = new QSpinBox();
    sp_green = new QSpinBox();
    sp_blue = new QSpinBox();
    widget->connect(sp_red, &QSpinBox::valueChanged, widget, setRed);
    widget->connect(sp_green, &QSpinBox::valueChanged, widget, setGreen);
    widget->connect(sp_blue, &QSpinBox::valueChanged, widget, setBlue);
    sp_red->setMaximum(255);
    sp_green->setMaximum(255);
    sp_blue->setMaximum(255);
    grid_layout->addWidget(sp_red, 0, 1);
    grid_layout->addWidget(sp_green, 1, 1);
    grid_layout->addWidget(sp_blue, 2, 1);

    s_red = new QSlider(Qt::Orientation::Horizontal);
    s_green = new QSlider(Qt::Orientation::Horizontal);
    s_blue = new QSlider(Qt::Orientation::Horizontal);
    widget->connect(s_red, &QSlider::valueChanged, widget, setRed);
    widget->connect(s_green, &QSlider::valueChanged, widget, setGreen);
    widget->connect(s_blue, &QSlider::valueChanged, widget, setBlue);
    s_red->setMaximum(255);
    s_green->setMaximum(255);
    s_blue->setMaximum(255);
    grid_layout->addWidget(s_red, 0, 2);
    grid_layout->addWidget(s_green, 1, 2);
    grid_layout->addWidget(s_blue, 2, 2);

    pte = new QPlainTextEdit();
    setColor();
    pte->setEnabled(false);
    grid_layout->addWidget(pte, 0, 3, 0, 2);
}

void setColor() {
    const QString templ("background-color: rgb(%1, %2, %3);");
    pte->setStyleSheet(templ.arg(pte_red).arg(pte_green).arg(pte_blue));
}

void setRed(int color) {
    pte_red = color;
    sp_red->setValue(color);
    s_red->setValue(color);
    setColor();
}
void setGreen(int color) {
    pte_green = color;
    sp_green->setValue(color);
    s_green->setValue(color);
    setColor();
}
void setBlue(int color) {
    pte_blue = color;
    sp_blue->setValue(color);
    s_blue->setValue(color);
    setColor();
}

void openFile() {
    QString file_name = QFileDialog::getOpenFileName();
    QFile file(file_name);
    file.open(QFile::OpenModeFlag::ReadOnly);

    QByteArray file_content = file.readAll();
    text_edit->setText(file_content);
}
