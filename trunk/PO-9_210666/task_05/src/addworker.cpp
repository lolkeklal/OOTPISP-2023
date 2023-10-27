#include "addworker.h"
#include "ui_addworker.h"

AddWorker::AddWorker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWorker)
{
    ui->setupUi(this);

    setWindowTitle("Worker");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    QRegularExpression exprName("\\w{1,20}");
    QValidator *validatorName = new QRegularExpressionValidator(exprName, this);
    ui->familyEditLine->setValidator(validatorName);
    ui->nameEditLine->setValidator(validatorName);
    ui->otchestvoEditLine->setValidator(validatorName);
}

AddWorker::~AddWorker()
{
    delete ui;
}

void AddWorker::setInitialValues(QVector<QString> initialValues){
    updatingId = initialValues.at(0);
    ui->familyEditLine->setText(initialValues.at(1));
    ui->nameEditLine->setText(initialValues.at(2));
    ui->otchestvoEditLine->setText(initialValues.at(3));
    ui->addWorkerButton->setText(initialValues.at(4));
}

void AddWorker::on_addWorkerButton_clicked()
{
    if (!ui->familyEditLine->hasAcceptableInput()
        || !ui->nameEditLine->hasAcceptableInput()
        || !ui->otchestvoEditLine->hasAcceptableInput()){
        QMessageBox::about(this, "Info", "Fields must contain at least 1 characters.");
        return;
    }

    QString family = ui->familyEditLine->text();
    QString name = ui->nameEditLine->text();
    QString otchestvo = ui->otchestvoEditLine->text();

    QSqlQuery query;
    QString queryString = QString("select * from fio where family = '%1' and "
                                  "name = '%2' and otch = '%3';")
                                  .arg(family, name, otchestvo);
    query.exec(queryString);
    if (!query.next()){
        if (updatingId.isEmpty()){
            queryString = QString("insert into fio (family, name, otch) values('%1', '%2', '%3');")
                              .arg(family, name, otchestvo);
        }
        else {
            //почему-то update не работает :(
            query.exec(QString("delete from fio where id = %1;").arg(updatingId));
            queryString = QString("insert into fio (id, family, name, otch) values('%1', '%2', '%3', '%4');")
                              .arg(updatingId, family, name, otchestvo);
        }
        query.exec(queryString);

        ui->familyEditLine->clear();
        ui->nameEditLine->clear();
        ui->otchestvoEditLine->clear();
        this->accept();
    }
    else {
        QMessageBox::about(this, "Info", "This record is alredy exists.");
    }
}

