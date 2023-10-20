#include "widget.h"
#include "./ui_widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setGeometry(800, 500, 500, 150);
    setWindowTitle("Color viewer");

    QGridLayout* mainLayout = new QGridLayout(this);

    redLabel.setText("Red");
    redSpinBox.setEnabled(false);
    redSpinBox.setMinimum(0);
    redSpinBox.setMaximum(255);
    redSpinBox.setMinimumSize(40, -1);
    redSlider.setOrientation(Qt::Horizontal);
    redSlider.setMinimum(0);
    redSlider.setMaximum(255);
    redSlider.setMinimumSize(100, -1);

    greenLabel.setText("Green");
    greenSpinBox.setEnabled(false);
    greenSpinBox.setMinimum(0);
    greenSpinBox.setMaximum(255);
    greenSpinBox.setMinimumSize(40, -1);
    greenSlider.setOrientation(Qt::Horizontal);
    greenSlider.setMinimum(0);
    greenSlider.setMaximum(255);
    greenSlider.setMinimumSize(100, -1);

    blueLabel.setText("Blue");
    blueSpinBox.setEnabled(false);
    blueSpinBox.setMinimum(0);
    blueSpinBox.setMaximum(255);
    blueSpinBox.setMinimumSize(40, -1);
    blueSlider.setOrientation(Qt::Horizontal);
    blueSlider.setMinimum(0);
    blueSlider.setMaximum(255);
    blueSlider.setMinimumSize(100, -1);

    mainLayout->addWidget(&redLabel, 0, 0);
    mainLayout->addWidget(&redSpinBox, 0, 1);
    mainLayout->addWidget(&redSlider, 0, 2);

    mainLayout->addWidget(&greenLabel, 1, 0);
    mainLayout->addWidget(&greenSpinBox, 1, 1);
    mainLayout->addWidget(&greenSlider, 1, 2);

    mainLayout->addWidget(&blueLabel, 2, 0);
    mainLayout->addWidget(&blueSpinBox, 2, 1);
    mainLayout->addWidget(&blueSlider, 2, 2);

    textEdit.setMaximumSize(150,  textEdit.height());
    mainLayout->addWidget(&textEdit, 0, 3, 3, 1);

    mainLayout->setColumnStretch(2, 2);

    setLayout(mainLayout);

    connect(&redSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setRed(int)));
    connect(&redSlider, SIGNAL(sliderMoved(int)), this, SLOT(setRed(int)));
    connect(&greenSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setGreen(int)));
    connect(&greenSlider, SIGNAL(sliderMoved(int)), this, SLOT(setGreen(int)));
    connect(&blueSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setBlue(int)));
    connect(&blueSlider, SIGNAL(sliderMoved(int)), this, SLOT(setBlue(int)));

    show();
}

void Widget::setRed(int value)
{
    redSpinBox.setValue(value);
    redSlider.setValue(value);
    setColor();
}

void Widget::setGreen(int value)
{
    greenSpinBox.setValue(value);
    greenSlider.setValue(value);
    setColor();
}

void Widget::setBlue(int value)
{
    blueSpinBox.setValue(value);
    blueSlider.setValue(value);
    setColor();
}

void Widget::setColor()
{
    int red = redSpinBox.value();
    int green = greenSpinBox.value();
    int blue = blueSpinBox.value();

    QColor color(red, green, blue);
    QPalette palette = textEdit.palette();
    palette.setColor(QPalette::Base, color);
    textEdit.setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}



Widget1::Widget1(QWidget *parent)
    : QWidget(parent)
{
    textEdit = new QTextEdit(this);
    button = new QPushButton("Открыть файл", this);

    connect(button, &QPushButton::clicked, this, &Widget1::openFile);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);
    layout->addWidget(button);

    setLayout(layout);
}

void Widget1::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Текстовые файлы (*.txt)");

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString fileContent = in.readAll();
        textEdit->setPlainText(fileContent);
        file.close();
    }
}

Widget1::~Widget1()
{
}

