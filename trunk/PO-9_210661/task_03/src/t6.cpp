// t6.cpp
#include "t6.h"
#include "ui_t6.h"
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <algorithm>

t6::t6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t6)
{
    ui->setupUi(this);
    setWindowTitle("t6");

    // Связываем слот с сигналом кнопки "Run"
    connect(ui->runButton, &QPushButton::clicked, this, &t6::onRunButtonClicked);

    // Инициализация при первом запуске
    onRunButtonClicked();
}

t6::~t6()
{
    delete ui;
}

void t6::onRunButtonClicked()
{
    processFile(ui->inputFile->text(),ui->outputFile->text());
}

void t6::processFile(const QString& inputFile, const QString& outputFile) {
    qDebug() << "Input file path:" << inputFile;
    qDebug() << "Output file path:" << outputFile;

    // Чтение файла f
    QFile inFile(inputFile);
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open input file";
        return;
    }

    QTextStream inStream(&inFile);
    QVector<int> fileData;

    while (!inStream.atEnd()) {
        QString line = inStream.readLine();
        bool conversionOk = false;
        int value = line.toInt(&conversionOk);
        if (conversionOk) {
            fileData.append(value);
        }
    }

    inFile.close();

    // Запись в файл g
    QFile outFile(outputFile);
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not open output file";
        return;
    }

    QTextStream outStream(&outFile);

    int groupSize = 5;
    int groups = (fileData.size() + groupSize - 1) / groupSize;

    for (int i = 0; i < groups; ++i) {
        int start = i * groupSize;
        int end = std::min((i + 1) * groupSize, static_cast<int>(fileData.size()));
        int maxElement = *std::max_element(fileData.begin() + start, fileData.begin() + end);

        outStream << maxElement << "\n";
    }

    outFile.close();
}
