#ifndef TASK03_H
#define TASK03_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class task03;
}

class task03 : public QMainWindow
{
    Q_OBJECT

public:
    explicit task03(QWidget *parent = nullptr);
    ~task03();

    QTableWidget* firstListTable;
    QTableWidget* secondListTable;
    QTableWidget* linkedListTable;

    QPushButton* generateListsButton;
    QPushButton* processListsButton;
    QPushButton* generateLinkedListButton;
    QPushButton* processLinkedListButton;

    QLabel* higherThan;

private:
    Ui::task03 *ui;

    int firstListSize;
    int secondListSize;
    int linkedListSize;

    QList<int> firstList;
    QList<int> secondList;
    std::list<int> linkedList;
private slots:
    void generateLists();
    void processLists();
    void generateLinkedList();
    void processLinkedList();
};

#endif // TASK03_H
