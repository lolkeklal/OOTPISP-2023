#ifndef TASK04_H
#define TASK04_H

#include <QWidget>
#include <QStack>
#include <QQueue>
#include <QPushButton>
#include <QLabel>
#include <QRandomGenerator>
#include <QGridLayout>

class Task04Window : public QWidget
{
    Q_OBJECT

public:
    Task04Window(QWidget *parent = nullptr);
    ~Task04Window();

private slots:
    void processStack();
    void processQueue();

private:
    QStack<int> intStack;
    QQueue<int> intQueue;
    QLabel *stackResultLabel;
    QLabel *queueResultLabel;
};

#endif // TASK04_H
