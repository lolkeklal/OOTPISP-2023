#ifndef T5_H
#define T5_H

#include <QWidget>

namespace Ui {
class t5;
}

class t5 : public QWidget
{
    Q_OBJECT

public:
    explicit t5(QWidget *parent = nullptr);
    ~t5();

private:
    Ui::t5 *ui;

    void solveFishTask();
};

#endif // T5_H
