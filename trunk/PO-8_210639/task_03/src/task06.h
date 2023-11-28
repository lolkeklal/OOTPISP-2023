#ifndef TASK06_H
#define TASK06_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>

namespace Ui {
class task06;
}

class task06 : public QMainWindow
{
    Q_OBJECT

public:
    explicit task06(QWidget *parent = nullptr);
    ~task06();

    QTextEdit* f;
    QTextEdit* g;
    QTextEdit* h;

    QPushButton* updateButton;

private:
    Ui::task06 *ui;
private slots:
    void updateFiles();
};

#endif // TASK06_H
