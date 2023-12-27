#include "mainwindow.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>
#include <random>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Удаление элементов из списка");

    QHBoxLayout *layout = new QHBoxLayout(&window);

    QLabel *labelN = new QLabel("Начальная позиция (N):");
    QSpinBox *spinBoxN = new QSpinBox();
    spinBoxN->setRange(0, 100);
    spinBoxN->setValue(0);

    QLabel *labelK = new QLabel("Конечная позиция (K):");
    QSpinBox *spinBoxK = new QSpinBox();
    spinBoxK->setRange(0, 100);
    spinBoxK->setValue(0);

    QPushButton *button = new QPushButton("Удалить элементы");

    QLabel *resultLabel = new QLabel();

    layout->addWidget(labelN);
    layout->addWidget(spinBoxN);
    layout->addWidget(labelK);
    layout->addWidget(spinBoxK);
    layout->addWidget(button);
    layout->addWidget(resultLabel);

    QObject::connect(button, &QPushButton::clicked, [=]() {
        int N = spinBoxN->value();
        int K = spinBoxK->value();

        std::list<int> myList;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 10);

        //Заполнение списка случайными элементами
       for (int i = 0; i < 10; ++i) {
           myList.push_back(dis(gen));
        }

        // Удаление элементов с позиций с N по K
        auto it = std::next(myList.begin(), N);
        auto itEnd = std::next(myList.begin(), K + 1);
        myList.erase(it, itEnd);

        // Обновление метки с результатом
        QString resultText = "Список после удаления:\n";
        for (auto const &item : myList) {
            resultText += QString::number(item) + " ";
        }
        resultLabel->setText(resultText);
    });


    window.setLayout(layout);
    window.show();

    return app.exec();
}
