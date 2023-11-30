// t3.cpp
#include "t3.h"
#include "ui_t3.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

t3::t3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t3)
{
    ui->setupUi(this);
    setWindowTitle("t3");

    std::srand(std::time(nullptr));

    // Заполнение списков случайными элементами
    for (int i = 0; i < 5; ++i) {
        list1.append(std::rand() % 100);
        list2.append(std::rand() % 100);
    }

    // Связываем слот с сигналом кнопки "Do It!"
    connect(ui->pushButtonDoIt, &QPushButton::clicked, this, &t3::onDoItButtonClicked);
}

t3::~t3()
{
    delete ui;
}

void t3::onDoItButtonClicked()
{
    // В зависимости от выбранного QRadioButton выполняем соответствующее действие
    if (ui->radioButtonAdd->isChecked()) {
        int newItem = std::rand() % 100;
        list1.append(newItem);
        updateOutputText("Added element: " + QString::number(newItem) + "\nList 1 after addition: " + listToString(list1, ", "));
    } else if (ui->radioButtonRemove->isChecked()) {
        if (!list1.isEmpty()) {
            int removedItem = list1.takeFirst();
            updateOutputText("Removed element: " + QString::number(removedItem) + "\nList 1 after removal: " + listToString(list1, ", "));
        } else {
            updateOutputText("List 1 is empty. Cannot remove.");
        }
    } else if (ui->radioButtonReplace->isChecked()) {
        list1.swap(list2);
        updateOutputText("List 1 after replacement: " + listToString(list1, ", ") + "\nList 2 after replacement: " + listToString(list2, ", "));
    } else {
        // Если ни один из QRadioButton не выбран
        updateOutputText("No action selected. Please choose an action.");
    }
}

QString t3::listToString(const QList<int>& list, const QString& separator)
{
    QStringList stringList;
    for (const auto& item : list) {
        stringList.append(QString::number(item));
    }
    return stringList.join(separator);
}


void t3::updateOutputText(const QString& text)
{
    // Очищаем текущий текст и добавляем новый
    ui->outputTextEdit->clear();
    ui->outputTextEdit->append(text);
}
