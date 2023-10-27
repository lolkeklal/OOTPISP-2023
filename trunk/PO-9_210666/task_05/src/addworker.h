#ifndef ADDWORKER_H
#define ADDWORKER_H

#include <QDialog>
#include <QMessageBox>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

namespace Ui {
class AddWorker;
}

class AddWorker : public QDialog
{
    Q_OBJECT

public:
    explicit AddWorker(QWidget *parent = nullptr);
    ~AddWorker();
    void setInitialValues(QVector<QString> initialValues);

private slots:
    void on_addWorkerButton_clicked();

private:
    Ui::AddWorker *ui;
    QString updatingId;
};

#endif // ADDWORKER_H
