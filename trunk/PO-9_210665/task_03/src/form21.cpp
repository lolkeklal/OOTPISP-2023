#include "form21.h"
#include "ui_form21.h"

form21::form21(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::form21)
{
    ui->setupUi(this);
    QVector <int> veco;
    int count = QInputDialog::getInt(this,tr("Колво номеров"),tr(""));
    for(int i=0;i<count;i++)
        veco.push_back(QInputDialog::getInt(this,tr("номер"),tr("")));
    for(int i=veco.count()-1;i>=0;i--)
        ui->comboBox->addItem(QString::number(veco[i]));
    ui->comboBox->addItem("");
}


form21::~form21()
{
    delete ui;
}
