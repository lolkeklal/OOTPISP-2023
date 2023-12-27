// t4.h
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
    void onRunButtonClicked();

private:
    Ui::t4 *ui;
    template <typename Container>
    QString concatElements(const Container& container);
};

#endif // T4_H
