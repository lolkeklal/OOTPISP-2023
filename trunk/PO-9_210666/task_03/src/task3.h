#ifndef TASK3_H
#define TASK3_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class Task3;
}

class Task3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Task3(QWidget *parent = nullptr);
    ~Task3();

private slots:
    void on_fillListPushButton_clicked();

    void on_List1ToList2pushButton_clicked();

    void on_List2ToList1pushButton_clicked();

    void on_interactPushButton_clicked();

private:
    Ui::Task3 *ui;
    void showEvent(QShowEvent *event) override;
    QStringList* lists;
    QList<QLabel*> listLabels;
};

#endif // TASK3_H
