#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QGridLayout>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void setRed(int value);
    void setGreen(int value);
    void setBlue(int value);
    void setColor();

private:
    QLabel redLabel;
    QSpinBox redSpinBox;
    QSlider redSlider;
    QLabel greenLabel;
    QSpinBox greenSpinBox;
    QSlider greenSlider;
    QLabel blueLabel;
    QSpinBox blueSpinBox;
    QSlider blueSlider;
    QPlainTextEdit textEdit;

private:
    Ui::Widget *ui;
};


class Widget1 : public QWidget
{
    Q_OBJECT

public:
    Widget1(QWidget *parent = nullptr);
    ~Widget1();

private slots:
    void openFile();

private:
    QTextEdit* textEdit;
    QPushButton* button;
};

#endif // WIDGET_H
