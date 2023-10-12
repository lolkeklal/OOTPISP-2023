#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent, QPlainTextEdit *textEdit);
    ~Widget();

    void setColor();
    void setRed(int value);
    void setGreen(int value);
    void setBlue(int value);

private:
    Ui::Widget *ui;
    int red, green, blue;
    QPlainTextEdit *textEdit;
};
#endif // WIDGET_H
