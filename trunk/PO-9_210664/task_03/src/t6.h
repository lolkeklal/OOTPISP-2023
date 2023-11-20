#ifndef T6_H
#define T6_H

#include <QWidget>

namespace Ui {
class t6;
}

class t6 : public QWidget
{
    Q_OBJECT

public:
    explicit t6(QWidget *parent = nullptr);
    ~t6();

private slots:
    void on_pushButton_clicked();

private:
    Ui::t6 *ui;

    bool do_file_fask();
};

#endif // T6_H
