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
    QLabel *redLabel;
    QLabel *greenLabel;
    QLabel *blueLabel;
    QSpinBox *redSpinBox;
    QSpinBox *greenSpinBox;
    QSpinBox *blueSpinBox;
    QSlider *redSlider;
    QSlider *greenSlider;
    QSlider *blueSlider;
    QPlainTextEdit *colorPreviewTextEdit;
    QGridLayout *mainGridLayout;

public slots:
    void updateColorPreview();
    void setRedValue(int value);
    void setGreenValue(int value);
    void setBlueValue(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
