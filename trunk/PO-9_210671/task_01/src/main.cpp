#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QTextEdit>
#include <QGridLayout>
#include <QFileDialog>

int main(int argc, char **argv) {
////
    QApplication app(argc, argv);

    // 1 Widget
    QWidget colorWidget(0);
    QGridLayout colorLayout;
    colorWidget.setLayout(&colorLayout);

    // Создание элементов интерфейса
    QSpinBox redSpinBox, greenSpinBox, blueSpinBox;
    QLabel redLabel, greenLabel, blueLabel;
    QSlider redSlider(Qt::Horizontal), greenSlider(Qt::Horizontal), blueSlider(Qt::Horizontal);
    QTextEdit colorPreview;

    // Установка меток для компонентов управления цветом
    redLabel.setText("Red");
    greenLabel.setText("Green");
    blueLabel.setText("Blue");

    // Расположение элементов в сетке
    colorLayout.addWidget(&redLabel, 0, 0);
    colorLayout.addWidget(&redSpinBox, 0, 1);
    colorLayout.addWidget(&redSlider, 0, 2);

    colorLayout.addWidget(&greenLabel, 1, 0);
    colorLayout.addWidget(&greenSpinBox, 1, 1);
    colorLayout.addWidget(&greenSlider, 1, 2);

    colorLayout.addWidget(&blueLabel, 2, 0);
    colorLayout.addWidget(&blueSpinBox, 2, 1);
    colorLayout.addWidget(&blueSlider, 2, 2);

    colorLayout.addWidget(&colorPreview, 0, 3, 3, 1);

    // Установка диапазонов значений для компонентов управления цветом
    redSpinBox.setMinimum(0);
    redSpinBox.setMaximum(255);
    redSlider.setMinimum(0);
    redSlider.setMaximum(255);

    greenSpinBox.setMinimum(0);
    greenSpinBox.setMaximum(255);
    greenSlider.setMinimum(0);
    greenSlider.setMaximum(255);

    blueSpinBox.setMinimum(0);
    blueSpinBox.setMaximum(255);
    blueSlider.setMinimum(0);
    blueSlider.setMaximum(255);

    // Установка стилей для элементов интерфейса
    colorWidget.setStyleSheet("QWidget { background-color: lightgray; }"
                              "QLabel { color: blue; font-size: 20px; }"
                              "QSpinBox, QSlider { background-color: white; }"
                              "QTextEdit { background-color: lightblue; }"
                              "QPushButton { color: white; background-color: #4CAF50; border: none; padding: 10px; }"
                              "QPushButton:hover { background-color: #45a049; }");

    colorPreview.setEnabled(false);

    // Лямбда-функция для установки цвета фона текстового поля
    auto setColor = [&]() {
        int red = redSpinBox.value();
        int green = greenSpinBox.value();
        int blue = blueSpinBox.value();
        QString styleSheet = QString("background-color: rgb(%1, %2, %3);")
                                 .arg(red)
                                 .arg(green)
                                 .arg(blue);
        colorPreview.setStyleSheet(styleSheet);
    };

    // Соединение сигналов и слотов для обновления цвета фона текстового поля
    QObject::connect(&redSlider, &QSlider::valueChanged, &redSpinBox, &QSpinBox::setValue);
    QObject::connect(&redSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), &redSlider, &QSlider::setValue);
    QObject::connect(&redSlider, &QSlider::valueChanged, setColor);

    QObject::connect(&greenSlider, &QSlider::valueChanged, &greenSpinBox, &QSpinBox::setValue);
    QObject::connect(&greenSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), &greenSlider, &QSlider::setValue);
    QObject::connect(&greenSlider, &QSlider::valueChanged, setColor);

    QObject::connect(&blueSlider, &QSlider::valueChanged, &blueSpinBox, &QSpinBox::setValue);
    QObject::connect(&blueSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), &blueSlider, &QSlider::setValue);
    QObject::connect(&blueSlider, &QSlider::valueChanged, setColor);

    // Отображение первого виджета с измененным заголовком
    colorWidget.setWindowTitle("Your color!");
    colorWidget.resize(500, 300);
    colorWidget.show();

    // 2 Widget
    QWidget fileWidget(0);
    QGridLayout fileLayout;
    fileWidget.setLayout(&fileLayout);

    QTextEdit fileViewer;
    QPushButton openFileButton("Выбрать файл");

    // Добавление элементов интерфейса во второй виджет
    fileLayout.addWidget(&fileViewer);
    fileLayout.addWidget(&openFileButton);

    // Лямбда-функция для открытия файла
    auto openFile = [&]() {
        QString filePath = QFileDialog::getOpenFileName(&fileWidget, "Выберите файл", "Example.txt", "Текстовые файлы (*.txt)");
        if (!filePath.isEmpty()) {
            QFile file(filePath);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                QString fileContents = in.readAll();
                file.close();
                fileViewer.setPlainText(fileContents);
            } else {
                fileViewer.setPlainText("Ошибка открытия файла: " + file.errorString());
            }
        }
    };

    // Соединение сигнала нажатия кнопки с функцией открытия файла
    QObject::connect(&openFileButton, &QPushButton::clicked, openFile);

    // Отображение второго виджета
    fileWidget.setWindowTitle("FileViewer");
    fileWidget.resize(500, 300);
    fileWidget.show();

    return app.exec();
}
