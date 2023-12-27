#include "task05.h"

Task05Window::Task05Window(QWidget *parent)
    : QWidget(parent)
{
    inputClass1 = new QLineEdit(this);
    inputClass2 = new QLineEdit(this);
    inputClass3 = new QLineEdit(this);

    QPushButton *processButton = new QPushButton("Process Names", this);
    connect(processButton, &QPushButton::clicked, this, &Task05Window::processNames);

    resultTextEdit = new QTextEdit(this);
    resultTextEdit->setReadOnly(true);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(inputClass1);
    mainLayout->addWidget(inputClass2);
    mainLayout->addWidget(inputClass3);
    mainLayout->addWidget(processButton);
    mainLayout->addWidget(resultTextEdit);

    setLayout(mainLayout);
}

Task05Window::~Task05Window()
{
}

void Task05Window::processNames()
{
    QStringList namesClass1 = inputClass1->text().split(' ', Qt::SkipEmptyParts);
    QStringList namesClass2 = inputClass2->text().split(' ', Qt::SkipEmptyParts);
    QStringList namesClass3 = inputClass3->text().split(' ', Qt::SkipEmptyParts);

    QStringList commonNames;
    QSet<QString> uniqueNames;

    for (const QString &name : namesClass1)
    {
        uniqueNames.insert(name);
        if (namesClass2.contains(name) && namesClass3.contains(name))
            commonNames.append(name);
    }

    for (const QString &name : namesClass2)
    {
        uniqueNames.insert(name);
        if (namesClass1.contains(name) && namesClass3.contains(name))
            commonNames.append(name);
    }

    for (const QString &name : namesClass3)
    {
        uniqueNames.insert(name);
        if (namesClass1.contains(name) && namesClass2.contains(name))
            commonNames.append(name);
    }

    QSet<QString> uniqueNamesClass1 = uniqueNames - QSet<QString>(namesClass2.begin(), namesClass2.end()) - QSet<QString>(namesClass3.begin(), namesClass3.end());
    QSet<QString> uniqueNamesClass2 = uniqueNames - QSet<QString>(namesClass1.begin(), namesClass1.end()) - QSet<QString>(namesClass3.begin(), namesClass3.end());
    QSet<QString> uniqueNamesClass3 = uniqueNames - QSet<QString>(namesClass1.begin(), namesClass1.end()) - QSet<QString>(namesClass2.begin(), namesClass2.end());

    QString resultText = "Common Names: " + commonNames.join(", ") + "\n\n";
    resultText += "Unique Names in Class 1: " + QStringList(uniqueNamesClass1.values()).join(", ") + "\n";
    resultText += "Unique Names in Class 2: " + QStringList(uniqueNamesClass2.values()).join(", ") + "\n";
    resultText += "Unique Names in Class 3: " + QStringList(uniqueNamesClass3.values()).join(", ");

    resultTextEdit->setPlainText(resultText);
}
