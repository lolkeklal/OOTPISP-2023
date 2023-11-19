#include "task4.h"
#include "ui_task4.h"

Task4::Task4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Task4)
{
    ui->setupUi(this);

    setWindowTitle("Task 4");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
}

void Task4::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
}

Task4::~Task4()
{
    delete ui;
}

void Task4::on_pushButton_clicked()
{
    QStack<QString>* initialStack = new QStack<QString>;
    for (int i = 0; i < 10; ++i) {
        initialStack->push(QString::number((rand() % 10) - 5).rightJustified(3, ' '));
    }
    ui->initialStacklabel->setText(initialStack->join(" "));

    QStack<QString>* updatedStack = new QStack<QString>;
    for(QString& elem : *initialStack){
        if(elem.toInt() > 0){
            updatedStack->push(QString("1").rightJustified(3, ' '));
        }
        else if (elem.toInt() < 0){
            updatedStack->push(QString("-1").rightJustified(3, ' '));
        }
        else{
            updatedStack->push(QString("0").rightJustified(3, ' '));
        }
    }
    ui->updatedStacklabel->setText(updatedStack->join(" "));
    delete initialStack;
    delete updatedStack;
}


void Task4::on_newQueuePushButton_clicked()
{
    QQueue<QString>* initialQueue = new QQueue<QString>;
    for (int i = 0; i < 10; ++i) {
        initialQueue->push_back(QString::number((rand() % 10) - 5).rightJustified(3, ' '));
    }
    ui->initialQueuelabel->setText(initialQueue->join(" "));

    int max = INT_MIN;
    for(QString& elem : *initialQueue){
        if(elem.toInt() > max){
            max = elem.toInt();
        }
    }
    QQueue<QString>* updatedQueue = new QQueue<QString>;
    for(QString& elem : *initialQueue){
        updatedQueue->push_back(QString::number(elem.toInt() + max).rightJustified(3, ' '));
    }
    ui->updatedQueuelabel->setText(updatedQueue->join(" "));
    delete initialQueue;
    delete updatedQueue;
}

