#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QSlider>

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
    QPlainTextEdit* textEdit;
    QSpinBox* spinBoxes;
    QSlider* sliders;


public slots:
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);

private:
    Ui::MainWindow *ui;
    int red{0}, green{0}, blue{0};
};
#endif // MAINWINDOW_H
