#ifndef T1_H
#define T1_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class t1; }
QT_END_NAMESPACE

class t1 : public QWidget
{
    Q_OBJECT

public:
    t1(QWidget *parent = nullptr);
    ~t1();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::t1 *ui;
};
#endif // T1_H
