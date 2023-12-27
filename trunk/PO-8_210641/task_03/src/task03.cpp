#include "task03.h"
#include <QInputDialog>
#include <QRandomGenerator>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

Task03Window::Task03Window(QWidget* parent)
    : QWidget(parent)
{
    listWidget1 = new QListWidget(this);
    listWidget2 = new QListWidget(this);
    inputElementLineEdit = new QLineEdit(this);
    addToFirstListCheckBox = new QCheckBox("Add to List 1", this);
    addToSecondListCheckBox = new QCheckBox("Add to List 2", this);
    listLabel1 = new QLabel("List 1", this);
    listLabel2 = new QLabel("List 2", this);

    QPushButton* addElementButton = new QPushButton("Add Element", this);
    connect(addElementButton, &QPushButton::clicked, this, &Task03Window::fillListsRandomly);


    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* inputLayout = new QHBoxLayout();
    inputLayout->addWidget(inputElementLineEdit);
    inputLayout->addWidget(addElementButton);

    mainLayout->addWidget(listLabel1);
    mainLayout->addWidget(listWidget1);
    mainLayout->addWidget(listLabel2);
    mainLayout->addWidget(listWidget2);
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(addToFirstListCheckBox);
    mainLayout->addWidget(addToSecondListCheckBox);

    QRadioButton* addRadioButton = new QRadioButton("Add to List", this);
    QRadioButton* removeRadioButton = new QRadioButton("Remove from List", this);

    connect(addRadioButton, &QRadioButton::clicked, this, &Task03Window::onAddRadioButtonClicked);
    connect(removeRadioButton, &QRadioButton::clicked, this, &Task03Window::onRemoveRadioButtonClicked);

    mainLayout->addWidget(addRadioButton);
    mainLayout->addWidget(removeRadioButton);

    QPushButton* replaceListsButton = new QPushButton("Replace Lists", this);
    connect(replaceListsButton, &QPushButton::clicked, this, &Task03Window::replaceLists);
    mainLayout->addWidget(replaceListsButton);

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

    bool addToFirstList = addToFirstListCheckBox->isChecked();
    bool addToSecondList = addToSecondListCheckBox->isChecked();

    if (addToFirstList)
        listWidget1->addItem(elementText);

    if (addToSecondList)
        listWidget2->addItem(elementText);

    inputElementLineEdit->clear();
}


void Task03Window::onAddRadioButtonClicked()
{
    addToFirstListCheckBox->setChecked(true);
    addToSecondListCheckBox->setChecked(false);
}

void Task03Window::onRemoveRadioButtonClicked()
{
    if (listWidget1->count() > 0)
        delete listWidget1->takeItem(0);
    else if (listWidget2->count() > 0)
        delete listWidget2->takeItem(0);
}

void Task03Window::replaceLists()
{
    QStringList tempList1;
    QStringList tempList2;

    for (int i = 0; i < listWidget1->count(); ++i) {
        tempList1.append(listWidget1->item(i)->text());
    }

    for (int i = 0; i < listWidget2->count(); ++i) {
        tempList2.append(listWidget2->item(i)->text());
    }

    listWidget1->clear();
    listWidget2->clear();

    listWidget1->addItems(tempList2);
    listWidget2->addItems(tempList1);

    QString labelText1 = listLabel1->text();
    listLabel1->setText(listLabel2->text());
    listLabel2->setText(labelText1);
}
