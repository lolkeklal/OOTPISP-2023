#include "gg.h"
#include "ui_gg.h"

gg::gg(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gg)
{
    ui->setupUi(this);
    QWidget* widget = new QWidget();
    this->setCentralWidget(widget);

    QGridLayout* grid_layout = new QGridLayout;
    widget->setLayout(grid_layout);


    QVBoxLayout* v_box_layout3 = new QVBoxLayout;
    QVBoxLayout* v_box_layout4 = new QVBoxLayout;

    grid_layout->addLayout(v_box_layout3, 0, 2);
    grid_layout->addLayout(v_box_layout4, 0, 3);



    but= new QPushButton("&opa", this);
    txtEdit = new QPlainTextEdit;
    txtEdit->setReadOnly(true);
    v_box_layout3->addWidget(but);
    v_box_layout4->addWidget(txtEdit);

    this->resize(450, 200);
    this->setWindowTitle("task_01");

    connect(but, &QPushButton::clicked, this, &gg::Otkr);

}
void gg::Otkr(){
    QFileDialog fila(this);
    fila.setFileMode(QFileDialog::AnyFile);
    QStringList fileName;
    if(fila.exec()){
        fileName = fila.selectedFiles();
        qDebug() << fileName[0];
        QFile readFil(fileName[0]);
        if(!readFil.open(QIODevice::ReadOnly))
            return;
        QByteArray data=readFil.readAll();
        txtEdit->setPlainText(QString(data));
    }

}
gg::~gg()
{
    delete ui;
}
