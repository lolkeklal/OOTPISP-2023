#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("tazk_05");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./my_cosy_db.db");
    if (!db.open()) {
        qDebug() << "FAIL: database failed to open.";
        qDebug() << db.lastError().text();
    }
    else{
        query = new QSqlQuery(db);
        QString str_to_exec = "CREATE TABLE student ("
            "id INTEGER NOT NULL UNIQUE,"
            "family TEXT NOT NULL,"
            "name TEXT NOT NULL,"
            "otch TEXT,"
            "PRIMARY KEY(id AUTOINCREMENT)"
            ")";
        if(!query->exec(str_to_exec))
            {
                qDebug() << query->lastError().text();
            }
        student = new QSqlTableModel(this, db);
        student->setTable("student");
        student->select();


        str_to_exec = "CREATE TABLE session ("
            "diss TEXT NOT NULL UNIQUE,"
            "vid TEXT NOT NULL CHECK (vid IN ('экзамен', 'зачет'))"
            ")";
        if(!query->exec(str_to_exec))
            {
                qDebug() << query->lastError().text();
            }
        session = new QSqlTableModel(this, db);
        session->setTable("session");
        session->select();


        str_to_exec = "CREATE TABLE result ("
            "id	INTEGER NOT NULL UNIQUE,"
            "itog INTEGER NOT NULL CHECK (itog=1 OR itog=0),"
            "PRIMARY KEY(id AUTOINCREMENT)"
            ")";
        if(!query->exec(str_to_exec))
            {
                qDebug() << query->lastError().text();
            }
        result = new QSqlTableModel(this, db);
        result->setTable("result");
        result->select();

        ui->tableView->setModel(student);
        ui->tableView->setSortingEnabled(true);
        uspeh();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
        getStudent(nullptr);
}

void MainWindow::getStudent(QWidget *parent)
{
    int number = 0;
    bool ok;
    QString strin1 = QInputDialog::getText(parent, "Получить family","Введите family:",QLineEdit::Normal,QDir::home().dirName(), &ok);
    if (ok) {qDebug() << "family: " << strin1;}
    else return;
    QString strin2 = QInputDialog::getText(parent, "Получить name","Введите name:",QLineEdit::Normal,QDir::home().dirName(), &ok);
    if (ok) {qDebug() << "name: " << strin2;}
    else return;
    QString strin3 = QInputDialog::getText(parent, "Получить otch(необяз)","Введите otch(необяз):",QLineEdit::Normal,QDir::home().dirName(), &ok);
    if (ok) {qDebug() << "otch: " << strin3;}
    else return;
    int itog = QInputDialog::getInt(parent, "Получить itog","Введите itog:",0, 0, 1, 1,&ok);
    if (ok) {qDebug() << "id: " << number;}
    else return;
    QString str_to_exec = QString("INSERT INTO student VALUES(NULL,'%2','%3','%4')").arg(strin1).arg(strin2).arg(strin3);
    if(!query->exec(str_to_exec))
    {
        qDebug() << query->lastError().text();
        return;
    }
    str_to_exec = QString("INSERT INTO result VALUES(NULL,%2)").arg(itog);
    if(!query->exec(str_to_exec))
    {
        qDebug() << query->lastError().text();
        return;
    }
    uspeh();
    if(ui->comboBox->currentText()=="students")
    {
        student = new QSqlTableModel(this, db);
        student->setTable("student");
        student->select();
        ui->tableView->setModel(student);
        return;
    }
    if(ui->comboBox->currentText()=="result")
    {
        result = new QSqlTableModel(this, db);
        result->setTable("result");
        result->select();
        ui->tableView->setModel(result);
        return;
    }
}

void MainWindow::getDiss(QWidget *parent)
{
    int number = 0;
    bool ok;
    QString strin1 = QInputDialog::getText(parent, "Получить family","Введите family:",QLineEdit::Normal,QDir::home().dirName(), &ok);
    if (ok) {qDebug() << "family: " << strin1;}
    else return;

    QInputDialog qDialog ;

    QStringList items;
    items << QString("экзамен");
    items << QString("зачет");

    qDialog.setOptions(QInputDialog::UseListViewForComboBoxItems);
    qDialog.setComboBoxItems(items);
    qDialog.setWindowTitle("Choose action");

    QObject::connect(&qDialog, SIGNAL(textValueChanged(const QString &)),
               this, SLOT(onCompute(const QString &)));
    int y;
    qDialog.exec();
    qDebug() << diss;

    QString str_to_exec = QString("INSERT INTO session VALUES('%1','%2')").arg(strin1).arg(diss);
    if(!query->exec(str_to_exec))
    {
        qDebug() << query->lastError().text();
        return;
    }

    if(ui->comboBox->currentText()=="session")
    {
        session = new QSqlTableModel(this, db);
        session->setTable("result");
        session->select();
        ui->tableView->setModel(session);
        return;
    }
}


void MainWindow::on_comboBox_textActivated(const QString &arg1)
{
    if(ui->comboBox->currentText()=="students")
    {
        student = new QSqlTableModel(this, db);
        student->setTable("student");
        student->select();
        ui->tableView->setModel(student);
        return;
    }
    if(ui->comboBox->currentText()=="session")
    {
        session = new QSqlTableModel(this, db);
        session->setTable("session");
        session->select();
        ui->tableView->setModel(session);
        return;
    }
    if(ui->comboBox->currentText()=="result")
    {
        result = new QSqlTableModel(this, db);
        result->setTable("result");
        result->select();
        ui->tableView->setModel(result);
        return;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    getDiss(nullptr);
}

void MainWindow::onCompute(const QString &gg){
    diss=gg;
}

void MainWindow::uspeh(){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM student WHERE id IN (SELECT id FROM result WHERE itog=0)");
    ui->tableView_1->setModel(model);
    QSqlQueryModel *model2 = new QSqlQueryModel;
    model2->setQuery("SELECT * FROM student WHERE id IN (SELECT id FROM result WHERE itog=1)");
    ui->tableView_2->setModel(model2);
}
