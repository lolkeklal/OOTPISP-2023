// t6.h
#ifndef T6_H
#define T6_H

#include <QWidget>

namespace Ui {
class t6;
}

class t6 : public QWidget
{
    Q_OBJECT

public:
    explicit t6(QWidget *parent = nullptr);
    ~t6();

private slots:
    void onRunButtonClicked();

private:
    Ui::t6 *ui;
    void processFile(const QString& inputFile, const QString& outputFile);
};

#endif // T6_H
