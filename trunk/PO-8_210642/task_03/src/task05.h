#ifndef TASK05_H
#define TASK05_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMap>

class Task05Window : public QWidget
{
    Q_OBJECT

public:
    Task05Window(QWidget *parent = nullptr);
    ~Task05Window();

private slots:
    void processNames();

private:
    QLineEdit *inputClass1;
    QLineEdit *inputClass2;
    QLineEdit *inputClass3;
    QTextEdit *resultTextEdit;
};

#endif // TASK05_H
