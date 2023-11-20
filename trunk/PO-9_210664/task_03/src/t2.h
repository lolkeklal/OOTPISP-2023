#ifndef T2_H
#define T2_H

#include <QWidget>

namespace Ui {
class t2;
}

class t2 : public QWidget
{
    Q_OBJECT

public:
    explicit t2(QWidget *parent = nullptr);
    ~t2();

private slots:
    void on_spinBoxN_valueChanged(int arg1);

    void on_spinBoxM_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::t2 *ui;
};

#endif // T2_H
