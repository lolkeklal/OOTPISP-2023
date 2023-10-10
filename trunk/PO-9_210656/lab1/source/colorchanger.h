#ifndef COLORCHANGER_H
#define COLORCHANGER_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QSlider>

namespace Ui {
class ColorChanger;
}

class ColorChanger : public QMainWindow
{
    Q_OBJECT

public:
    explicit ColorChanger(QWidget *parent = nullptr);
    ~ColorChanger();
    void setColor();
    QPlainTextEdit* textEdit;
    QSpinBox* spinBoxes;
    QSlider* sliders;


public slots:
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);

private:
    Ui::ColorChanger *ui;
    int red{0}, green{0}, blue{0};
};

#endif // COLORCHANGER_H
