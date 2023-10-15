#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QPlainTextEdit>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QSpinBox *spinBox1;
    QSpinBox *spinBox2;
    QSpinBox *spinBox3;
    QSlider *slider1;
    QSlider *slider2;
    QSlider *slider3;
    QPlainTextEdit *textEdit;
    QGridLayout *gridLayout;

public slots:
    void setColor();
    void setRed(int value);
    void setGreen(int value);
    void setBlue(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
