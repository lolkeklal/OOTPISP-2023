#ifndef FORM4_H
#define FORM4_H

#include <QMainWindow>
#include <QStack>
#include <QQueue>

namespace Ui {
class form4;
}

class form4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit form4(QWidget *parent = nullptr);
    ~form4();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::form4 *ui;
    QStack <QString> stakhanov;
    QQueue <QString> Qaveva;
};

#endif // FORM4_H
