#ifndef TASK01_H
#define TASK01_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class Task01Window : public QWidget
{
    Q_OBJECT

public:
    Task01Window(QWidget *parent = nullptr);
    ~Task01Window();

private slots:
    void calculateResult();

private:
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QLabel *resultLabel;
};

#endif // TASK01_H
