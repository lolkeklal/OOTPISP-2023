#include "widget.h"
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QFont>
#include <QColor>

TemperatureConverter::TemperatureConverter(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Temperature Converter");

    QVBoxLayout *layout = new QVBoxLayout(this);

    fahrenheitInput = new QLineEdit(this);
    fahrenheitInput->setPlaceholderText("Enter Fahrenheit temperature");
    connect(fahrenheitInput, &QLineEdit::textChanged, this, &TemperatureConverter::onFahrenheitInputTextChanged);
    layout->addWidget(fahrenheitInput);

    addButton = new QPushButton("Добавить", this);
    connect(addButton, &QPushButton::clicked, this, &TemperatureConverter::onAddButtonClicked);
    layout->addWidget(addButton);

    tableWidget = new QTableWidget(0, 3, this);  // Устанавливаем начальное количество строк в 0
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Fahrenheit" << "Celsius" << "Absolute");
    layout->addWidget(tableWidget);

    // Set column widths
    for (int i = 0; i < 3; ++i) {
        tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }

    // Set font for better appearance
    QFont font("Arial", 10);
    tableWidget->setFont(font);

    resultLabel = new QLabel(this);
    layout->addWidget(resultLabel);
}

void TemperatureConverter::onAddButtonClicked() {
    QString text = fahrenheitInput->text();
    bool ok;
    double fahrenheit = text.toDouble(&ok);
    if (ok && fahrenheit >= 0 && fahrenheit <= 212) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);

        double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
        double absolute = celsius + 273.15;

        QTableWidgetItem *fItem = new QTableWidgetItem(QString::number(fahrenheit));
        QTableWidgetItem *cItem = new QTableWidgetItem(QString::number(celsius, 'f', 3));
        QTableWidgetItem *aItem = new QTableWidgetItem(QString::number(absolute, 'f', 1));

        // Set text alignment
        fItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        cItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        aItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

        // Set text color
        if (celsius < 0.0) {
            cItem->setForeground(QColor("blue"));
        } else if(celsius > 0.0){
            cItem->setForeground(QColor("red"));
        }

        tableWidget->setItem(row, 0, fItem);
        tableWidget->setItem(row, 1, cItem);
        tableWidget->setItem(row, 2, aItem);

        // Clear the input field after adding
        fahrenheitInput->clear();

        // Update result label
        resultLabel->setText(QString("Добавлено значение: %1").arg(fahrenheit));
    }else {
        // Update result label
        resultLabel->setText(QString("Неверные данные"));
    }
}

void TemperatureConverter::onFahrenheitInputTextChanged(const QString& text) {
    addButton->setEnabled(!text.isEmpty());
}
