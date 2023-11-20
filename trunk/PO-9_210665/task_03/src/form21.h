#ifndef FORM21_H
#define FORM21_H

#include <QMainWindow>
#include <QInputDialog>

namespace Ui {
class form21;
}

class form21 : public QMainWindow
{
    Q_OBJECT

public:
    explicit form21(QWidget *parent = nullptr);
    ~form21();

private:
    Ui::form21 *ui;
};

#endif // FORM21_H
