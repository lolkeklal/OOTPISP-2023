#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QPlainTextEdit>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setColor();

public slots:
    void setRed(int value);
    void setGreen(int value);
    void setBlue(int value);
    void openFile();

private:
    QLabel *redLabel;
    QSpinBox *redSpinBox;
    QSlider *redSlider;

    QLabel *greenLabel;
    QSpinBox *greenSpinBox;
    QSlider *greenSlider;

    QLabel *blueLabel;
    QSpinBox *blueSpinBox;
    QSlider *blueSlider;

    QPlainTextEdit *colorDisplay;

    QGridLayout *layout;

    QPushButton *openFileButton;
    QTextEdit *textEdit;
};
#endif // MAINWINDOW_H
