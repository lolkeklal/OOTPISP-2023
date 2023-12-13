#include "task03.h"
#include <QInputDialog>
#include <QRandomGenerator>

Task03Window::Task03Window(QWidget *parent)
    : QWidget(parent)
{
    listWidget1 = new QListWidget(this);
    listWidget2 = new QListWidget(this);
    inputElementLineEdit = new QLineEdit(this);
    addToFirstListCheckBox = new QCheckBox("Add to List 1", this);
    addToSecondListCheckBox = new QCheckBox("Add to List 2", this);

    QPushButton *addElementButton = new QPushButton("Add Element", this);
    connect(addElementButton, &QPushButton::clicked, this, &Task03Window::fillListsRandomly);

    QPushButton *sortButton = new QPushButton("Sort Lists", this);
    connect(sortButton, &QPushButton::clicked, this, &Task03Window::sortList);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(inputElementLineEdit);
    inputLayout->addWidget(addElementButton);

    mainLayout->addWidget(listWidget1);
    mainLayout->addWidget(listWidget2);
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(addToFirstListCheckBox);
    mainLayout->addWidget(addToSecondListCheckBox);
    mainLayout->addWidget(sortButton);

    setLayout(mainLayout);
}

Task03Window::~Task03Window()
{
}

void Task03Window::fillListsRandomly()
{
    QString elementText = inputElementLineEdit->text();

    if (elementText.isEmpty())
        return;

    // Получаем состояние чекбоксов
    bool addToFirstList = addToFirstListCheckBox->isChecked();
    bool addToSecondList = addToSecondListCheckBox->isChecked();

    // Добавляем элемент в соответствующие списки
    if (addToFirstList)
        listWidget1->addItem(elementText);

    if (addToSecondList)
        listWidget2->addItem(elementText);

    // Очищаем поле ввода
    inputElementLineEdit->clear();
}

void Task03Window::sortList()
{
    // Сортировка элементов в обоих списках
    QList<QString> elementsList1;
    QList<QString> elementsList2;

    for (int i = 0; i < listWidget1->count(); ++i)
        elementsList1.append(listWidget1->item(i)->text());

    for (int i = 0; i < listWidget2->count(); ++i)
        elementsList2.append(listWidget2->item(i)->text());

    std::sort(elementsList1.begin(), elementsList1.end());
    std::sort(elementsList2.begin(), elementsList2.end());

    listWidget1->clear();
    listWidget2->clear();

    for (const QString &element : elementsList1)
        listWidget1->addItem(element);

    for (const QString &element : elementsList2)
        listWidget2->addItem(element);
}
