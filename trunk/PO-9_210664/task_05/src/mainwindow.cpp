#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Magaz.db");
    if (!db.open()) {
        qDebug() << "Fail to open DB!";
    }

    prodavecModel.setQuery("SELECT * FROM prodavec");
    productModel.setQuery("SELECT * FROM product");

    ui->tableView_prodavec->setModel(&prodavecModel);
    ui->tableView_product->setModel(&productModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_findProdavec_clicked()
{
    delete ui->tableView_select->model();

    QSqlQueryModel* queryResultModel = new QSqlQueryModel;
    QSqlQuery query;
    query.exec("SELECT p.family, p.name, p.otch "
               "FROM prodavec p "
               "JOIN product pr ON p.id = pr.vid " +
               QString("WHERE pr.id = %1").arg(ui->spinBox->value())
    );

    queryResultModel->setQuery(query);
    ui->tableView_select->setModel(queryResultModel);
}

void MainWindow::on_pushButton_sumProdavec_clicked()
{
    delete ui->tableView_select->model();

    QSqlQueryModel* queryResultModel = new QSqlQueryModel;
    QSqlQuery query;
    query.exec("SELECT p.family, p.name, p.otch, SUM(pr.summa) as total_summa "
               "FROM prodavec p "
               "JOIN product pr ON p.id = pr.vid "
               "GROUP BY p.id, p.family, p.name, p.otch");

    queryResultModel->setQuery(query);
    ui->tableView_select->setModel(queryResultModel);
}

