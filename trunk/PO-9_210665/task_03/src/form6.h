#ifndef FORM6_H
#define FORM6_H

#include <QMainWindow>

namespace Ui {
class form6;
}

class form6 : public QMainWindow
{
    Q_OBJECT

public:
    explicit form6(QWidget *parent = nullptr);
    ~form6();

private slots:
    void on_pushButton_clicked();

private:
    Ui::form6 *ui;
};

#endif // FORM6_H
