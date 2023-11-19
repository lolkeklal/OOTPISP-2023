#include "task3.h"
#include "ui_task3.h"

Task3::Task3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Task3)
{
    ui->setupUi(this);

    setWindowTitle("Task 3");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    QRegularExpression exprNum("([1-9][0-9]*)|0");
    QValidator *validatorNum = new QRegularExpressionValidator(exprNum, this);
    ui->listElemLineEdit->setValidator(validatorNum);

    lists = new QList<QString>[2];
    listLabels.append(ui->list1Label);
    listLabels.append(ui->list2Label);
}

void Task3::showEvent(QShowEvent *event){
    ui->listElemLineEdit->clear();
    lists[0].clear();
    lists[1].clear();
    for (int i = 0; i < 5; ++i) {
        lists[0].append(QString::number(rand()%10));
        lists[1].append(QString::number(rand()%10));
    }
    listLabels[0]->setText("List1 = " + lists[0].join(", "));
    listLabels[1]->setText("List2 = " +lists[1].join(", "));
    QWidget::showEvent(event);
}

Task3::~Task3()
{
    delete ui;
}

void Task3::on_fillListPushButton_clicked()
{
    int listIndex = (ui->listComboBox->currentText() == "List1" ? 0 : 1);
    lists[listIndex].clear();
    for (int i = 0; i < 5; ++i) {
        lists[listIndex].append(QString::number(rand()%10));
    }
    listLabels[listIndex]->setText(listLabels[listIndex]->text().left(8) + lists[listIndex].join(", "));
}


void Task3::on_List1ToList2pushButton_clicked()
{
    lists[1] = lists[0];
    ui->list2Label->setText("List2 = " +lists[1].join(", "));
}


void Task3::on_List2ToList1pushButton_clicked()
{
    lists[0] = lists[1];
    ui->list1Label->setText("List1 = " + lists[0].join(", "));
}


void Task3::on_interactPushButton_clicked()
{
    int listIndex = (ui->listComboBox->currentText() == "List1" ? 0 : 1);
    QString listElementToBeAdded = ui->listElemLineEdit->text();
    if(ui->buttonGroup->checkedButton()->text() == "add after last" && !listElementToBeAdded.isEmpty()){
        lists[listIndex].append(listElementToBeAdded);

    }
    else {
        lists[listIndex].removeFirst();
    }
    listLabels[listIndex]->setText(listLabels[listIndex]->text().left(8) + lists[listIndex].join(", "));
}

