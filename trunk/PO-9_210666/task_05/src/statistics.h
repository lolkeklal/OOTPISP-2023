#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class Statistics;
}

class Statistics : public QDialog
{
    Q_OBJECT

public:
    enum StatisticsType{WorkTypes, Salary};
    explicit Statistics(QWidget *parent = nullptr);
    ~Statistics();
    void showAllWorkersStatistics(StatisticsType statisticsType);
    void showWorkerStatistics(QString id, StatisticsType statisticsType);

private:
    Ui::Statistics *ui;
};

#endif // STATISTICS_H
