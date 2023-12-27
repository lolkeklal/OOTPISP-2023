#include "task06.h"
#include "ui_task06.h"
#include <QLabel>
#include <QGridLayout>
#include <QFile>

task06::task06(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::task06)
{
    ui->setupUi(this);

    QLabel* label1 = new QLabel("f.txt:");
    QLabel* label2 = new QLabel("g.txt:");
    QLabel* label3 = new QLabel("h.txt:");

    updateButton = new QPushButton("update");

    f = new QTextEdit();
    g = new QTextEdit();
    h = new QTextEdit();

    connect(updateButton, &QPushButton::clicked, this, &task06::updateFiles);


    

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(label1, 0, 0);
    layout->addWidget(f, 1, 0);
    layout->addWidget(label2, 2, 0);
    layout->addWidget(g, 3, 0);
    layout->addWidget(label3, 4, 0);
    layout->addWidget(h, 5, 0);
    layout->addWidget(updateButton, 6, 0);

    ui->centralwidget->setLayout(layout);

    QString fileName;
    fileName = "f.txt";
    QFile file(fileName);
    QByteArray text;
    if (!file.open(QIODevice::ReadOnly))
        return;
    text = file.readAll();
    f->setText(QString(text));
    file.close();

    fileName = "g.txt";
    file.setFileName(fileName);
    text.clear();
    if (!file.open(QIODevice::ReadOnly))
        return;
    text = file.readAll();
    g->setText(QString(text));
    file.close();

    fileName = "h.txt";
    file.setFileName(fileName);
    text.clear();
    if (!file.open(QIODevice::ReadOnly))
        return;
    text = file.readAll();
    h->setText(QString(text));
    file.close();
}

task06::~task06()
{
    delete ui;
}

void task06::updateFiles() {

    QString fileName;
    fileName = "f.txt";
    QFile file(fileName);
    QByteArray text = f->toPlainText().toUtf8();
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))return;
    file.write(text);
    file.close();

    std::string str;
    QVector<int> v;
    std::stringstream ss(f->toPlainText().toStdString());
    while (getline(ss, str, ' ')) {
        int temp;
        std::istringstream(str) >> temp;
        v.push_back(temp);
    }

    QString gText;
    QString hText;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0) {
            if (gText.isEmpty()) {
                gText = QString::number(v[i]);
            }
            else {
                gText += " " + QString::number(v[i]);
            }
        }
        else {
            if (hText.isEmpty()) {
                hText = QString::number(v[i]);
            }
            else {
                hText += " " + QString::number(v[i]);
            }
        }
    }

    fileName = "g.txt";
    file.setFileName(fileName);
    text = gText.toUtf8();
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))return;
    file.write(text);
    file.close();

    fileName = "h.txt";
    file.setFileName(fileName);
    text = hText.toUtf8();
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))return;
    file.write(text);
    file.close();

    g->setText(gText);
    h->setText(hText);
}
