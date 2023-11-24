#include <QApplication>
#include <QMainWindow>
#include <QTextStream>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
#include <QMessageBox>
#include <QListWidget>
#include <QInputDialog>
#include <QRandomGenerator>
#include <QStack>
#include <QQueue>
#include <QStringList>
#include <QFile>
#include <QFileDialog>

#include <iostream>

void task1()
{
    //Перераспределить значения переменных X и Y (переменные вводятся в lineedit ) так, чтобы в X оказалось меньшее из этих значений, а в Y − большее.
    QWidget *w = new QWidget;

    QVBoxLayout* layout = new QVBoxLayout(w);
    QLineEdit *lineEditX = new QLineEdit;
    QLineEdit *lineEditY = new QLineEdit;
    QPushButton *button = new QPushButton("&Перераспределить");

    layout->addWidget(new QLabel("Введите значения X и Y:"));
    layout->addWidget(new QLabel("X:"));
    layout->addWidget(lineEditX);
    layout->addWidget(new QLabel("Y:"));
    layout->addWidget(lineEditY);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, w, [=]{
        int x = lineEditX->text().toInt();
        int y = lineEditY->text().toInt();

        if (x > y)
            std::swap(x, y);

        QMessageBox::information(w, "Результат", QString("X: %1, Y: %2").arg(x).arg(y));
    });


    w->show();
}

void task2()
{
    //Дана матрица размера m x n. В каждой строке найти количество элементов, больших среднего арифметического всех элементов этой строки.
    const int rows = 3;
    const int cols = 4;

    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);

    QTableWidget *tableWidget = new QTableWidget(rows, cols);
    QPushButton *calculateButton = new QPushButton("Подсчитать");
    QLabel *resultLabel = new QLabel("Результат:");

    layout->addWidget(tableWidget);
    layout->addWidget(calculateButton);
    layout->addWidget(resultLabel);

    QObject::connect(calculateButton, &QPushButton::clicked, widget, [=]() {
        QString result;
        for (int row = 0; row < rows; ++row) {
            int sum = 0;
            int countGreater = 0;

            for (int col = 0; col < cols; ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                if (!item) continue;

                int value = item->text().toInt();
                sum += value;
            }

            double avg = static_cast<double>(sum) / cols;

            for (int col = 0; col < cols; ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                if (!item) continue;

                int value = item->text().toInt();
                if (value > avg) {
                    countGreater++;
                }
            }

            result += QString("В строке %1 элементов больше среднего: %2\n").arg(row + 1).arg(countGreater);
        }

        resultLabel->setText(result); // Вывод результатов в QLabel
    });

    // Для демонстрации добавления случайных значений в таблицу (может быть заменено на ваш метод ввода)
    srand(time(nullptr));
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int value = rand() % 100; // Генерация случайных чисел от 0 до 99
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(value));
            tableWidget->setItem(row, col, item);
        }
    }

    widget->show();
}

void task3()
{
    //Заполнить список случайными элементами и реализовать удаление элементов с позиций с N по K.
    //Заполнить связный список случайными элементами и отсортировать их по убыванию.
    const int itemCount = 30; // Количество элементов в списке

    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);

    QListWidget *listWidget = new QListWidget();
    QPushButton *removeButton = new QPushButton("Удалить элементы с N по K");
    QPushButton *sortButton = new QPushButton("Отсортировать по убыванию");

    layout->addWidget(listWidget);
    layout->addWidget(removeButton);
    layout->addWidget(sortButton);

    // Заполнение списка случайными элементами
    for (int i = 0; i < itemCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(100); // Случайные числа от 0 до 99
        listWidget->addItem(QString::number(randomValue));
    }

QObject::connect(removeButton, &QPushButton::clicked, widget, [=]() {
        bool ok1, ok2;
        int start = QInputDialog::getInt(widget, "Введите N", "N:", 0, 0, listWidget->count() - 1, 1, &ok1);
        int end = QInputDialog::getInt(widget, "Введите K", "K:", listWidget->count() - 1, 0, listWidget->count() - 1, 1, &ok2);

        if (ok1 && ok2) {
            while (end >= start && end < listWidget->count()) {
                QListWidgetItem *item = listWidget->takeItem(start); // Удаление элемента
                delete item;
                ++end;
            }
        }
    });

    QObject::connect(sortButton, &QPushButton::clicked, widget, [=]() {
        QList<int> values;

        for (int i = 0; i < listWidget->count(); ++i) {
            values << listWidget->item(i)->text().toInt();
        }

        std::sort(values.begin(), values.end(), std::greater<int>()); // Сортировка по убыванию

        listWidget->clear(); // Очистка списка

        for (const auto &value : values) {
            listWidget->addItem(QString::number(value)); // Добавление отсортированных элементов
        }
    });

    widget->show();
}

