#include "form5.h"
#include "ui_form5.h"

form5::form5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::form5)
{
    ui->setupUi(this);
}

form5::~form5()
{
    delete ui;
}
bool propusk=0;
void form5::on_pushButton_clicked()
{
    propusk=0;
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    pervy_class.clear();
    for(int i=0;i<10;i++){
        human chel(this->names[i],this->names);
        pervy_class.append(chel);
        if(i==0)
            for(int j=0;j<chel.names.count()-1;j++)
                ui->comboBox_2->addItem(chel.names[j]);
        if(chel.names.count()==9)
            ui->comboBox_3->addItem(chel.name);
        ui->comboBox->addItem(chel.name);

    }
    propusk=1;
}


void form5::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(propusk){
        for(int i=0;i<10;i++){
            if(pervy_class[i].name==arg1){
                ui->comboBox_2->clear();
                for(int j=0;j<pervy_class[i].names.count()-1;j++)
                    ui->comboBox_2->addItem(pervy_class[i].names[j]);
            }
        }
    }
}

