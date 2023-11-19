#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QTextEdit>
#include <QGridLayout>
#include <QFileDialog>

class ColorChanger : public QWidget {
public:
    explicit ColorChanger(QWidget *parent = nullptr) : QWidget(parent) {
        QGridLayout *gridLayout = new QGridLayout(this);

        SbRed.setMinimum(0);
        SbRed.setMaximum(255);
        sRed.setMinimum(0);
        sRed.setMaximum(255);

        SbGreen.setMinimum(0);
        SbGreen.setMaximum(255);
        sGreen.setMinimum(0);
        sGreen.setMaximum(255);

        SbBlue.setMinimum(0);
        SbBlue.setMaximum(255);
        sBlue.setMinimum(0);
        sBlue.setMaximum(255);

        textEdit.setEnabled(false);

        SbRed.setValue(0);
        SbGreen.setValue(0);
        SbBlue.setValue(0);

        Label1.setText("Red");
        Label2.setText("Green");
        Label3.setText("Blue");

        gridLayout->addWidget(&Label1, 0, 0);
        gridLayout->addWidget(&SbRed, 0, 1);
        gridLayout->addWidget(&sRed, 0, 2);

        gridLayout->addWidget(&Label2, 1, 0);
        gridLayout->addWidget(&SbGreen, 1, 1);
        gridLayout->addWidget(&sGreen, 1, 2);

        gridLayout->addWidget(&Label3, 2, 0);
        gridLayout->addWidget(&SbBlue, 2, 1);
        gridLayout->addWidget(&sBlue, 2, 2);

        gridLayout->addWidget(&textEdit, 0, 3, 3, 1);

        QObject::connect(&sRed, &QSlider::valueChanged, &SbRed, &QSpinBox::setValue);
        QObject::connect(&SbRed, &QSpinBox::valueChanged, &sRed, &QSlider::setValue);
        QObject::connect(&sRed, &QSlider::valueChanged, this, &ColorChanger::updateColor);

        QObject::connect(&sGreen, &QSlider::valueChanged, &SbGreen, &QSpinBox::setValue);
        QObject::connect(&SbGreen, &QSpinBox::valueChanged, &sGreen, &QSlider::setValue);
        QObject::connect(&sGreen, &QSlider::valueChanged, this, &ColorChanger::updateColor);

        QObject::connect(&sBlue, &QSlider::valueChanged, &SbBlue, &QSpinBox::setValue);
        QObject::connect(&SbBlue, &QSpinBox::valueChanged, &sBlue, &QSlider::setValue);
        QObject::connect(&sBlue, &QSlider::valueChanged, this, &ColorChanger::updateColor);
        updateColor();
    }

private:
    QSpinBox SbRed, SbGreen, SbBlue;
    QLabel Label1, Label2, Label3;
    QSlider sRed{Qt::Horizontal}, sGreen{Qt::Horizontal}, sBlue{Qt::Horizontal};
    QTextEdit textEdit;

    void updateColor() {
        int red = SbRed.value();
        int green = SbGreen.value();
        int blue = SbBlue.value();
        QString styleSheet = QString("background-color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue);
        textEdit.setStyleSheet(styleSheet);
    }
};

int main(int argc, char **argv) {
QApplication app(argc, argv);

    // Создание основного виджета
    QWidget mainWidget;
    QVBoxLayout *layout = new QVBoxLayout(&mainWidget);

    // Создание экземпляра ColorChanger
    ColorChanger colorChanger;
    layout->addWidget(&colorChanger);

    // Создание виджетов для открытия и отображения файла
    QWidget fileViewerWidget;
    QGridLayout *fileViewerLayout = new QGridLayout(&fileViewerWidget);
    QTextEdit textEditFileViewer;
    QPushButton openButton("Выбрать файл");

    fileViewerLayout->addWidget(&textEditFileViewer, 0, 0, 1, 2);
    fileViewerLayout->addWidget(&openButton, 1, 0, 1, 2);

    fileViewerWidget.setWindowTitle("FileViewer");
    fileViewerWidget.resize(500, 200);

    // Соединение кнопки открытия файла с функцией openFile
    QObject::connect(&openButton, &QPushButton::clicked, [&](){
        QString filePath = QFileDialog::getOpenFileName(&fileViewerWidget, "Выберите файл", "Example.txt", "Текстовые файлы (*.txt)");
        if (!filePath.isEmpty()) {
            QFile file(filePath);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                QString fileContents = in.readAll();
                file.close();
                textEditFileViewer.setPlainText(fileContents);
            } else {
                textEditFileViewer.setPlainText("Ошибка открытия: " + file.errorString());
            }
        }
    });

    // Добавление окна просмотра файла в основное окно
    layout->addWidget(&fileViewerWidget);

    mainWidget.show();
    return app.exec();
}
