#include "databasewindow.h"
#include "./ui_databasewindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QTime>
#include <QResource>

DatabaseWindow::DatabaseWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DatabaseWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.sqlite");
    on_comboBox_currentTextChanged("machine");
}

DatabaseWindow::~DatabaseWindow()
{
    delete ui;
}


void DatabaseWindow::on_pushButton_clicked()
{
    QString in = ui->lineIn->text(), out = ui->lineOut->text();
    QList <QString> result;

    if (!in.isEmpty())  result += QString("states.state1 = '%1'").arg(in);
    if (!out.isEmpty()) result += QString("states.state5 = '%1'").arg(out);
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    if (!result.isEmpty()){
        query.exec(QString("SELECT machine.nom as 'number', "\
                           "states.state1, states.state2, states.state3, states.state4, states.state5, "\
                           "reys.t_out, reys.t_in, reys.t_all "\
                           "FROM machine "\
                           "INNER JOIN states ON machine.id = states.id "\
                           "INNER JOIN reys ON machine.nom = reys.id "\
                           "WHERE %1;").arg(result.join(" and ")));
        model->setQuery(query);
        ui->comboBox->setCurrentIndex(3);
        ui->tableView->setModel(model);
    }
}


void DatabaseWindow::on_pushButton_2_clicked()
{
    QString in = ui->timeIn->text(), all = ui->timeAll->text(), out = ui->timeOut->text();
    QList <QString> result;

    if (in != "00:00")  result += QString("reys.t_in = '%1'").arg(in);
    if (out != "00:00") result += QString("reys.t_out = '%1'").arg(out);
    if (all != "00:00") result += QString("reys.t_all = '%1'").arg(all);
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    if (!result.isEmpty()){
        query.exec(QString("SELECT machine.nom as 'number', "\
                           "states.state1, states.state2, states.state3, states.state4, states.state5, "\
                           "reys.t_out, reys.t_in, reys.t_all "\
                           "FROM machine "\
                           "INNER JOIN states ON machine.id = states.id "\
                           "INNER JOIN reys ON machine.nom = reys.id "\
                           "WHERE %1;").arg(result.join(" and ")));
        model->setQuery(query);
        ui->comboBox->setCurrentIndex(3);
        ui->tableView->setModel(model);
    }
}


void DatabaseWindow::on_pushButton_3_clicked()
{
    QString state = ui->lineState->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.exec(QString("SELECT machine.nom as 'number', "\
                       "states.state1, states.state2, states.state3, states.state4, states.state5, "\
                       "reys.t_out, reys.t_in, reys.t_all "\
                       "FROM machine "\
                       "INNER JOIN states ON machine.id = states.id "\
                       "INNER JOIN reys ON machine.nom = reys.id "\
                       "WHERE states.state1 = '%1' OR states.state2 = '%1' OR "\
                       "states.state3 = '%1' OR states.state4 = '%1' OR states.state5 = '%1'").arg(state));
    model->setQuery(query);
    ui->comboBox->setCurrentIndex(3);
    ui->tableView->setModel(model);
}


void DatabaseWindow::on_comboBox_currentTextChanged(const QString &arg)
{
    if (arg == "queries")
        return;
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable(arg);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->select();
    ui->tableView->setModel(model);
}

