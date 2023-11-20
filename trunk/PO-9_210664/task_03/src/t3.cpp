#include "t3.h"
#include "ui_t3.h"

#include <QList>
#include <list>
#include <QRandomGenerator>

t3::t3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t3)
{
    ui->setupUi(this);
    this->on_pushButton_clicked();
}

t3::~t3()
{
    delete ui;
}

void t3::fillRandom(QList<int>& list, int size) {
    list.clear();
    for (int i = 0; i < size; ++i) {
        list.append(QRandomGenerator::global()->bounded(-100, 100));
    }
}
void t3::fillRandom(std::list<int>& list, int size) {
    list.clear();
    for (int i = 0; i < size; ++i) {
        list.push_back(QRandomGenerator::global()->bounded(-100, 100));
    }
}

QString t3::listToString(const QList<int>& list) {
    QString result;
    for (const auto& elem : list) {
        result += " " + QString::number(elem);
    }
    return result;
}


void t3::replacePositiveWithMin(QList<int>& list1, const QList<int>& list2) {
    if (list1.size() != list2.size()) {
        qDebug() << "Error: Lists must have the same size.";
        return;
    }

    int minFromList2 = *std::min_element(list2.begin(), list2.end());

    for (int i = 0; i < list1.size(); ++i) {
        if (list1[i] > 0) {
            list1[i] = minFromList2;
        }
    }
}

void t3::removeElementsGreaterThanK(std::list<int>& linkedList, int k) {
    auto it = linkedList.begin();
    while (it != linkedList.end()) {
        if (*it > k) {
            it = linkedList.erase(it);
        } else {
            ++it;
        }
    }
}

// Regenerate
void t3::on_pushButton_clicked()
{
    QList<int> list1, list2;
    fillRandom(list1, 10);
    fillRandom(list2, 10);

    QString list1BeforeReplacement = "List 1 before replacement: " + listToString(list1);
    QString list2String = "List 2: " + listToString(list2);

    ui->label->setText(list1BeforeReplacement + "\n" + list2String);

    replacePositiveWithMin(list1, list2);

    QString list1AfterReplacement = "List 1 after replacement: " + listToString(list1);
    this->ui->label->setText(this->ui->label->text() + "\n" + list1AfterReplacement + "\n");

    // ---------------------------------------

    std::list<int> linkedList;
    fillRandom(linkedList, 10);

    QString linkedListBeforeRemoval = "Linked List before removal:";
    for (const auto& elem : linkedList) {
        linkedListBeforeRemoval += " " + QString::number(elem);
    }

    this->ui->label->setText(this->ui->label->text() + "\n" + linkedListBeforeRemoval);

    removeElementsGreaterThanK(linkedList, this->ui->spinBox->value());

    QString linkedListAfterRemoval = "Linked List after removal:";
    for (const auto& elem : linkedList) {
        linkedListAfterRemoval += " " + QString::number(elem);
    }

    this->ui->label->setText(this->ui->label->text() + "\n" + linkedListAfterRemoval);

}
