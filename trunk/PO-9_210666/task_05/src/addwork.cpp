#include "addwork.h"
#include "ui_addwork.h"

AddWork::AddWork(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWork)
{
    ui->setupUi(this);

    setWindowTitle("Work");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    QRegularExpression exprVid("\\w{1,20}");
    QValidator *validatorVid = new QRegularExpressionValidator(exprVid, this);
    ui->vidEditLine->setValidator(validatorVid);

    QRegularExpression exprSumma("[1-9][0-9]*");
    QValidator *validatorSumma = new QRegularExpressionValidator(exprSumma, this);
    ui->summaEditLine->setValidator(validatorSumma);
}

AddWork::~AddWork()
{
    delete ui;
}

void AddWork::setInitialValues(QVector<QString> initialValues){
    QSqlQuery query;
    QString queryString = "select id from fio";
    query.exec(queryString);
    QString workerId;
    ui->workersIdComboBox->clear();
    while(query.next()){
        workerId = query.value(0).toString();
        ui->workersIdComboBox->addItem(workerId);
    }
    ui->workersIdComboBox->setCurrentIndex(
        initialValues.at(0).isEmpty() ? 0
        : ui->workersIdComboBox->findText(initialValues.at(0), Qt::MatchExactly)
    );
    ui->vidEditLine->setText(initialValues.at(1));
    ui->dateEdit->setDate(QDate::fromString(initialValues.at(2), "MM.yyyy"));
    ui->summaEditLine->setText(initialValues.at(3));
    ui->addWorkButton->setText(initialValues.at(4));
}

void AddWork::on_addWorkButton_clicked() {
    if (!ui->vidEditLine->hasAcceptableInput()){
        QMessageBox::about(this, "Info", "Vid must contain at least 1 characters.");
        return;
    }
    if (!ui->summaEditLine->hasAcceptableInput()){
        QMessageBox::about(this, "Info", "Summa is a required field.");
        return;
    }

    QString workerId = ui->workersIdComboBox->currentText();
    QString vid = ui->vidEditLine->text();
    QString month = ui->dateEdit->text();
    QString summa = ui->summaEditLine->text();

    QSqlQuery query;
    QString queryString = QString("select * from vid where workerId = '%1' and month = '%3'")
                                  .arg(workerId, month);
    query.exec(queryString);
    if (!query.next()){
        queryString = QString("insert into vid values('%1', '%2', '%3', '%4')")
                          .arg(workerId, vid, month, summa);
        query.exec(queryString);
        ui->workersIdComboBox->setCurrentIndex(0);
        ui->vidEditLine->clear();
        ui->summaEditLine->clear();
        this->accept();
    }
    else {
        QMessageBox::about(this, "Info", "The employee is busy this month");
    }
}

