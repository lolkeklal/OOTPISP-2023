#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSpinBox>
#include <QSlider>
#include <QPlainTextEdit>
#include <QGridLayout>
#include <QLabel>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаем элементы
    redSpinBox = new QSpinBox(this);
    redSlider = new QSlider(Qt::Horizontal, this);
    greenSpinBox = new QSpinBox(this);
    greenSlider = new QSlider(Qt::Horizontal, this);
    blueSpinBox = new QSpinBox(this);
    blueSlider = new QSlider(Qt::Horizontal, this);
    textEdit = new QPlainTextEdit("", this);

    // Устанавливаем диапазон значений для SpinBox и Slider
    redSpinBox->setRange(0, 255);
    greenSpinBox->setRange(0, 255);
    blueSpinBox->setRange(0, 255);

    redSlider->setRange(0, 255);
    greenSlider->setRange(0, 255);
    blueSlider->setRange(0, 255);

    // Подключаем сигналы к слотам
    connect(redSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setRed(int)));
    connect(redSlider, SIGNAL(valueChanged(int)), this, SLOT(setRed(int)));

    connect(greenSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setGreen(int)));
    connect(greenSlider, SIGNAL(valueChanged(int)), this, SLOT(setGreen(int)));

    connect(blueSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setBlue(int)));
    connect(blueSlider, SIGNAL(valueChanged(int)), this, SLOT(setBlue(int)));

    // Создаем компоновщик
    QGridLayout *layout = new QGridLayout(ui->centralwidget);

    // Добавляем элементы на форму с пояснениями
    layout->addWidget(new QLabel("Red:", this), 0, 0);
    layout->addWidget(redSpinBox, 0, 1);
    layout->addWidget(redSlider, 0, 2);

    layout->addWidget(new QLabel("Green:", this), 1, 0);
    layout->addWidget(greenSpinBox, 1, 1);
    layout->addWidget(greenSlider, 1, 2);

    layout->addWidget(new QLabel("Blue:", this), 2, 0);
    layout->addWidget(blueSpinBox, 2, 1);
    layout->addWidget(blueSlider, 2, 2);

    layout->addWidget(textEdit, 3, 0, 1, 3);

    // Добавляем кнопку "Open File"
    QPushButton *openButton = new QPushButton("Open File", this);
    layout->addWidget(openButton, 4, 0, 1, 3);

    // Подключаем сигнал от кнопки к слоту открытия файла
    connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRed(int value)
{
    redSpinBox->setValue(value);
    redSlider->setValue(value);
    setColor();
}

void MainWindow::setGreen(int value)
{
    greenSpinBox->setValue(value);
    greenSlider->setValue(value);
    setColor();
}

void MainWindow::setBlue(int value)
{
    blueSpinBox->setValue(value);
    blueSlider->setValue(value);
    setColor();
}

void MainWindow::setColor()
{
    // Получаем значения компонентов RGB
    int red = redSpinBox->value();
    int green = greenSpinBox->value();
    int blue = blueSpinBox->value();

    // Обновляем стиль текстового поля с цветом
    QString style = QString("QPlainTextEdit { background: #%1%2%3; }")
                        .arg(red, 2, 16, QChar('0'))
                        .arg(green, 2, 16, QChar('0'))
                        .arg(blue, 2, 16, QChar('0'));

    textEdit->setStyleSheet(style);
}

void MainWindow::openFile()
{
    // Открываем диалог выбора файла
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");

    // Проверяем, был ли выбран файл
    if (!filePath.isEmpty())
    {
        // Открываем файл
        QFile file(filePath);

        // Проверяем, удалось ли открыть файл
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            // Читаем содержимое файла
            QTextStream in(&file);
            QString fileContent = in.readAll();

            // Закрываем файл
            file.close();

            // Создаем новое диалоговое окно для вывода текста файла
            QDialog *fileDialog = new QDialog(this);
            QVBoxLayout *dialogLayout = new QVBoxLayout(fileDialog);

            QPlainTextEdit *fileViewer = new QPlainTextEdit(fileContent, fileDialog);
            dialogLayout->addWidget(fileViewer);

            fileDialog->setWindowTitle(filePath);
            fileDialog->exec();
        }
    }
}
