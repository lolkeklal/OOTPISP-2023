#include "t5.h"
#include "ui_t5.h"

t5::t5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t5)
{
    ui->setupUi(this);
    this->solveFishTask();
}

t5::~t5()
{
    delete ui;
}

void t5::solveFishTask() {
    QSet<QString> allFish = {"лосось", "окунь", "щука", "карп", "карась", "селедка"};
    QString label("allFish set: {лосось, окунь, щука, карп}\n\n");

    QSet<QString> fisherman1 = {"лосось", "окунь"};
    label += "Fisher1: {\"лосось\", \"окунь\"}\n";
    QSet<QString> fisherman2 = {"щука", "карп"};
    label += "Fisher2: {\"щука\", \"карп\"}\n";
    QSet<QString> fisherman3 = {"лосось", "карп"};
    label += "Fisher3: {\"лосось\", \"карп\"}\n\n";

    QSet<QString> notCaughtFish = allFish;

    notCaughtFish -= fisherman1;
    notCaughtFish -= fisherman2;
    notCaughtFish -= fisherman3;

    label += "Uncatched fish: {";
    for (auto it = notCaughtFish.begin(); it != notCaughtFish.end(); it++) {
        if (it != notCaughtFish.begin()) label += ", ";
        label += "\"" + *it + "\"";
    }
    label += "}";

    ui->label->setText(label);
}
