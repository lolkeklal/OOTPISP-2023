#include "task04.h"

Task04Window::Task04Window(QWidget *parent)
    : QWidget(parent)
{
    for (int i = 0; i < 10; ++i)
        intStack.push(QRandomGenerator::global()->bounded(-10, 81));

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
    QString initialStack = "Initial Stack: ";
    QStack<int> tempStack(intStack);

    while (!tempStack.isEmpty())
        initialStack += QString::number(tempStack.pop()) + " ";

    QString resultText;
    QStack<int> replacedStack;

    while (!intStack.isEmpty())
    {
        int value = intStack.pop();
        int replacement = (value > 0) ? 1 : -1;
        replacedStack.push(replacement);
        resultText = QString::number(replacement) + " " + resultText;
    }

    while (!replacedStack.isEmpty())
        tempStack.push(replacedStack.pop());

    intStack = tempStack;

    stackResultLabel->setText("Stack Result:\n" + initialStack + "\nStack Result: " + resultText);
}



void Task04Window::processQueue()
{
    QString initialNumbers = "Initial Numbers: ";
    int maxElement = INT_MIN;

    for (int value : intQueue)
    {
        initialNumbers += QString::number(value) + " ";
        if (value > maxElement)
            maxElement = value;
    }

    QQueue<int> tempQueue;

    for (int value : intQueue)
        tempQueue.enqueue(value + maxElement);

    intQueue = tempQueue;

    QString resultText = "Queue Result: ";
    for (int value : intQueue)
        resultText += QString::number(value) + " ";

    queueResultLabel->setText(initialNumbers + "\n" + resultText);
}
