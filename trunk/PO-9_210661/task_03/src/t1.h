// t1.h
#ifndef T1_H
#define T1_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class t1;
}

class t1 : public QWidget
{
    Q_OBJECT

public:
    explicit t1(QWidget *parent = nullptr);
    ~t1();

private slots:
    void sortVariables();

private:
    Ui::t1 *ui;
    QLineEdit *lineEditX;
    QLineEdit *lineEditY;
    QLineEdit *lineEditZ;
    QPushButton *sortButton;
};

#endif // T1_H
