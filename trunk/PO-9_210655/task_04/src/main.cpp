#include <QtWidgets>

class TemperatureConverter : public QWidget
{
    Q_OBJECT

public:
    TemperatureConverter(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        setupUi();
        connectSignals();
    }

private:
    QLabel *fahrenheitLabel;
    QLabel *celsiusLabel;
    QLabel *kelvinLabel;
    QTableWidget *tableWidget;
    QLineEdit *fahrenheitLineEdit;
    QPushButton *convertButton;
    QShortcut *shortcut;

    void setupUi()
    {
        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        QHBoxLayout *inputLayout = new QHBoxLayout;
        fahrenheitLabel = new QLabel("Fahrenheit:", this);
        fahrenheitLineEdit = new QLineEdit(this);
        convertButton = new QPushButton("Convert", this);
        inputLayout->addWidget(fahrenheitLabel);
        inputLayout->addWidget(fahrenheitLineEdit);
        inputLayout->addWidget(convertButton);
        mainLayout->addLayout(inputLayout);

        tableWidget = new QTableWidget(this);
        tableWidget->setRowCount(1);
        tableWidget->setColumnCount(3);
        QStringList headers;
        headers << "Fahrenheit" << "Celsius" << "Kelvin";
        tableWidget->setHorizontalHeaderLabels(headers);
        tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        mainLayout->addWidget(tableWidget);

        setLayout(mainLayout);

        shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this);
        shortcut->setContext(Qt::WidgetWithChildrenShortcut);
    }



    void connectSignals()
    {
        connect(convertButton, &QPushButton::clicked, this, &TemperatureConverter::convertTemperature);
        connect(shortcut, &QShortcut::activated, this, &TemperatureConverter::convertTemperature);
        connect(tableWidget, &QTableWidget::cellEntered, this, &TemperatureConverter::showToolTip);
    }

    void showToolTip(int row, int column)
    {
        QTableWidgetItem *item = tableWidget->item(row, column);
        if (item) {
            QToolTip::showText(QCursor::pos(), item->text());
        }
    }

    double fahrenheitToCelsius(double fahrenheit)
    {
        return (fahrenheit - 32) * 5 / 9;
    }

    double fahrenheitToKelvin(double fahrenheit)
    {
        return std::round(((fahrenheit + 459.67) * 5 / 9))/10;
    }

    QString formatTemperature(double temperature)
    {
        if (temperature >= 0) {
            return "+" + QString::number(temperature, 'f', 3);
        } else {
            return QString::number(temperature, 'f', 3);
        }
    }

public slots:
    void convertTemperature()
    {
        QString fahrenheitText = fahrenheitLineEdit->text();
        if(fahrenheitText.toInt() > 212 || fahrenheitText.toInt() < 0){
           qDebug() << fahrenheitText.toInt();
           QMessageBox::warning(this, "Внимание","Диапозон ввода: 0 > n < 212");
           return;
        }
        bool ok;
        double fahrenheit = fahrenheitText.toDouble(&ok);
        if (ok) {
            double celsius = fahrenheitToCelsius(fahrenheit);
            double kelvin = fahrenheitToKelvin(fahrenheit);

            QTableWidgetItem *fahrenheitItem = new QTableWidgetItem(fahrenheitText);
            QTableWidgetItem *celsiusItem = new QTableWidgetItem(formatTemperature(celsius));
            QTableWidgetItem *kelvinItem = new QTableWidgetItem(formatTemperature(kelvin));

            tableWidget->setItem(0, 0, fahrenheitItem);
            tableWidget->setItem(0, 1, celsiusItem);
            tableWidget->setItem(0, 2, kelvinItem);

            if (celsius < 0) {
                celsiusItem->setForeground(Qt::blue);
            } else {
                celsiusItem->setForeground(Qt::red);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TemperatureConverter converter;
    converter.setWindowTitle("Temperature Converter");
    converter.show();

    return app.exec();
}

#include "main.moc"
