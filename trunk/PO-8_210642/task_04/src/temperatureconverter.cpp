#include "temperatureconverter.h"
#include "./ui_temperatureconverter.h"

TemperatureConverter::TemperatureConverter(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TemperatureConverter)
{
    ui->setupUi(this);

    temperatureTable = new QTableWidget(0, 3); 
    inputLineEdit = new QLineEdit();
    convertButton = new QPushButton("Convert");
    resetButton = new QPushButton("Reset");
    rangeLabel = new QLabel("Enter Fahrenheit temperature (0 to 212):");

    layout = new QGridLayout();
    layout->addWidget(rangeLabel, 0, 0, 1, 3);
    layout->addWidget(inputLineEdit, 1, 0);
    layout->addWidget(convertButton, 1, 1);
    layout->addWidget(resetButton, 1, 2);
    layout->addWidget(temperatureTable, 2, 0, 1, 3);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(layout);

    setCentralWidget(centralWidget);
    resize(600, 400);

    setupTable();

    connect(convertButton, &QPushButton::clicked, this, &TemperatureConverter::convertTemperature);
    connect(resetButton, &QPushButton::clicked, this, &TemperatureConverter::resetValues);
}

TemperatureConverter::~TemperatureConverter()
{
    delete ui;
}

void TemperatureConverter::setupTable()
{
    temperatureTable->setHorizontalHeaderLabels(QStringList() << "Fahrenheit" << "Celsius" << "Kelvin");
}

void TemperatureConverter::setTableCell(int row, int col, const QString &text, const QColor &color)
{
    QTableWidgetItem *item = new QTableWidgetItem(text);
    item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    item->setForeground(color);
    temperatureTable->setItem(row, col, item);
}

void TemperatureConverter::convertTemperature()
{
    bool conversionOk;
    double fahrenheit = inputLineEdit->text().toDouble(&conversionOk);

    if (conversionOk && fahrenheit >= 0 && fahrenheit <= 212)
    {
        double celsius = (5.0 / 9.0) * (fahrenheit - 32);
        double kelvin = celsius + 273.0;

        QString celsiusStr = QString("%1").arg(celsius, 0, 'f', 3);
        QString kelvinStr = QString("%1").arg(kelvin, 0, 'f', 1);

        QColor textColor = (celsius < 0) ? QColor("blue") : QColor("red");

        int rowCount = temperatureTable->rowCount();
        temperatureTable->setRowCount(rowCount + 1);

        setTableCell(rowCount, 0, QString::number(fahrenheit), textColor);
        setTableCell(rowCount, 1, celsiusStr, textColor);
        setTableCell(rowCount, 2, kelvinStr, textColor);

        inputLineEdit->clear();
    }
}

void TemperatureConverter::resetValues()
{
    temperatureTable->clearContents();
    temperatureTable->setRowCount(0);
    inputLineEdit->clear();
}
