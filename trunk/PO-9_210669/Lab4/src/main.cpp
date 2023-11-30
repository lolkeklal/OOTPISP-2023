#include <QApplication>
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>

class NumberFinderApp : public QWidget {
    Q_OBJECT

public:
    NumberFinderApp(QWidget *parent = nullptr) : QWidget(parent) {
        // Создаем элементы управления
        tableWidget = new QTableWidget(10, 10, this);
        generateNumbers();

        QPushButton *findButton = new QPushButton("Найти числа", this);
        connect(findButton, &QPushButton::clicked, this, &NumberFinderApp::findNumbers);

        resultLabel = new QLabel("Результат: ", this);

        // Размещаем элементы управления в вертикальном layout
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(tableWidget);
        layout->addWidget(findButton);
        layout->addWidget(resultLabel);
    }

private slots:
    // Генерация случайных чисел в таблице
    void generateNumbers() {
        QTime time = QTime::currentTime();
        srand(static_cast<uint>(time.msec()));

        for (int row = 0; row < 10; ++row) {
            for (int col = 0; col < 10; ++col) {
                int randomNumber = rand() % 100 + 1;  // Генерация случайных чисел от 1 до 100
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(randomNumber));
                tableWidget->setItem(row, col, item);
            }
        }
    }

    // Поиск и подсветка чисел
    void findNumbers() {
        int count = 0;

        for (int row = 0; row < 10; ++row) {
            for (int col = 0; col < 10; ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                if (item) {
                    int number = item->text().toInt();

                    // Проверяем деление на 2, 3, 4, 5 и 6
                    if (number % 2 == 0 || number % 3 == 0 || number % 4 == 0 || number % 5 == 0 || number % 6 == 0) {
                        item->setBackground(Qt::green);
                        count++;
                    } else {
                        item->setBackground(Qt::white);
                    }
                }
            }
        }

        resultLabel->setText("Результат: Найдено " + QString::number(count) + " чисел");
    }

private:
    QTableWidget *tableWidget;
    QLabel *resultLabel;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    NumberFinderApp appWindow;
    appWindow.show();

    return app.exec();
}

#include "main.moc"

