#include "task04.h"

Task04Window::Task04Window(QWidget *parent)
    : QWidget(parent)
{
    // Заполняем стек 10 случайными числами из интервала [-10; 80]
    for (int i = 0; i < 10; ++i)
        intStack.push(QRandomGenerator::global()->bounded(-10, 81));

    // Формируем очередь из 8 чисел
    for (int i = 0; i < 8; ++i)
        intQueue.enqueue(QRandomGenerator::global()->bounded(-10, 81));

    stackResultLabel = new QLabel("Stack Result: ", this);
    queueResultLabel = new QLabel("Queue Result: ", this);

    QPushButton *stackButton = new QPushButton("Process Stack", this);
    QPushButton *queueButton = new QPushButton("Process Queue", this);

    connect(stackButton, &QPushButton::clicked, this, &Task04Window::processStack);
    connect(queueButton, &QPushButton::clicked, this, &Task04Window::processQueue);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(stackButton, 0, 0);
    mainLayout->addWidget(queueButton, 1, 0);
    mainLayout->addWidget(stackResultLabel, 0, 1);
    mainLayout->addWidget(queueResultLabel, 1, 1);

    setLayout(mainLayout);
}

Task04Window::~Task04Window()
{
}

void Task04Window::processStack()
{
    // Заменяем значения остатками от деления на номер элемента в стеке
    QString resultText;
    QStack<int> tempStack;
    int size = intStack.size();

    for (int i = 0; i < size; ++i)
    {
        int value = intStack.pop();
        value %= size - i;
        tempStack.push(value);
        resultText = QString::number(value) + " " + resultText;
    }

    intStack = tempStack;
    stackResultLabel->setText("Stack Result: " + resultText);
}

void Task04Window::processQueue()
{
    // Показываем изначальные числа
    QString initialNumbers = "Initial Numbers: ";
    for (int value : intQueue)
        initialNumbers += QString::number(value) + " ";

    // Заменяем значение первого элемента очереди суммой первого и последнего,
    // второго элемента очереди - суммой второго и предпоследнего и т.д.
    int size = intQueue.size();
    QQueue<int> tempQueue;

    for (int i = 0; i < size / 2; ++i)
    {
        int first = intQueue.dequeue();
        int last = intQueue.dequeue();
        tempQueue.enqueue(first + last);
    }

    while (!intQueue.isEmpty())
        tempQueue.enqueue(intQueue.dequeue());

    intQueue = tempQueue;

    // Выводим результат
    QString resultText = "Queue Result: ";
    for (int value : intQueue)
        resultText += QString::number(value) + " ";

    // Выводим изначальные числа и результат
    queueResultLabel->setText(initialNumbers + "\n" + resultText);
}
