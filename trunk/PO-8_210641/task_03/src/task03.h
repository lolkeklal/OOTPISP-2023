// task03.h
#ifndef TASK03_H
#define TASK03_H

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>

class Task03Window : public QWidget
{
    Q_OBJECT

public:
    Task03Window(QWidget* parent = nullptr);
    ~Task03Window();

private slots:
    void fillListsRandomly();
    void onAddRadioButtonClicked();
    void onRemoveRadioButtonClicked();
    void replaceLists();

private:
    QListWidget* listWidget1;
    QListWidget* listWidget2;
    QLineEdit* inputElementLineEdit;
    QCheckBox* addToFirstListCheckBox;
    QCheckBox* addToSecondListCheckBox;
    QLabel* listLabel1;
    QLabel* listLabel2;
};

#endif // TASK03_H
