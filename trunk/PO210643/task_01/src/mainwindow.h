#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPushButton"
#include "QRadioButton"
#include "QSpinBox"
#include "QLabel"
#include "QSlider"
#include "QPlainTextEdit"
#include "QFormLayout"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setColor();

    int r{0};
    int g{0};
    int b{0};

    QPlainTextEdit* txtEdit;
    QSpinBox* sBox1;
    QSpinBox* sBox2;
    QSpinBox* sBox3;
    QSlider* slider1;
    QSlider* slider2;
    QSlider* slider3;

private:
    Ui::MainWindow *ui;

public slots:
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
};
#endif // MAINWINDOW_H
