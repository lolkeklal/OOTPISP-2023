// t3.h
#ifndef T3_H
#define T3_H

#include <QWidget>
#include <QList>

namespace Ui {
class t3;
}

class t3 : public QWidget
{
    Q_OBJECT

public:
    explicit t3(QWidget *parent = nullptr);
    ~t3();

private slots:
    void onDoItButtonClicked();

private:
    Ui::t3 *ui;
    QList<int> list1;
    QList<int> list2;

    QString listToString(const QList<int>& list, const QString& separator);
    // Добавляем QTextEdit для вывода результатов
    void updateOutputText(const QString& text);
};

#endif // T3_H
