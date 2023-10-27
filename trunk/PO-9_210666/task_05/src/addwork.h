#ifndef ADDWORK_H
#define ADDWORK_H

#include <QDialog>
#include <QMessageBox>
#include <QSql>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

namespace Ui {
class AddWork;
}

class AddWork : public QDialog
{
    Q_OBJECT

public:
    explicit AddWork(QWidget *parent = nullptr);
    ~AddWork();
    void setInitialValues(QVector<QString> initialValues);

private slots:
    void on_addWorkButton_clicked();

private:
    Ui::AddWork *ui;
};

#endif // ADDWORK_H
