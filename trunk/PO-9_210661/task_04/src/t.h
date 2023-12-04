#ifndef T_H
#define T_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QTableWidget>

namespace Ui {
class t;
}

class t : public QWidget
{
    Q_OBJECT

public:
    explicit t(QWidget *parent = nullptr);
    ~t();

private:
    Ui::t *ui;
    QVector<QVector<int>> array;

    void bubbleSort(bool ascending, int column);
    void updateTable();

private slots:
    void on_generateButton_clicked();
    void on_columnHeaderClicked(int column);
};

#endif // T_H
