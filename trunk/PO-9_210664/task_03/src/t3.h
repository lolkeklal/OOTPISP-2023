#ifndef T3_H
#define T3_H

#include <QWidget>

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
    void on_pushButton_clicked();

private:
    Ui::t3 *ui;

    static void fillRandom(QList<int>& list, int size);
    static void fillRandom(std::list<int>& list, int size);
    static QString listToString(const QList<int>& list);
    static void replacePositiveWithMin(QList<int>& list1, const QList<int>& list2);
    static void removeElementsGreaterThanK(std::list<int>& linkedList, int k);
};

#endif // T3_H
