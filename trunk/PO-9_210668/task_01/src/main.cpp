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

    QApplication app(argc, argv);

    //1 Widget
    QWidget widget(0);
    QGridLayout grid_layout;
    widget.setLayout(&grid_layout);

    QSpinBox sbRed, sbGreen, sbBlue;
    QLabel sb_label1, sb_label2, sb_label3;
    QSlider slRed(Qt::Horizontal), slGreen(Qt::Horizontal), slBlue(Qt::Horizontal);
    QTextEdit text_edit;

    sb_label1.setText("Red");
    sb_label2.setText("Green");
    sb_label3.setText("Blue");

    //Структурирование
    grid_layout.addWidget(&sb_label1, 0, 0);
    grid_layout.addWidget(&sbRed, 0, 1);
    grid_layout.addWidget(&slRed, 0, 2);

    grid_layout.addWidget(&sb_label2, 1, 0);
    grid_layout.addWidget(&sbGreen, 1, 1);
    grid_layout.addWidget(&slGreen, 1, 2);

    grid_layout.addWidget(&sb_label3, 2, 0);
    grid_layout.addWidget(&sbBlue, 2, 1);
    grid_layout.addWidget(&slBlue, 2, 2);

    grid_layout.addWidget(&text_edit, 0, 3, 3, 1);

    //Установка границ значений
    sbRed.setMinimum(0);
    sbRed.setMaximum(255);
    slRed.setMinimum(0);
    slRed.setMaximum(255);

    sbGreen.setMinimum(0);
    sbGreen.setMaximum(255);
    slGreen.setMinimum(0);
    slGreen.setMaximum(255);

    sbBlue.setMinimum(0);
    sbBlue.setMaximum(255);
    slBlue.setMinimum(0);
    slBlue.setMaximum(255);

    text_edit.setEnabled(false);

    // Лямбда-функция для установки цвета фона текстового поля
    auto setColor = [&]() {
        int red = sbRed.value();
        int green = sbGreen.value();
        int blue = sbBlue.value();
        QString styleSheet = QString("background-color: rgb(%1, %2, %3);")
                                 .arg(red)
                                 .arg(green)
                                 .arg(blue);
        text_edit.setStyleSheet(styleSheet);
    };

    // Соединяем сигналы и слоты
    QObject::connect(&slRed, &QSlider::valueChanged, &sbRed, &QSpinBox::setValue);
    QObject::connect(&sbRed, &QSpinBox::valueChanged, &slRed, &QSlider::setValue);
    QObject::connect(&slRed, &QSlider::valueChanged, setColor);

    QObject::connect(&slGreen, &QSlider::valueChanged, &sbGreen, &QSpinBox::setValue);
    QObject::connect(&sbGreen, &QSpinBox::valueChanged, &slGreen, &QSlider::setValue);
    QObject::connect(&slGreen, &QSlider::valueChanged, setColor);

    QObject::connect(&slBlue, &QSlider::valueChanged, &sbBlue, &QSpinBox::setValue);
    QObject::connect(&sbBlue, &QSpinBox::valueChanged, &slBlue, &QSlider::setValue);
    QObject::connect(&slBlue, &QSlider::valueChanged, setColor);

    widget.setWindowTitle("Your color!");
    widget.resize(500, 200);
    widget.show();

    //2 Widget
    QWidget widgetFileViewer(0);
    QGridLayout grid_layout_FileViewer;
    widgetFileViewer.setLayout(&grid_layout_FileViewer);

    QTextEdit text_edit_FileViewer;
    QPushButton openButton("Выбрать файл");

    grid_layout_FileViewer.addWidget(&text_edit_FileViewer);
    grid_layout_FileViewer.addWidget(&openButton);

    auto openFile = [&](){
        QString filePath = QFileDialog::getOpenFileName(&widgetFileViewer, "Выберите файл", "Example.txt", "Текстовые файлы (*.txt)");
        if (!filePath.isEmpty())
        {
            QFile file(filePath);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&file);
                QString fileContents = in.readAll();
                file.close();
                text_edit_FileViewer.setPlainText(fileContents);
            }
            else
            {
                text_edit_FileViewer.setPlainText("Ошибка открытия файла: " + file.errorString());
            }
        }

    };

    QObject::connect(&openButton, QPushButton::clicked, openFile);

    widgetFileViewer.setWindowTitle("FileViewer");
    widgetFileViewer.resize(500, 200);
    widgetFileViewer.show();

    return app.exec();
}

