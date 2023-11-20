#include "form2.h"
#include "ui_form2.h"

form2::form2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::form2)
{
    ui->setupUi(this);
    ui->pushButton_2->hide();
}

form2::~form2()
{
    delete ui;
}

void form2::on_pushButton_clicked()
{
    ui->tableWidget->setColumnCount(ui->spinBox->value());
    ui->tableWidget->setRowCount(ui->spinBox_2->value());
    ui->spinBox_4->setMaximum(ui->spinBox->value());
    ui->spinBox_4->setMinimum(1);
    ui->pushButton_2->show();
}


void form2::on_pushButton_2_clicked()
{
    int result=0;
    if(ui->comboBox->currentText()=="sum"){
        for(int i=0;i<ui->spinBox_2->value();i++)
            result+=ui->tableWidget->item(i,ui->spinBox_4->value()-1)->text().toInt();
        ui->spinBox_3->setValue(result);
    }
}

