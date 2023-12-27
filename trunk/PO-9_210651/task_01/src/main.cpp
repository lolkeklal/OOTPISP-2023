#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QPlainTextEdit>
#include <QLabel>
#include <QGridLayout>
#include <QObject>
#include <QColor>
#include <QString>
#include <QPushButton>
#include <QFileDialog>


void setRed(int x);
void setGreen(int x);
void setBlue(int x);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget widget1(0);
    QWidget widget2(0);
    widget1.setWindowTitle("Color change");
    widget2.setWindowTitle("Open file");
    widget1.resize(700,400);
    widget2.resize(600,300);
    QGridLayout gridlayout, fgridlayout;
    widget1.setLayout(&gridlayout);
    widget2.setLayout(&fgridlayout);

    //--first task--
//Creating objects
    QPlainTextEdit plainTextedit;
    plainTextedit.setEnabled(false);
    QSlider rSlider(Qt::Horizontal), gSlider(Qt::Horizontal), bSlider(Qt::Horizontal);
    QLabel rLabel("Red"), gLabel("Green"), bLabel("Blue");
    QSpinBox rSpinBox, gSpinBox, bSpinBox;

//Setting limits
    rSlider.setMinimum(0);
    rSlider.setMaximum(255);
    gSlider.setMinimum(0);
    gSlider.setMaximum(255);
    bSlider.setMinimum(0);
    bSlider.setMaximum(255);
    rSpinBox.setMinimum(0);
    rSpinBox.setMaximum(255);
    gSpinBox.setMinimum(0);
    gSpinBox.setMaximum(255);
    bSpinBox.setMinimum(0);
    bSpinBox.setMaximum(255);

 //adding objects
    gridlayout.addWidget(&rLabel, 0,0);
    gridlayout.addWidget(&gLabel, 1,0);
    gridlayout.addWidget(&bLabel, 2,0);

    gridlayout.addWidget(&rSpinBox, 0,1);
    gridlayout.addWidget(&gSpinBox, 1,1);
    gridlayout.addWidget(&bSpinBox, 2,1);

    gridlayout.addWidget(&rSlider, 0,2);
    gridlayout.addWidget(&gSlider, 1,2);
    gridlayout.addWidget(&bSlider, 2,2);

    gridlayout.addWidget(&plainTextedit, 0, 3, 3, 1);


  //connecting signals and slots
    QObject::connect(&rSlider, &QSlider::sliderMoved, &rSpinBox, &QSpinBox::setValue);
    QObject::connect(&rSpinBox, &QSpinBox::valueChanged, &rSlider, &QSlider::setValue);
    QObject::connect(&gSlider, &QSlider::sliderMoved, &gSpinBox, &QSpinBox::setValue);
    QObject::connect(&gSpinBox, &QSpinBox::valueChanged, &gSlider, &QSlider::setValue);
    QObject::connect(&bSlider, &QSlider::sliderMoved, &bSpinBox, &QSpinBox::setValue);
    QObject::connect(&bSpinBox,&QSpinBox::valueChanged, &bSlider, &QSlider::setValue);

    auto setColor = [&]() {
        int red = rSpinBox.value();
        int green = gSpinBox.value();
        int blue = bSpinBox.value();
        QString newstyle = QString("background-color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue);
        plainTextedit.setStyleSheet(newstyle);
    };

    QObject::connect(&rSlider, &QSlider::sliderMoved, setColor);
    QObject::connect(&gSlider, &QSlider::sliderMoved, setColor);
    QObject::connect(&bSlider, &QSlider::sliderMoved, setColor);

    QObject::connect(&rSpinBox,&QSpinBox::valueChanged, setColor);
    QObject::connect(&gSpinBox, &QSpinBox::valueChanged, setColor);
    QObject::connect(&bSpinBox, &QSpinBox::valueChanged, setColor);


    //--second task--
    //creating objects
    QPlainTextEdit ftext;
    QPushButton fbutton;
    fbutton.setText("Open a file");

    //adding objects
    fgridlayout.addWidget(&ftext, 0, 0, 1,1);
    fgridlayout.addWidget(&fbutton, 1,1);


    QObject::connect(&fbutton, &QPushButton::clicked, [&](){
        QString fpath = QFileDialog::getOpenFileName(&widget2, "Choose your file", "", "Text files(*.txt)");
        if (!fpath.isEmpty()){
            QFile file(fpath);
            if(file.open(QIODevice::ReadOnly| QIODevice::Text)){
                QTextStream in(&file);
                QString fInfo = in.readAll();
                file.close();
                ftext.setPlainText(fInfo);
            }
        }else{
            ftext.setPlainText("Error");
        }
    }
                     );


    widget1.show();
    widget2.show();


    return a.exec();
}
