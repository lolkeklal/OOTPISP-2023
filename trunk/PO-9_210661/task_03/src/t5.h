// t5.h
#ifndef T5_H
#define T5_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>

namespace Ui {
class t5;
}

class t5 : public QWidget
{
    Q_OBJECT

public:
    explicit t5(QWidget *parent = nullptr);
    ~t5();

private slots:
    void onRunButtonClicked();

private:
    Ui::t5 *ui;
};

#endif // T5_H
