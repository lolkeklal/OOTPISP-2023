#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    redLabel = new QLabel("Red:");
    greenLabel = new QLabel("Green:");
    blueLabel = new QLabel("Blue:");

    redSpinBox = new QSpinBox();
    redSlider = new QSlider(Qt::Horizontal);
    redSpinBox->setMinimum(0);
    redSpinBox->setMaximum(255);
    redSlider->setMinimum(0);
    redSlider->setMaximum(255);

    greenSpinBox = new QSpinBox();
    greenSlider = new QSlider(Qt::Horizontal);
    greenSpinBox->setMinimum(0);
    greenSpinBox->setMaximum(255);
    greenSlider->setMinimum(0);
    greenSlider->setMaximum(255);

    blueSpinBox = new QSpinBox();
    blueSlider = new QSlider(Qt::Horizontal);
    blueSpinBox->setMinimum(0);
    blueSpinBox->setMaximum(255);
    blueSlider->setMinimum(0);
    blueSlider->setMaximum(255);

    colorPreviewTextEdit = new QPlainTextEdit();
    colorPreviewTextEdit->setFixedSize(100, 150);
    colorPreviewTextEdit->setEnabled(false);

    mainGridLayout = new QGridLayout();
    mainGridLayout->addWidget(redLabel, 0, 0);
    mainGridLayout->addWidget(redSpinBox, 0, 1);
    mainGridLayout->addWidget(redSlider, 0, 2);
    mainGridLayout->addWidget(greenLabel, 1, 0);
    mainGridLayout->addWidget(greenSpinBox, 1, 1);
    mainGridLayout->addWidget(greenSlider, 1, 2);
    mainGridLayout->addWidget(blueLabel, 2, 0);
    mainGridLayout->addWidget(blueSpinBox, 2, 1);
    mainGridLayout->addWidget(blueSlider, 2, 2);
    mainGridLayout->addWidget(colorPreviewTextEdit, 0, 3, 3, 1);

    connect(redSlider, &QSlider::valueChanged, this, &MainWindow::setRedValue);
    connect(greenSlider, &QSlider::valueChanged, this, &MainWindow::setGreenValue);
    connect(blueSlider, &QSlider::valueChanged, this, &MainWindow::setBlueValue);

    connect(redSpinBox, &QSpinBox::valueChanged, this, &MainWindow::setRedValue);
    connect(greenSpinBox, &QSpinBox::valueChanged, this, &MainWindow::setGreenValue);
    connect(blueSpinBox, &QSpinBox::valueChanged, this, &MainWindow::setBlueValue);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(mainGridLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateColorPreview() {
    int red = redSpinBox->value();
    int green = greenSpinBox->value();
    int blue = blueSpinBox->value();

    QColor color(red, green, blue);
    QPalette palette = colorPreviewTextEdit->palette();
    palette.setColor(QPalette::Base, color);
    colorPreviewTextEdit->setPalette(palette);

    redSlider->setValue(red);
    greenSlider->setValue(green);
    blueSlider->setValue(blue);
}

void MainWindow::setRedValue(int value) {
    redSpinBox->setValue(value);
    updateColorPreview();
}

void MainWindow::setGreenValue(int value) {
    greenSpinBox->setValue(value);
    updateColorPreview();
}

void MainWindow::setBlueValue(int value) {
    blueSpinBox->setValue(value);
    updateColorPreview();
}
