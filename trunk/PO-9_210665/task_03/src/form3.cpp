#include "form3.h"
#include "ui_form3.h"

form3::form3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::form3)
{
    ui->setupUi(this);
}

form3::~form3()
{
    delete ui;
}

void form3::on_pushButton_clicked()
{
    Lesta.clear();
    ui->comboBox->clear();
    for(int i=0;i<ui->spinBox->value();i++){
        Lesta.push_back(QString::number(rand()));
        ui->comboBox->addItem(Lesta.back());
    }
}


void form3::on_pushButton_2_clicked()
{
    if(ui->radioButton->isChecked()){
        Lesta.push_back(QString::number(rand()));
        ui->comboBox->addItem(Lesta.back());
    }
    else{
        if(ui->comboBox->count()>0){
            Lesta.pop_back();
            ui->comboBox->removeItem(ui->comboBox->count()-1);
        }
    }
}


void form3::on_pushButton_3_clicked()
{
    Lesta2.clear();
    ui->comboBox_2->clear();
    for(int i=0;i<ui->spinBox_2->value();i++){
        Lesta2.push_back(QString::number(rand()));
        ui->comboBox_2->addItem(Lesta2.back());
    }
    Lesta3.clear();
    ui->comboBox_3->clear();
    for(int i=0;i<ui->spinBox_2->value();i++){
        Lesta3.push_back(QString::number(rand()));
        ui->comboBox_3->addItem(Lesta3.back());
    }
}


void form3::on_pushButton_4_clicked()
{
    Lesta2.clear();
    Lesta2=Lesta3;
    ui->comboBox_2->clear();
    for(int i=0;i<Lesta2.count();i++){
        ui->comboBox_2->addItem(Lesta2[i]);
    }
    ui->comboBox_3->clear();
    for(int i=0;i<Lesta3.count();i++){
        ui->comboBox_3->addItem(Lesta3[i]);
    }
}

