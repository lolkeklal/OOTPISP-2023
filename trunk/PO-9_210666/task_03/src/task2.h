#ifndef TASK2_H
#define TASK2_H

#include <QMainWindow>

namespace Ui {
class Task2;
}

class Task2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Task2(QWidget *parent = nullptr);
    ~Task2();

private slots:
    void on_regenerateMatrix1PushButton_clicked();

    void on_regenerateMatrix2PushButton_clicked();

    void on_getMatrix2SumPushButton_clicked();

private:
    Ui::Task2 *ui;
    void showEvent(QShowEvent *event) override;
};

#endif // TASK2_H
