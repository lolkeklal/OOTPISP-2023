#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDialog>
#include <QInputDialog>
#include <QDialogButtonBox>
#include <QAbstractButton>
#include <QTableView>

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

    void on_comboBox_textActivated(const QString &arg1);

    void on_pushButton_2_clicked();

    void onCompute(const QString &);

private:
    QSqlQuery *query;
    Ui::MainWindow *ui;
    QSqlTableModel *student,*session,*result,*dobro,*zlo;
    void getStudent(QWidget *parent);
    void getDiss(QWidget *parent);
    void uspeh();
    QSqlDatabase db;
    QString diss;

};
#endif // MAINWINDOW_H
