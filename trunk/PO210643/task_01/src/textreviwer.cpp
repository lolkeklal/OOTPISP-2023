#include "textreviwer.h"
#include "ui_textreviwer.h"

TextReviwer::TextReviwer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextReviwer)
{
    ui->setupUi(this);

    QWidget* widget = new QWidget();
    this->setCentralWidget(widget);

    QVBoxLayout* vBoxLayout = new QVBoxLayout;
    widget->setLayout(vBoxLayout);

    txtEdit = new QPlainTextEdit;
    txtEdit->setReadOnly(true);
    QPushButton* btn = new QPushButton;
    btn->setText("Choose file for reading:");
    vBoxLayout->addWidget(txtEdit);
    vBoxLayout->addWidget(btn);

    this->resize(400, 400);

    connect(btn, &QPushButton::clicked, this, &TextReviwer::textreviwer);
}

TextReviwer::~TextReviwer()
{
    delete ui;
}

void TextReviwer::textreviwer(){
    QString fileName = QFileDialog::getOpenFileName(this);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        qDebug() << "It seems there's an error";
    QByteArray data;
    data = file.readAll();
    txtEdit->setPlainText(QString(data));
}
