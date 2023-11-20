#ifndef T4_H
#define T4_H

#include <QWidget>

namespace Ui {
class t4;
}

class t4 : public QWidget
{
    Q_OBJECT

public:
    explicit t4(QWidget *parent = nullptr);
    ~t4();

private slots:
    void on_pushButton_clicked();

private:
    Ui::t4 *ui;
};

#endif // T4_H
