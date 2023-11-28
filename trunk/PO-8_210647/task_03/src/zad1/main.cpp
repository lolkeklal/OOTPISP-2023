#include "mainwindow.h"
#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setGeometry(100, 100, 300, 200);

    QVBoxLayout *layout = new QVBoxLayout(&window); //1

    QLineEdit* lineEditA = new QLineEdit(&window);
    layout->addWidget(lineEditA);

    QLineEdit* lineEditB = new QLineEdit(&window);
    layout->addWidget(lineEditB);

    QPushButton* button = new QPushButton("Calculate", &window);
    layout->addWidget(button);

    QLabel* labelA = new QLabel(&window);
    layout->addWidget(labelA);

    QLabel* labelB = new QLabel(&window);
    layout->addWidget(labelB);

    QObject::connect(button, &QPushButton::clicked, &window, [=]() {
        bool successA, successB;
        int A = lineEditA->text().toInt(&successA);
        int B = lineEditB->text().toInt(&successB);

        if (successA && successB) {
            if (A != B) {
                A = A + B;
                B = A;
            } else {
                A = 0;
                B = 0;
            }
            labelA->setText("A: " + QString::number(A));
            labelB->setText("B: " + QString::number(B));
        } else {
            labelA->setText("Invalid input");
            labelB->setText("");
        }
    });

    window.setLayout(layout);
    window.show();
    return app.exec();
}