void task4()
{
    //Сформировать стек из 8 чисел. Заменить значение первого элемента стека произведением первого и последнего, значение второго элемента стека − произведением второго и предпоследнего и т.д.
    //Заполнить очередь 8 случайными числами из интервала [-20; 50]. Найти среднее арифметическое значений двух соседних элементов очереди. Результат поместить в очередь.
    QWidget *widget = new QWidget;

    QVBoxLayout *layout = new QVBoxLayout(widget);

    QLabel *stackLabel1 = new QLabel("Стек до замены значений:");
    QStack<int> myStack;
    myStack << rand() % 100 << rand() % 100 << rand() % 100 << rand() % 100 << rand() % 100 << rand() % 100 << rand() % 100 << rand() % 100;

    layout->addWidget(stackLabel1);
    for (int i = 0; i < myStack.size(); ++i) {
        QLabel *label = new QLabel(QString::number(myStack[i]));
        layout->addWidget(label);
    }

    QStack<int> newStack;
    for (int i = 0; i < myStack.size(); ++i) {
        newStack << myStack[i] * myStack[myStack.size() - 1 - i];
    }

    QLabel *stackLabel = new QLabel("Стек после замены значений:");
    layout->addWidget(stackLabel);

    while (!newStack.isEmpty()) {
        QLabel *label = new QLabel(QString::number(newStack.top()));
        layout->addWidget(label);
        newStack.pop();
    }

    // Создание очереди и заполнение случайными числами
    QQueue<int> myQueue;
    srand(time(NULL)); // Инициализация генератора случайных чисел
    for (int i = 0; i < 8; ++i) {
        int randomNumber = rand() % 71 - 20; // Генерация чисел в интервале [-20; 50]
        myQueue.enqueue(randomNumber);
    }

    QLabel *queueLabel1 = new QLabel("Очередь случайных чисел:");
    layout->addWidget(queueLabel1);

    // Вывод первоначальной очереди
    for (int i = 0; i < myQueue.size(); ++i) {
        QLabel *label = new QLabel(QString::number(myQueue[i]));
        layout->addWidget(label);
    }

    // Нахождение среднего арифметического и добавление его в очередь
    QQueue<double> averageQueue;
    for (int i = 0; i < myQueue.size() - 1; ++i) {
        double average = (myQueue[i] + myQueue[i + 1]) / 2.0;
        averageQueue.enqueue(average);
    }

    QLabel *queueLabel2 = new QLabel("Очередь средних значений:");
    layout->addWidget(queueLabel2);

    // Вывод очереди со средними значениями
    while (!averageQueue.isEmpty()) {
        QLabel *label = new QLabel(QString::number(averageQueue.head()));
        layout->addWidget(label);
        averageQueue.dequeue();
    }


    widget->show();
}

void task5()
{
    //Известны марки машин, изготовляемых в данной стране и импортируемых за рубеж. Даны некоторые N стран. Определить для каждой из марок, какие из них были доставлены во все страны, доставлены в некоторые из стран, не доставлены ни в одну страну.
    QMap<QString, QStringList> cars = {
        {"Toyota", {"USA", "Canada", "Japan", "Germany", "Mexico"}},
        {"Lada", {}},
        {"Ford", {"USA", "Canada"}},
        {"Chevrolet", {"USA", "Canada", "Mexico"}},
        {"Hyundai", {"USA"}}
    };

    QStringList allCountries;
    QStringList someCountries;
    QStringList noCountries;

    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);

    for (auto it = cars.begin(); it != cars.end(); ++it) {
        const QString &car = it.key();
        const QStringList &countries = it.value();

        QLabel *labelCar = new QLabel("Марка: " + car);
        layout->addWidget(labelCar);

        QLabel *labelCountries = new QLabel("Доставлена в страны: " + countries.join(", "));
        layout->addWidget(labelCountries);

        layout->addSpacing(1);
    }

    for (auto it = cars.begin(); it != cars.end(); ++it) {
        const QStringList &countries = it.value();

        if (countries.size() == static_cast<int>(cars.size())) {
            allCountries << it.key();
        }
        else if (countries.size() > 0) {
            someCountries << it.key();
        }
        else {
            noCountries << it.key();
        }
    }

    QLabel *labelAllCars = new QLabel("Марки автомобилей, доставленные во все страны: " + allCountries.join(", "));
    QLabel *labelSomeCars = new QLabel("Марки автомобилей, доставленные в некоторые страны: " + someCountries.join(", "));
    QLabel *labelNoCars = new QLabel("Марки автомобилей, не доставленные ни в одну страну: " + noCountries.join(", "));

    layout->addWidget(labelAllCars);
    layout->addWidget(labelSomeCars);
    layout->addWidget(labelNoCars);

    widget->setLayout(layout);
    widget->show();

}

