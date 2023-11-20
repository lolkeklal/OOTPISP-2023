#include "form6.h"
#include "ui_form6.h"
#include <iostream>
#include <QFileDialog>

form6::form6(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::form6)
{
    ui->setupUi(this);
}

form6::~form6()
{
    delete ui;
}

void form6::on_pushButton_clicked()
{
    QFileDialog fila(this);
    fila.setFileMode(QFileDialog::AnyFile);
    QStringList fileName;
    if(fila.exec()){
            fileName = fila.selectedFiles();
        }
    QFile file(fileName[0]);
    if (!file.open(QIODevice::Text | QIODevice::ReadOnly)) return; // пытаемся открыть файл
    QByteArray ba = file.readLine(); // читаем первую строку
    file.close(); // закрываем файл
    QList<QByteArray> baList = ba.split(' '); // делим строку на кусочки... в качестве разделителя используем пробел
    QList<int> intList; // сюда запишем результат
    for (int i=0;i<baList.size();i++) // перебираем все кусочки строки
    {
      intList.append(baList[i].toInt()); // переводим их int и записываем в новый массив
    }
    int r1=-9999,r2=9999,r3=-9999,r4;
    for(int i=0;i<intList.count();i++)
    {
        if(intList[i]>r1)
            r1=intList[i];
        if(intList[i]<r2 && (i+1)%2==0)
            r2=intList[i];
        if(abs(intList[i])>r3 && (i+1)%2==1)
            r3=intList[i];
        r4=abs(intList[0] - intList[intList.count()-1]);
    }
    ui->spinBox->setValue(r1);
    ui->spinBox_2->setValue(r2);
    ui->spinBox_3->setValue(r3);
    ui->spinBox_4->setValue(r4);
}

