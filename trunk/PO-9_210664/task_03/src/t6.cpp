#include "t6.h"
#include "ui_t6.h"

#include <QFile>

t6::t6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t6)
{
    ui->setupUi(this);
    do_file_fask();
}

t6::~t6()
{
    delete ui;
}

bool t6::do_file_fask() {
    QFile inputFile("f.txt");
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString er("Failed to open f.txt");
        ui->plainTextEditF->setPlainText(er);
        return false;
    }

    QFile outputFileEven("g.txt");
    if (!outputFileEven.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QString er("Failed to open g.txt");
        ui->plainTextEditF->setPlainText(er);
        return false;
    }

    QFile outputFileOdd("h.txt");
    if (!outputFileOdd.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QString er("Failed to open h.txt");
        ui->plainTextEditF->setPlainText(er);
        return false;
    }

    QTextStream in(&inputFile);
    QTextStream outEven(&outputFileEven);
    QTextStream outOdd(&outputFileOdd);

    QString f_plain_text;
    QString g_plain_text;
    QString h_plain_text;

    int number;
    while (!in.atEnd()) {
        in >> number;
        f_plain_text += QString::number(number) + " ";
        if (number % 2 == 0) {
            g_plain_text += QString::number(number) + " ";
        } else {
            h_plain_text += QString::number(number) + " ";
        }
    }

    ui->plainTextEditF->setPlainText(f_plain_text);
    outEven << g_plain_text;
    ui->plainTextEditG->setPlainText(g_plain_text);
    outOdd << h_plain_text;
    ui->plainTextEditH->setPlainText(h_plain_text);

    inputFile.close();
    outputFileEven.close();
    outputFileOdd.close();

    return true;
}

void t6::on_pushButton_clicked()
{
    do_file_fask();
}

