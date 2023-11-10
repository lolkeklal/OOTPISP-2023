#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QSlider>
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setRed(int value);
    void setGreen(int value);
    void setBlue(int value);
    void setColor();
    void openFile(); // Добавлено объявление для слота открытия файла

private:
    Ui::MainWindow *ui;
    QSpinBox *redSpinBox;
    QSlider *redSlider;
    QSpinBox *greenSpinBox;
    QSlider *greenSlider;
    QSpinBox *blueSpinBox;
    QSlider *blueSlider;
    QPlainTextEdit *textEdit;
};

#endif // MAINWINDOW_H
