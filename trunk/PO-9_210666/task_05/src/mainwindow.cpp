#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db.sqlite");
    if (!db.open()) {
        qDebug() << "bd isn't open";
    }
	
    setWindowTitle("lab 5");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    fioModel = new QSqlTableModel(this);
    fioModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    fioModel->setTable("fio");
    fioModel->setSort(0, Qt::AscendingOrder);
    ui->fioTableView->verticalHeader()->setVisible(false);
    ui->fioTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->fioTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->fioTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->fioTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->fioTableView->setSortingEnabled(true);
    ui->fioTableView->setModel(fioModel);
    fioModel->select();

    vidModel = new QSqlTableModel(this);
    vidModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    vidModel->setTable("vid");
    vidModel->setSort(0, Qt::AscendingOrder);
    ui->vidTableView->verticalHeader()->setVisible(false);
    ui->vidTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->vidTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->vidTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->vidTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->vidTableView->setSortingEnabled(true);
    ui->vidTableView->setModel(vidModel);
    vidModel->select();

    addWork = new AddWork();
    addWork->setModal(true);

    addWorker = new AddWorker();
    addWorker->setModal(true);

    statistics = new Statistics();
    statistics->setModal(true);
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addWorkerButton_clicked()
{
    QVector<QString> initialValues = {"", "", "", "", "Add record"};
    addWorker->setInitialValues(initialValues);
    addWorker->exec();
    fioModel->submitAll();
}

void MainWindow::on_editWorkerButton_clicked()
{
    if (ui->fioTableView->selectionModel()->hasSelection()){
        QString id = ui->fioTableView->currentIndex().siblingAtColumn(0).data(Qt::DisplayRole).toString();
        QString family = ui->fioTableView->currentIndex().siblingAtColumn(1).data(Qt::DisplayRole).toString();
        QString name = ui->fioTableView->currentIndex().siblingAtColumn(2).data(Qt::DisplayRole).toString();
        QString otchestvo = ui->fioTableView->currentIndex().siblingAtColumn(3).data(Qt::DisplayRole).toString();
        QVector<QString> initialValues = {id, family, name, otchestvo, "Update record"};
        addWorker->setInitialValues(initialValues);
        addWorker->exec();
        fioModel->submitAll();
    }
}

void MainWindow::on_deleteWorkerButton_clicked()
{
    if (ui->fioTableView->selectionModel()->hasSelection()){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Delete worker", "Do you want to delete worker?",
                                                                  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes){
            fioModel->removeRow(ui->fioTableView->currentIndex().row());
            fioModel->submitAll();
        }
    }
}

void MainWindow::on_addWorkButton_clicked()
{
    QSqlQuery query;
    QString queryString = "select * from fio";
    query.exec(queryString);
    if (query.next()){
        QVector<QString> initialValues = {"", "", "10.2023", "", "Add record"};
        addWork->setInitialValues(initialValues);
        addWork->exec();
        vidModel->submitAll();
    }
    else {
        QMessageBox::about(this, "Info", "Must be at least 1 worker");
    }
}

void MainWindow::on_editWorkButton_clicked()
{
    if (ui->vidTableView->selectionModel()->hasSelection()){
        QSqlQuery query;
        QString queryString = "select * from fio";
        query.exec(queryString);
        if (query.next()){
            QModelIndex indexOfRemovingRow = ui->vidTableView->currentIndex();
            QString id = ui->vidTableView->currentIndex().siblingAtColumn(0).data(Qt::DisplayRole).toString();
            QString vid = ui->vidTableView->currentIndex().siblingAtColumn(1).data(Qt::DisplayRole).toString();
            QString month = ui->vidTableView->currentIndex().siblingAtColumn(2).data(Qt::DisplayRole).toString();
            QString summa = ui->vidTableView->currentIndex().siblingAtColumn(3).data(Qt::DisplayRole).toString();
            QVector<QString> initialValues = {id, vid, month, summa, "Update record"};
            addWork->setInitialValues(initialValues);
            if (addWork->exec() == QDialog::Accepted){
                vidModel->removeRow(indexOfRemovingRow.row());
                vidModel->submitAll();
            }
        }
        else {
            QMessageBox::about(this, "Info", "Must be at least 1 worker");
        }
    }
}

void MainWindow::on_deleteWorkButton_clicked()
{
    if (ui->vidTableView->selectionModel()->hasSelection()){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Delete work", "Do you want to delete work?",
                                                                  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes){
            vidModel->removeRow(ui->vidTableView->currentIndex().row());
            vidModel->submitAll();
        }
    }
}

void MainWindow::on_showWorkerStatisticsButton_clicked()
{
    if (ui->fioTableView->selectionModel()->hasSelection()){
        QString workerId = ui->fioTableView->currentIndex().siblingAtColumn(0).data(Qt::DisplayRole).toString();
        statistics->showWorkerStatistics(workerId, Statistics::StatisticsType::Salary);
    }
    else {
        statistics->showAllWorkersStatistics(Statistics::StatisticsType::Salary);
    }
    statistics->exec();
}


void MainWindow::on_showWorkStatisticsButton_clicked()
{
    if (ui->fioTableView->selectionModel()->hasSelection()){
        QString workerId = ui->fioTableView->currentIndex().siblingAtColumn(0).data(Qt::DisplayRole).toString();
        statistics->showWorkerStatistics(workerId, Statistics::StatisticsType::WorkTypes);
    }
    else {
        statistics->showAllWorkersStatistics(Statistics::StatisticsType::WorkTypes);
    }
    statistics->exec();
}
