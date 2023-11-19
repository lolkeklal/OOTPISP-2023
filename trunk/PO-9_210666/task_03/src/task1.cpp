#include "task1.h"
#include "ui_task1.h"

Task1::Task1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Task1)
{
    ui->setupUi(this);

    setWindowTitle("Task 1");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    QRegularExpression exprNums("(((-?[1-9][0-9]*)|0)\\s){2}((-?[1-9][0-9]*)|0)");
    QValidator *validatorNums = new QRegularExpressionValidator(exprNums, this);
    ui->numsLineEdit->setValidator(validatorNums);
}

void Task1::showEvent(QShowEvent *event){
    ui->numsLineEdit->clear();
    QWidget::showEvent(event);
}

Task1::~Task1()
{
    delete ui;
}

void Task1::on_pushButton_clicked()
{
    if (ui->numsLineEdit->hasAcceptableInput()){
        QStringList nums = ui->numsLineEdit->text().split(" ");
        for (int i = 0; i < 3; ++i) {
            if ((nums[i].toInt() >= nums[(i+1)%3].toInt() && nums[i].toInt() <= nums[(i+2)%3].toInt()) ||
                (nums[i].toInt() <= nums[(i+1)%3].toInt() && nums[i].toInt() >= nums[(i+2)%3].toInt())){
                nums[i] = QString::number(abs(nums[(i+1)%3].toInt() - nums[(i+2)%3].toInt()));
                ui->numsLineEdit->setText(nums.join(" "));
                return;
            }
        }
    }
    else{
        QMessageBox::about(this, "Info", "Wrong input.");
    }
}

