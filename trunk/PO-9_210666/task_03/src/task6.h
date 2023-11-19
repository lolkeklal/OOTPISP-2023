#ifndef TASK6_H
#define TASK6_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class Task6;
}

class Task6 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Task6(QWidget *parent = nullptr);
    ~Task6();

private slots:
    void on_openFilePushButton_clicked();

    void on_saveFilePushButton_clicked();

private:
    Ui::Task6 *ui;
    void showEvent(QShowEvent *event) override;
};

#endif // TASK6_H
