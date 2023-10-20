#include "openfile.h"
#include "ui_openfile.h"

OpenFile::OpenFile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OpenFile)
{
    ui->setupUi(this);

    QWidget* widget = new QWidget();
    this->setCentralWidget(widget);

    QVBoxLayout* v_box_layout = new QVBoxLayout;
    widget->setLayout(v_box_layout);

    txtEdit = new QPlainTextEdit;
    txtEdit->setReadOnly(true);
    QPushButton* bt = new QPushButton;
    bt->setText("Choose file");
    v_box_layout->addWidget(txtEdit);
    v_box_layout->addWidget(bt);

    this->resize(400, 400);

    connect(bt, &QPushButton::clicked, this, &OpenFile::openFile);
}

OpenFile::~OpenFile()
{
    delete ui;
}

void OpenFile::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        qDebug() << "Error";
    QByteArray data;
    data = file.readAll();
    txtEdit->setPlainText(QString(data));
}
