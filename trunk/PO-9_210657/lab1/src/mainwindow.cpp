#include "mainwindow.h"
#include <QWidget>
#include <QColor>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    redLabel = new QLabel("Red");
    redSpinBox = new QSpinBox;
    redSpinBox->setMinimum(0);
    redSpinBox->setMaximum(255);
    redSlider = new QSlider(Qt::Horizontal);
    redSlider->setMinimum(0);
    redSlider->setMaximum(255);

    greenLabel = new QLabel("Green");
    greenSpinBox = new QSpinBox;
    greenSpinBox->setMinimum(0);
    greenSpinBox->setMaximum(255);
    greenSlider = new QSlider(Qt::Horizontal);
    greenSlider->setMinimum(0);
    greenSlider->setMaximum(255);

    blueLabel = new QLabel("Blue");
    blueSpinBox = new QSpinBox;
    blueSpinBox->setMinimum(0);
    blueSpinBox->setMaximum(255);
    blueSlider = new QSlider(Qt::Horizontal);
    blueSlider->setMinimum(0);
    blueSlider->setMaximum(255);

    colorDisplay = new QPlainTextEdit;
    colorDisplay->setEnabled(false);

    layout = new QGridLayout;

    layout->addWidget(redLabel, 0, 0); // row 0, column 0
    layout->addWidget(redSpinBox, 0, 1); // row 0, column 1
    layout->addWidget(redSlider, 0, 2); // row 0, column 2

    layout->addWidget(greenLabel, 1, 0); // row 1, column 0
    layout->addWidget(greenSpinBox, 1, 1); // row 1, column 1
    layout->addWidget(greenSlider, 1, 2); // row 1, column 2

    layout->addWidget(blueLabel, 2, 0); // row 2, column 0
    layout->addWidget(blueSpinBox, 2, 1); // row 2, column 1
    layout->addWidget(blueSlider, 2, 2); // row 2, column 2

    layout->addWidget(colorDisplay, 0, 3, 3, 1); // row 3, column 0, span 1 row and 3 columns

    openFileButton = new QPushButton("Open File");
    textEdit = new QTextEdit;

    layout->addWidget(openFileButton, 3, 0, 1, 3); // row 3, column 0, span 1 row and 3 columns
    layout->addWidget(textEdit, 4, 0, 1, 4);      // row 4, column 0, span 1 row and 4 columns


    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(redSlider, SIGNAL(sliderMoved(int)), this, SLOT(setRed(int)));
    connect(redSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setRed(int)));
    connect(greenSlider, SIGNAL(sliderMoved(int)), this, SLOT(setGreen(int)));
    connect(greenSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setGreen(int)));
    connect(blueSlider, SIGNAL(sliderMoved(int)), this, SLOT(setBlue(int)));
    connect(blueSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setBlue(int)));

    connect(openFileButton, SIGNAL(clicked()), this, SLOT(openFile()));

}

void MainWindow::setRed(int value) {
    redSpinBox->setValue(value);
    redSlider->setValue(value);
    setColor();
}

void MainWindow::setGreen(int value) {
    greenSpinBox->setValue(value);
    greenSlider->setValue(value);
    setColor();
}

void MainWindow::setBlue(int value) {
    blueSpinBox->setValue(value);
    blueSlider->setValue(value);
    setColor();
}

void MainWindow::setColor() {
    QColor color(redSpinBox->value(), greenSpinBox->value(), blueSpinBox->value());
    QString styleSheet = QString("QPlainTextEdit {background: %1}").arg(color.name());
    colorDisplay->setStyleSheet(styleSheet);
}

void MainWindow::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Text File"), "", tr("Text Files (*.txt);;All Files (*)"));

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString fileContent = in.readAll();
            textEdit->setPlainText(fileContent);
            file.close();
        }
    }
}

MainWindow::~MainWindow()
{
    delete redLabel;
    delete redSpinBox;
    delete redSlider;

    delete greenLabel;
    delete greenSpinBox;
    delete greenSlider;

    delete blueLabel;
    delete blueSpinBox;
    delete blueSlider;

    delete colorDisplay;
}

