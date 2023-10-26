#ifndef DATABASEWINDOW_H
#define DATABASEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DatabaseWindow; }
QT_END_NAMESPACE

class DatabaseWindow : public QMainWindow
{
    Q_OBJECT

public:
    DatabaseWindow(QWidget *parent = nullptr);
    ~DatabaseWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::DatabaseWindow *ui;
};
#endif // DATABASEWINDOW_H
