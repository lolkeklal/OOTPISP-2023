#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include "form2.h"
#include "form21.h"
#include "form3.h"
#include "form4.h"
#include "form5.h"
#include "form6.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    form *f_to_pay;
    form21 *f_to_pay21;
    form2 *f_to_pay22;
    form3 *f_to_pay3;
    form4 *f_to_pay4;
    form5 *f_to_pay5;
    form6 *f_to_pay6;
};
#endif // MAINWINDOW_H
