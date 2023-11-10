#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget> //210667

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; } //210667
QT_END_NAMESPACE

class Widget : public QWidget //210667
{ //210667
    Q_OBJECT

public: //210667
    Widget(QWidget *parent = nullptr); //210667
    ~Widget(); //210667

private: //210667
    Ui::Widget *ui; //210667
};
#endif // WIDGET_H
