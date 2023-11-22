#include <QDebug>
#include <QString>

#include <iostream>
#include <string>

// Части отчета
class Header {
public:
    void print() const {
        qDebug() << "Header\n";
    }
};

class Block {
public:
    void print() const {
        qDebug() << "Block\n";
    }
};

class Ending {
public:
    void print() const {
        qDebug() << "Ending\n";
    }
};

// Строитель отчета
class ReportBuilder {
public:
    virtual void buildHeader() = 0;
    virtual void buildBlock() = 0;
    virtual void buildEnding() = 0;
    virtual QString getResult() const = 0;
};

// Конкретные строители отчета
class HtmlBuilder : public ReportBuilder {
public:
    void buildHeader() override {
        header.print();
    }

    void buildBlock() override {
        block.print();
    }

    void buildEnding() override {
        ending.print();
    }

    QString getResult() const override {
        return "HTML Report";
    }

private:
    Header header;
    Block block;
    Ending ending;
};

class TxtBuilder : public ReportBuilder {
public:
    void buildHeader() override {
        header.print();
    }

    void buildBlock() override {
        block.print();
    }

    void buildEnding() override {
        ending.print();
    }

    QString getResult() const override {
        return "Text Report";
    }

private:
    Header header;
    Block block;
    Ending ending;
};

// Класс-директор
class ReportDirector {
public:
    void construct(ReportBuilder* builder) {
        builder->buildHeader();
        builder->buildBlock();
        builder->buildEnding();
    }
};

//void func() {
//    // Пример использования строителя отчета
//    ReportBuilder* htmlBuilder = new HtmlBuilder();
//    ReportDirector director;
//    director.construct(htmlBuilder);
//    qDebug() << "Report Type: " << htmlBuilder->getResult() << "\n";
//}
