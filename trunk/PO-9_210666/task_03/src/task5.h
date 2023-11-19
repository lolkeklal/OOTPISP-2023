#ifndef TASK5_H
#define TASK5_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QListView>
#include <QMimeData>

namespace Ui {
class Task5;
}

class Task5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Task5(QWidget *parent = nullptr);
    ~Task5();

private slots:
    void on_createShopsPushButton_clicked();

    void on_shopComboBox_currentIndexChanged(int index);

    void on_addProductPushButton_clicked();

    void on_productsInShopListWidget_itemSelectionChanged();

    void on_getStatisticsPushButton_clicked();

private:
    Ui::Task5 *ui;
    void showEvent(QShowEvent *event) override;
    QStringList products;
    QVector<QVector<bool>>* productsInShops;
    int shopsCount{0};
};

#endif // TASK5_H
