#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QShortCut>
#include <QBrush>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool Valid();
    void minmax();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void on_tableWidget_2_cellChanged(int row, int column);

    void on_tableWidget_3_cellChanged(int row, int column);

private:
    QShortcut *key1,*key2,*key3;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
