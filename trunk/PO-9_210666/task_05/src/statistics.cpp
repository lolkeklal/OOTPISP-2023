#include "statistics.h"
#include "ui_statistics.h"

Statistics::Statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistics)
{
    ui->setupUi(this);

    setWindowTitle("Statistics");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
}

Statistics::~Statistics()
{
    delete ui;
}

void Statistics::showAllWorkersStatistics(StatisticsType statisticsType){
    QStringList headers = statisticsType == StatisticsType::Salary ?
                          QStringList{"id", "date", "zarplata"} :
                          QStringList{"id", "date", "vid"};
    QString description = statisticsType == StatisticsType::Salary ?
                              QString("Zarplata rabotnikov:") :
                              QString("Vidы rabot rabotnikov");

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->descriptionLabel->setText(description);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setVisible(false);

    QSqlQuery queryId, queryWork;
    QString queryString = QString("select id from fio");
    queryId.exec(queryString);
    int i = 0;
    while(queryId.next()){
        if (statisticsType == StatisticsType::Salary){
            queryString = QString("select  workerId, month, summa from vid where workerId = %1")
                              .arg(queryId.value(0).toString());
        }
        else {
            queryString = QString("select  workerId, month, vid from vid where workerId = %1")
                              .arg(queryId.value(0).toString());
        }

        queryWork.exec(queryString);
        while(queryWork.next()){
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(queryWork.value(0).toString()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(queryWork.value(1).toString()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(queryWork.value(2).toString()));
            i++;
        }
    }
    this->accept();
}

void Statistics::showWorkerStatistics(QString id, StatisticsType statisticsType){
    QStringList headers = statisticsType == StatisticsType::Salary ?
                              QStringList{"date", "zarplata"} :
                              QStringList{"date", "vid"};
    QString description = statisticsType == StatisticsType::Salary ?
                              QString("Zarplata rabotnika s id = %1:").arg(id) :
                              QString("Vidы rabot rabotnika s id = %1:").arg(id);

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->descriptionLabel->setText(description);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setVisible(false);

    QSqlQuery query;
    QString queryString = statisticsType == StatisticsType::Salary ?
                          QString("select month, summa from vid where workerId = %1").arg(id) :
                          QString("select month, vid from vid where workerId = %1").arg(id);

    query.exec(queryString);

    int i = 0;
    while(query.next()){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(query.value(1).toString()));
        i++;
    }
    this->accept();
}
