#include "task6.h"
#include "ui_task6.h"

Task6::Task6(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Task6)
{
    ui->setupUi(this);

    setWindowTitle("Task 6");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
}

void Task6::showEvent(QShowEvent *event){
    ui->initialFilePlainTextEdit->clear();
    ui->neededFilePlainTextEdit->clear();
    QWidget::showEvent(event);
}

Task6::~Task6()
{
    delete ui;
}

void Task6::on_openFilePushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open document",
                                                    QDir::currentPath(),
                                                    "Text documents (*.txt)");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Error", "The file is not open");
        return;
    }

    QTextStream fin(&file);
    QStringList* values = new QStringList;
    int max, tmp;
    QTextCharFormat* formatRedText = new QTextCharFormat;
    formatRedText->setForeground(QBrush("red"));
    QTextCharFormat* formatBlackText = new QTextCharFormat;
    while(!fin.atEnd()){
        max = INT_MIN;
        values->clear();
        for (int i = 0; i < 5 && !fin.atEnd(); ++i) {
            fin >> tmp;
            values->append(QString::number(tmp));
            if (tmp > max){
                max = tmp;
            }
        }
        for (QString &elem : *values){
            if (elem.toInt() == max){
                ui->initialFilePlainTextEdit->setCurrentCharFormat(*formatRedText);
                ui->initialFilePlainTextEdit->insertPlainText(elem + " ");
                ui->initialFilePlainTextEdit->setCurrentCharFormat(*formatBlackText);
            }
            else{
                ui->initialFilePlainTextEdit->insertPlainText(elem + " ");
            }
        }
        ui->initialFilePlainTextEdit->insertPlainText("| ");
        ui->neededFilePlainTextEdit->insertPlainText(QString::number(max) + " ");
    }
    delete values;
    delete formatRedText;
    delete formatBlackText;
    file.close();
}


void Task6::on_saveFilePushButton_clicked()
{
    if (ui->neededFilePlainTextEdit->toPlainText().isEmpty())
        return;
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
                                                        QDir::currentPath(),
                                                        "Text documents (*.txt)");
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << ui->neededFilePlainTextEdit->toPlainText();
        file.close();
    }
}

