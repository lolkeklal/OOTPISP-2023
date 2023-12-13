#ifndef TASK01_H
#define TASK01_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVector>

namespace Ui {
class task01;
}

class task01 : public QMainWindow
{
    Q_OBJECT

public:
    explicit task01(QWidget *parent = nullptr);

    QLineEdit* edit1;
    QLineEdit* edit2;
    QLineEdit* edit3;

    QPushButton* compareButton;

    QLabel* resultLabel;

    ~task01();

private:
    Ui::task01 *ui;
    void sortFromMinToMax(QVector<float>& Arr, int first, int last);
private slots:
    void compareValues();
};

#endif // TASK01_H
