#ifndef TASK4_H
#define TASK4_H

#include <QMainWindow>
#include <QStack>
#include <QQueue>

namespace Ui {
class Task4;
}

class Task4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Task4(QWidget *parent = nullptr);
    ~Task4();

private slots:
    void on_pushButton_clicked();

    void on_newQueuePushButton_clicked();

private:
    Ui::Task4 *ui;
    void showEvent(QShowEvent *event) override;
};

#endif // TASK4_H
