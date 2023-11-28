#include "mainwindow.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QStack>
#include <QQueue>
#include <random>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Решение");
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // Зaдание 1

    QStack<int> myStack;
    myStack << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8; // Зaполнение стека
    QLabel *stackLabel1 = new QLabel("Стек до замены значений:");
    layout->addWidget(stackLabel1);
    for (int i = 0; i < myStack.size(); ++i) {
        QLabel *label = new QLabel(QString::number(myStack[i]));
        layout->addWidget(label);
    }
    for (int i = 0; i < myStack.size() / 2; ++i) {
        myStack[i] = myStack[i] * myStack[myStack.size() - 1 - i]; // Зaмена значений в соответствии с заданием
    }

    QLabel *stackLabel = new QLabel("Стек после замены значений:");
    layout->addWidget(stackLabel);
    for (int i = 0; i < myStack.size(); ++i) {
        QLabel *label = new QLabel(QString::number(myStack[i]));
        layout->addWidget(label);
    }

    window.setLayout(layout);
    window.show();

    return app.exec();
}
