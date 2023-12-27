#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Инициализация главного окна и пользовательского интерфейса
    ui->setupUi(this);

    // Инициализация базы данных SQLite
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("internet.db");
    if (!db.open()) {
        qDebug() << "Fail to open DB!";
    }

    // Создание таблицы 'day' и 'net' в базе данных
    q1 = new QSqlQuery(db);
    q1->exec("CREATE TABLE day(id INT, day TEXT, month TEXT, year TEXT);");
    q1->exec("CREATE TABLE net(id INT, host TEXT, hour INT, time INT, volume INT);");

    // Инициализация моделей данных и их привязка к соответствующим виджетам
    modDay = new QSqlTableModel(this, db);
    modDay->setTable("day");
    modDay->select();

    modNet = new QSqlTableModel(this, db);
    modNet->setTable("net");
    modNet->select();

    ui->tableView_day->setModel(modDay);
    ui->tableView_net->setModel(modNet);
}

MainWindow::~MainWindow()
{
    // Деструктор окна
    delete ui;
}

// Обработчики событий кнопок и таблиц
void MainWindow::on_pushButton_add_day_clicked()
{
    modDay->insertRow(modDay->rowCount());
}

void MainWindow::on_pushButton_delete_day_clicked()
{
    modDay->removeRow(rowDay);
}

void MainWindow::on_tableView_day_clicked(const QModelIndex &index)
{
    rowDay = index.row();
}

void MainWindow::on_pushButton_add_net_clicked()
{
    modNet->insertRow(modNet->rowCount());
}

void MainWindow::on_pushButton_delete_net_clicked()
{
    modNet->removeRow(rowNet);
}

void MainWindow::on_tableView_net_clicked(const QModelIndex &index)
{
    rowNet = index.row();
}

// Функции для выполнения SQL-запросов к базе данных
int getConnectionsCountForHour(int hour)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM net WHERE hour = :hour");
    query.bindValue(":hour", hour);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

int getTotalVolumeForPeriod(const QString& startDate, const QString& endDate)
{
    QSqlQuery query;
    query.prepare("SELECT SUM(net.volume) FROM net JOIN day ON net.id = day.id WHERE day.day >= :startDate AND day.day <= :endDate");
    query.bindValue(":startDate", startDate);
    query.bindValue(":endDate", endDate);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

QStringList getVisitedHosts()
{
    QSqlQuery query("SELECT DISTINCT host FROM net");
    QStringList hosts;
    while (query.next()) {
        hosts.append(query.value(0).toString());
    }
    return hosts;
}

// Обработчики событий кнопок для вызова SQL-запросов и отображения результатов на интерфейсе
void MainWindow::on_pushButton_hours_clicked()
{
    int a = getConnectionsCountForHour(ui->lineEdit_hours->text().toInt());
    ui->label_3->setText("" + QString::number(a));
}

void MainWindow::on_pushButton_hours_2_clicked()
{
    int a = getTotalVolumeForPeriod(ui->lineEdit_period_1->text(), ui->lineEdit_period_2->text());
    ui->label_period_result->setText(": " + QString::number(a));
}

void MainWindow::on_pushButton_sites_clicked()
{
    QString strListToSrt;
    foreach(QString str, getVisitedHosts()) strListToSrt.append(str + ", ");
    ui->label_sites->setText(strListToSrt);
}
