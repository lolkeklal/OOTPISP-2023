#ifndef TASK05_H
#define TASK05_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>

namespace Ui {
class task05;
}

class task05 : public QMainWindow
{
    Q_OBJECT

public:
    explicit task05(QWidget *parent = nullptr);
    ~task05();

    QTableWidget* firstFisher;
    QTableWidget* secondFisher;
    QTableWidget* thirdFisher;
    QTableWidget* fishes;
    QTableWidget* equalFishes;
    QTableWidget* notCaughtFishes;

    QPushButton* generateButton;

private:
    Ui::task05 *ui;

    int size1;
    int size2;
    int size3;
    int allFishesSize=0;

    QVector<QString> fv;
    QVector<QString> sv;
    QVector<QString> tv;

    QVector<QString> v{ "anchovy", "carp", "catfish", "perch", "pike" };
private slots:
    void generateTables();
};

#endif // TASK05_H
