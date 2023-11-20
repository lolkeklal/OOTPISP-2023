#include "form.h"
#include "ui_form.h"

form::form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::form)
{
    ui->setupUi(this);
    ui->textEdit->setText("Даны две переменные целого типа: A и B (переменные вводятся в lineedit). "
                          "Если их значения не равны, то присвоить каждой переменной максимальное "
                          "из этих значений, а если равны, то присвоить переменным нулевые значения.");
}

form::~form()
{
    delete ui;
}


void form::on_pushButton_clicked()
{
    QString A = ui->lineEdit->text();
    QString B = ui->lineEdit_2->text();
    bool ok1,ok2;
    int AA,BB;
    AA = A.toInt(&ok1);
    BB = B.toInt(&ok2);
    if(ok1 && ok2)
        if(AA > -1000 && BB > -1000 && AA < 1000 && BB < 1000)
        {
            if(AA>BB)
            {
                BB=AA;
                B=A;
            }
            else{
                AA=BB;
                A=B;
            }
            ui->lineEdit->setText(A);
            ui->lineEdit_2->setText(B);
        }
        else{
            ui->lineEdit->setText("wrong format");
            ui->lineEdit_2->setText("wrong format");}
    else
    {
        ui->lineEdit->setText("wrong format");
        ui->lineEdit_2->setText("wrong format");
    }
}

