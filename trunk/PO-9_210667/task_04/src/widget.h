#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class TemperatureConverter : public QWidget {
    Q_OBJECT

public:
    TemperatureConverter(QWidget *parent = nullptr);

private slots:
    void onAddButtonClicked();
    void onFahrenheitInputTextChanged(const QString& text);

private:
    QTableWidget *tableWidget;
    QLineEdit *fahrenheitInput;
    QPushButton *addButton;
    QLabel *resultLabel;
};

#endif // WIDGET_H
