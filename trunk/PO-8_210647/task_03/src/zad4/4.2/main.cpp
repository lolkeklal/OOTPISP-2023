#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QQueue>
#include <random>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;
    window.setWindowTitle("Решение задачи");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QQueue<int> myQueue;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-20, 50);

    // Зaполнение очереди 8 случайными числaми из интервала [-20; 50]
    for (int i = 0; i < 8; ++i) {
        int randomNum = dis(gen);
        myQueue.enqueue(randomNum);
        QLabel *queueElement = new QLabel("Элемент " + QString::number(i + 1) + ": " + QString::number(randomNum));
        layout->addWidget(queueElement);
    }

    // Нaхождение среднего aрифметического двух соседних элементов очереди и помещение результата в очередь
    for (int i = 0; i < myQueue.size() - 1; ++i) {
        int average = (myQueue[i] + myQueue[i + 1]) / 2;
        myQueue.enqueue(average);
        QLabel *queueAverage = new QLabel("Среднее арифметическое " + QString::number(i + 1) + " и " + QString::number(i + 2) + ": " + QString::number(average));
        layout->addWidget(queueAverage);
    }

    window.setLayout(layout);
    window.show();
    return a.exec();
}
