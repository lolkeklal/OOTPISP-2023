// t2.h
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
    void on_processArrayButton_clicked();
    void on_processMatrixButton_clicked();

private:
    Ui::t2 *ui;

    void processArray(const QVector<int>& array);
    void processMatrix(const QVector<QVector<int>>& matrix);
};

#endif // T2_H
