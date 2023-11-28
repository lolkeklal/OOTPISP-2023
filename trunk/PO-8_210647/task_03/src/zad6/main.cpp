#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QLabel>

void filterFile(QStringList &lines, QString path, QString condition) {
    QFile inputFile(path); //1
    if (inputFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&inputFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            bool ok;
            int num = line.toInt(&ok);
            if (ok) {
                if (condition == "even" && num % 2 == 0) {
                    lines.append(line);
                } else if (condition == "divisibleBy3NotBy7" && num % 3 == 0 && num % 7 != 0) {
                    lines.append(line);
                } else if (condition == "perfectSquare") {
                    int squareRoot = int(sqrt(num));
                    if (squareRoot * squareRoot == num) {
                        lines.append(line);
                    }
                }
            }
        }
        inputFile.close();
    }
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;
    window.setWindowTitle("Фильтрация файла");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QPushButton *openFileButton = new QPushButton("Выбрать файл");
    layout->addWidget(openFileButton);

    QLabel *evenLabel = new QLabel("Четные числа: ");
    layout->addWidget(evenLabel);

    QLabel *divisibleBy3NotBy7Label = new QLabel("Числа, делящиеся на 3 и не делящиеся на 7: ");
    layout->addWidget(divisibleBy3NotBy7Label);

    QLabel *perfectSquareLabel = new QLabel("Точные квадраты: ");
    layout->addWidget(perfectSquareLabel);

    QObject::connect(openFileButton, &QPushButton::clicked, [&]() {
        QString fileName = QFileDialog::getOpenFileName(&window, "Выбрать файл", "", "Text Files (*.txt)");
        if (fileName != "") {
            QStringList evenLines;
            QStringList divisibleBy3NotBy7Lines;
            QStringList perfectSquareLines;

            filterFile(evenLines, fileName, "even");
            filterFile(divisibleBy3NotBy7Lines, fileName, "divisibleBy3NotBy7");
            filterFile(perfectSquareLines, fileName, "perfectSquare");

            evenLabel->setText("Четные числа: " + evenLines.join(", "));
            divisibleBy3NotBy7Label->setText("Числа, делящиеся на 3 и не делящиеся на 7: " + divisibleBy3NotBy7Lines.join(", "));
            perfectSquareLabel->setText("Точные квадраты: " + perfectSquareLines.join(", "));
        }
    });

    window.setLayout(layout);
    window.show();
    return a.exec();
}
