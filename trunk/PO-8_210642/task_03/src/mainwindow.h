// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>

#include "task01.h"
#include "task02.h"
#include "task03.h"
#include "task04.h"
#include "task05.h"
#include "task06.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPushButton* task01Button;
    QPushButton* task02Button;
    QPushButton* task03Button;
    QPushButton* task04Button;
    QPushButton* task05Button;
    QPushButton* task06Button;

private:
    Ui::MainWindow *ui;

private slots:
    void createTask01Window();
    void createTask02Window();
    void createTask03Window();
    void createTask04Window();
    void createTask05Window();
    void createTask06Window();
};

#endif // MAINWINDOW_H
