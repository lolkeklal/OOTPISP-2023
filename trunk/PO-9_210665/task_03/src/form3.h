#ifndef FORM3_H
#define FORM3_H

#include <QMainWindow>

namespace Ui {
class form3;
}

class form3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit form3(QWidget *parent = nullptr);
    ~form3();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::form3 *ui;
    QList <QString> Lesta,Lesta2,Lesta3;
};

#endif // FORM3_H
