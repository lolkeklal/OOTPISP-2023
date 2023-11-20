#include "form4.h"
#include "ui_form4.h"

form4::form4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::form4)
{
    ui->setupUi(this);
    for(int i=0;i<10;i++)
    {
        ui->comboBox->addItem(QString::number(rand()%30-10));
        stakhanov.push(ui->comboBox->itemText(ui->comboBox->count()-1));
    }
    for(int i=0;i<8;i++)
    {
        ui->comboBox_2->addItem(QString::number(rand()%30-10));
        Qaveva.push_front(ui->comboBox_2->itemText(ui->comboBox_2->count()-1));
    }
}

form4::~form4()
{
    delete ui;
}

void form4::on_pushButton_clicked()
{
    int result=0;
    for(int i=0;i<10;i++)
    {
        if(stakhanov[i].toInt()>0)
            result+=stakhanov[i].toInt();
    }
    ui->label->setText(QString::number(result));
}


void form4::on_pushButton_2_clicked()
{
    int result=0;
        if(Qaveva[0].toInt()-Qaveva[1].toInt()>0)
            result+=Qaveva[0].toInt()-Qaveva[1].toInt();
        else
            result+=Qaveva[1].toInt()-Qaveva[0].toInt();
    Qaveva.push_front(QString::number(result));
    ui->comboBox_2->addItem(QString::number(result));
    ui->label_2->setText(QString::number(result));
}

