#include "labrab15.h"
#include "./ui_labrab15.h"

Labrab15::Labrab15(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Labrab15)
{
    ui->setupUi(this);
}

Labrab15::~Labrab15()
{
    delete ui;
}