void filterFile(const QString &inputFileName, const QString &outputFileName) {
    // Открытие файла для чтения
    QFile inputFile(inputFileName);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл для чтения";
        return;
    }

    // Чтение чисел из файла в вектор
    QVector<int> numbers;
    QTextStream inStream(&inputFile);
    while (!inStream.atEnd()) {
        QString line = inStream.readLine();
        QStringList tokens = line.split(" ", Qt::SkipEmptyParts);
        for (const QString& token : tokens) {
            bool ok;
            int num = token.toInt(&ok);
            if (ok) {
                numbers.append(num);
            }
        }
    }
    inputFile.close();

    // Открытие файла для записи
    QFile outputFile(outputFileName);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл для записи";
        return;
    }

    QTextStream outStream(&outputFile);

    // Фильтрация чисел по заданным условиям и запись в файл
    for (int num : numbers) {
        // а) Четные числа
        if (num % 2 == 0) {
            outStream << num << " (четное)\n";
        }

        // б) Делящиеся на 3 и не делящиеся на 7
        if (num % 3 == 0 && num % 7 != 0) {
            outStream << num << " (делящееся на 3, но не на 7)\n";
        }

        // в) Точные квадраты
        int sqrtNum = sqrt(num);
        if (sqrtNum * sqrtNum == num) {
            outStream << num << " (точный квадрат)\n";
        }
    }

    outputFile.close();
}

void task6() {
    QWidget *w = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(w);

    QPushButton *selectInputFileButton = new QPushButton("Выбрать входной файл");
    QPushButton *selectOutputFileButton = new QPushButton("Выбрать выходной файл");
    QLabel *inputFilePathLabel = new QLabel("Выбранный входной файл:");
    QLabel *outputFilePathLabel = new QLabel("Выбранный выходной файл:");
    QPushButton *processButton = new QPushButton("Обработать файлы");

    layout->addWidget(selectInputFileButton);
    layout->addWidget(inputFilePathLabel);
    layout->addWidget(selectOutputFileButton);
    layout->addWidget(outputFilePathLabel);
    layout->addWidget(processButton);

    QObject::connect(selectInputFileButton, &QPushButton::clicked, w, [=]() {
        QString inputFileName = QFileDialog::getOpenFileName(nullptr, "Выберите входной файл", "", "Text Files (*.txt)");
        if (!inputFileName.isEmpty()) {
            inputFilePathLabel->setText("Выбранный входной файл: " + inputFileName);
        }
    });

    QObject::connect(selectOutputFileButton, &QPushButton::clicked, w, [=]() {
        QString outputFileName = QFileDialog::getSaveFileName(nullptr, "Выберите выходной файл", "", "Text Files (*.txt)");
        if (!outputFileName.isEmpty()) {
            outputFilePathLabel->setText("Выбранный выходной файл: " + outputFileName);
        }
    });

    QObject::connect(processButton, &QPushButton::clicked, w, [=]() {
        QString inputFileName = inputFilePathLabel->text().remove("Выбранный входной файл: ");
        QString outputFileName = outputFilePathLabel->text().remove("Выбранный выходной файл: ");

        if (!inputFileName.isEmpty() && !outputFileName.isEmpty()) {
            filterFile(inputFileName, outputFileName);
            QMessageBox::information(nullptr, "Готово", "Файлы обработаны и записаны.");
        } else {
            QMessageBox::warning(nullptr, "Ошибка", "Выберите входной и выходной файлы.");
        }
    });

    w->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *window = new QWidget;

    QVBoxLayout* mainLayout = new QVBoxLayout(window);
    QLineEdit *line = new QLineEdit;

    QPushButton *button = new QPushButton("&Подтвердить");

    mainLayout->addWidget(new QLabel("Введите номер задания"));
    mainLayout->addWidget(line);
    mainLayout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, window,  [=]{
        bool ok;
        int number = line->text().toInt(&ok);
        if (ok) {
            switch (number) {
            case 1:task1();break;
            case 2:task2();break;
            case 3:task3();break;
            case 4:task4();break;
            case 5:task5();break;
            case 6:task6();break;
            default:QMessageBox::warning(window, "Ошибка", "Введите задание от 1 до 6)");break;
            }
        } else {
            QMessageBox::warning(window, "Ошибка", "Введите задание от 1 до 6");
        }
    });
    window->show();

    return a.exec();
}
