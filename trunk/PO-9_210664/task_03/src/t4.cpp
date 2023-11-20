#include "t4.h"
#include "ui_t4.h"

#include <QStack>
#include <QQueue>
#include <QRandomGenerator>

t4::t4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t4)
{
    ui->setupUi(this);
    this->on_pushButton_clicked();
}

t4::~t4()
{
    delete ui;
}

void t4::on_pushButton_clicked()
{
    QStack<int> stack;
    for (int i = 0; i < 5; ++i) {
        stack.push(QRandomGenerator::global()->bounded(0, 50));
    }

    QString stackText = "Stack: ";
    for (int i : stack) {
        stackText += QString::number(i) + " ";
    }
    ui->label->setText(stackText);

    int max = stack.top();
    int min = stack.top();
    int i = 0;
    int max_i = 0;
    int min_i = 0;
    QStack<int> tempStack;

    while (!stack.isEmpty()) {
        int val = stack.pop();
        tempStack.push(val);
        if (val > max) {
            max = val;
            max_i = i;
        }
        if (val < min) {
            min = val;
            min_i = i;
        }
        i++;
    }

    for (; i > 0;) {
        i--;
        int val = tempStack.pop();

        if (i == min_i) {
            stack.push(max);
        }
        else if (i == max_i) {
            stack.push(min);
        }
        else {
            stack.push(val);
        }
    }

    QString replacedStackText = "Replaced Stack: ";
    for (int i : stack) {
        replacedStackText += QString::number(i) + " ";
    }
    ui->label->setText(ui->label->text() + "\n" + replacedStackText + "\n");

    QQueue<int> queue;
    for (int i = 0; i < 8; ++i) {
        queue.enqueue(QRandomGenerator::global()->bounded(0, 50));
    }

    QString queueText = "Queue: ";
    QQueue<int> tempQueue = queue;
    while (!tempQueue.isEmpty()) {
        queueText += QString::number(tempQueue.dequeue()) + " ";
    }
    ui->label->setText(ui->label->text() + "\n" + queueText);

    int sum = 0;
    int count = 0;
    tempQueue = queue;
    while (!tempQueue.isEmpty()) {
        int val = tempQueue.dequeue();
        if (val % 2 == 0) {
            sum += val;
            ++count;
        }
    }

    QQueue<int> resultQueue = tempQueue;
    if (count > 0) {
        int average = sum / count;
        tempQueue = queue;
        for (int i = 0; i < 8; ++i) {
            int val = tempQueue.dequeue();
            if (val % 2 == 0) {
                resultQueue.enqueue(average);
            }
            else {
                resultQueue.enqueue(val);
            }
        }
    }

    QString replacedQueueText = "Replaced Queue: ";
    while (!resultQueue.isEmpty()) {
        replacedQueueText += QString::number(resultQueue.dequeue()) + " ";
    }

    ui->label->setText(ui->label->text() + "\n" + replacedQueueText);
}
