#include "mainwindow.h"
#include "./ui_mainwindow.h"

bool MainWindow::Valid(){
    QTableWidgetItem *curitem;
    QString idTrn;
    bool ok,finaly_ok=true;
    for(int j=0;j<3;j++)
        for(int i=0;i<3;i++){
            curitem = ui->tableWidget->item(j,i);
            idTrn = curitem->text();
            idTrn.toInt(&ok);
            if(ok == false){
                finaly_ok=false;
            }
            curitem = ui->tableWidget_2->item(j,i);
            idTrn = curitem->text();
            idTrn.toInt(&ok);
            if(!ok){
                finaly_ok=false;
            }
        }
    if(finaly_ok==false){
        ui->label->setText("wrong format");
        return false;
    }
    ui->label->clear();
    return true;
    ui->tableWidget->setToolTipDuration(5);
    ui->tableWidget_2->setToolTipDuration(5);
    ui->tableWidget_3->setToolTipDuration(5);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("tazk_04");
    key1 = new QShortcut(this);
    key1->setKey(Qt::Key_Q);
    connect(key1, SIGNAL(activated()), this, SLOT(on_pushButton_clicked()));

    key2 = new QShortcut(this);
    key2->setKey(Qt::Key_W);
    connect(key2, SIGNAL(activated()), this, SLOT(on_pushButton_2_clicked()));

    key3 = new QShortcut(this);
    key3->setKey(Qt::Key_E);
    connect(key3, SIGNAL(activated()), this, SLOT(on_pushButton_3_clicked()));

    for(int j=0;j<3;j++)
        for(int i=0;i<3;i++){
            ui->tableWidget->setItem(j,i, new QTableWidgetItem("0"));
            ui->tableWidget_2->setItem(j,i, new QTableWidgetItem("0"));
            ui->tableWidget_3->setItem(j,i, new QTableWidgetItem("0"));
        }
    MainWindow::Valid();


}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (MainWindow::Valid()==false)
        return;
    for(int j=0;j<3;j++)
        for(int i=0;i<3;i++){
            ui->tableWidget_3->setItem(j,i,
                new QTableWidgetItem(QString::number
                    (ui->tableWidget->item(j,i)->text().toInt()+ui->tableWidget_2->item(j,i)->text().toInt())));
        }
    minmax();
}


void MainWindow::on_pushButton_2_clicked()
{
    if (MainWindow::Valid()==false)
        return;
    for(int j=0;j<3;j++)
        for(int i=0;i<3;i++){
            ui->tableWidget_3->setItem(j,i,
                new QTableWidgetItem(QString::number
                    (ui->tableWidget->item(j,i)->text().toInt()-ui->tableWidget_2->item(j,i)->text().toInt())));
        }
    minmax();
}


void MainWindow::on_pushButton_3_clicked()
{
    if (MainWindow::Valid()==false)
        return;
    int t_1_1;
    int t_1_2;
    int t_1_3;
    int t_2_1;
    int t_2_2;
    int t_2_3;
    int result;
    for(int j=0;j<3;j++)
        for(int i=0;i<3;i++){
            t_1_1 = ui->tableWidget->item(j,0)->text().toInt();
            t_1_2 = ui->tableWidget->item(j,1)->text().toInt();
            t_1_3 = ui->tableWidget->item(j,2)->text().toInt();
            t_2_1 = ui->tableWidget_2->item(0,i)->text().toInt();
            t_2_2 = ui->tableWidget_2->item(1,i)->text().toInt();
            t_2_3 = ui->tableWidget_2->item(2,i)->text().toInt();
            result = t_1_1 * t_2_1 + t_1_2 * t_2_2 +t_1_3 * t_2_3;
            ui->tableWidget_3->setItem(j,i,
                new QTableWidgetItem(QString::number
                    (result)));
        }
    minmax();
}

void MainWindow::minmax(){
    short imin,jmin,imax,jmax;
    int min=9999,max=-9999;
    for(int j=0;j<3;j++)
        for(int i=0;i<3;i++){

            if(ui->tableWidget_3->item(j,i)->text().toInt()>max){
                max=ui->tableWidget_3->item(j,i)->text().toInt();
                imax=i;
                jmax=j;
            };
            if(ui->tableWidget_3->item(j,i)->text().toInt()<min){
                min=ui->tableWidget_3->item(j,i)->text().toInt();
                imin=i;
                jmin=j;
            };
        }
    QBrush cl;
    ui->tableWidget_3->item(jmin,imin)->setBackground(Qt::cyan);
    ui->tableWidget_3->item(jmax,imax)->setBackground(Qt::darkCyan);
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    ui->tableWidget->item(row,column)->setToolTip(ui->tableWidget->item(row,column)->text());

}


void MainWindow::on_tableWidget_2_cellChanged(int row, int column)
{
    ui->tableWidget_2->item(row,column)->setToolTip(ui->tableWidget_2->item(row,column)->text());
}


void MainWindow::on_tableWidget_3_cellChanged(int row, int column)
{
    ui->tableWidget_3->item(row,column)->setToolTip(ui->tableWidget_3->item(row,column)->text());
}

