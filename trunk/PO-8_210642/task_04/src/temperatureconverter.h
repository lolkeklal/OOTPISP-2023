#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QGridLayout>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class TemperatureConverter; }
QT_END_NAMESPACE

class TemperatureConverter : public QMainWindow
{
    Q_OBJECT

public:
    TemperatureConverter(QWidget *parent = nullptr);
    ~TemperatureConverter();

private slots:
    void convertTemperature();
    void resetValues();

private:
    Ui::TemperatureConverter *ui;
    QTableWidget *temperatureTable;
    QLineEdit *inputLineEdit;
    QPushButton *convertButton;
    QPushButton *resetButton;
    QLabel *rangeLabel;
    QGridLayout *layout;

    void setupTable();
    void setTableCell(int row, int col, const QString &text, const QColor &color);
};

#endif // TEMPERATURECONVERTER_H
