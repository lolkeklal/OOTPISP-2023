#ifndef FORM5_H
#define FORM5_H

#include <QMainWindow>

class human{
public:
    QString name;
    QList <QString> names;
    human(QString name, QString names[10]){
        this->name=name;
        for(int i=0;i<10;i++)
            if(name!=names[i])
                if(rand() % 5)
                    this->names.append(names[i]);
    }
};

namespace Ui {
class form5;
}

class form5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit form5(QWidget *parent = nullptr);
    ~form5();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::form5 *ui;
    QList <human> pervy_class;
    QString names[10]={"Doter","Loler","0->Slave0->","Pedro","Adolf","Gendalf","Geralt","Mecheny","Vova Vist","Van"};
};

#endif // FORM5_H
