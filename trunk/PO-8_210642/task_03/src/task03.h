#ifndef TASK03_H
#define TASK03_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRandomGenerator>

class Task03Window : public QWidget
{
    Q_OBJECT

public:
    Task03Window(QWidget *parent = nullptr);
    ~Task03Window();

private slots:
    void fillListsRandomly();
    void sortList();

private:
    QListWidget *listWidget1;
    QListWidget *listWidget2;
    QLineEdit *inputElementLineEdit;
    QCheckBox *addToFirstListCheckBox;
    QCheckBox *addToSecondListCheckBox;
};

#endif // TASK03_H
