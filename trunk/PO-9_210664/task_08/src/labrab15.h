#ifndef LABRAB15_H
#define LABRAB15_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Labrab15; }
QT_END_NAMESPACE

class Labrab15 : public QMainWindow
{
    Q_OBJECT

public:
    Labrab15(QWidget *parent = nullptr);
    ~Labrab15();

private:
    Ui::Labrab15 *ui;
};
#endif // LABRAB15_H
