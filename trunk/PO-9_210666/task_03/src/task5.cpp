#include "task5.h"
#include "ui_task5.h"

Task5::Task5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Task5)
{
    ui->setupUi(this);

    setWindowTitle("Task 5");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    QRegularExpression exprNum("([1-9][0-9]*)");
    QValidator *validatorNum = new QRegularExpressionValidator(exprNum, this);
    ui->shopsCountLineEdit->setValidator(validatorNum);
}

void Task5::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
}
Task5::~Task5()
{
    delete ui;
}

void Task5::on_createShopsPushButton_clicked()
{
    if (!ui->shopsCountLineEdit->text().isEmpty()){
        ui->shopsCountLineEdit->setReadOnly(true);
        ui->createShopsPushButton->setHidden(true);

        this->shopsCount = ui->shopsCountLineEdit->text().toInt();
        int productsCount = products.count();
        productsInShops = new QVector<QVector<bool>>(shopsCount, QVector<bool>(productsCount, false));
        for (int i = 0; i < shopsCount; ++i) {
            ui->shopComboBox->addItem(QString("shop %1").arg(i + 1));
        }
    }
}


void Task5::on_shopComboBox_currentIndexChanged(int index)
{
    QSignalBlocker blocker(ui->productsInShopListWidget);
    ui->productsInShopListWidget->clear();
    int productsCount = products.count();
    for (int i = 0; i < productsCount; ++i) {
        ui->productsInShopListWidget->addItem(products[i]);
        if (productsInShops->at(index)[i]){
            ui->productsInShopListWidget->setCurrentRow(i);
        }
    }
    blocker.unblock();
}


void Task5::on_addProductPushButton_clicked()
{
    QString productName = ui->productNameLineEdit->text();
    if (!productName.isEmpty() && !products.contains(productName)){
        ui->productNameLineEdit->clear();
        products.append(productName);
        if (this->shopsCount){
            for (QVector<bool> &prods : *productsInShops) {
                prods.append(false);
                Task5::on_shopComboBox_currentIndexChanged(ui->shopComboBox->currentIndex());
            }
        }
    }
}


void Task5::on_productsInShopListWidget_itemSelectionChanged()
{
    int shopIndex = ui->shopComboBox->currentIndex();
    QList<QListWidgetItem*> selectedItems = ui->productsInShopListWidget->selectedItems();
    int productsCount = products.count(), productIndex;
    for (int i = 0; i < productsCount; ++i) {
        (*productsInShops)[shopIndex].replace(i, false);
    }
    for (QListWidgetItem* item : selectedItems) {
        productIndex = ui->productsInShopListWidget->row(item);
        (*productsInShops)[shopIndex].replace(productIndex, true);
    }
}


void Task5::on_getStatisticsPushButton_clicked()
{
    if (this->shopsCount){
        ui->productsInAllShopsPlainTextEdit->clear();
        ui->productsInShopsSplainTextEdit->clear();
        ui->productsNotInShopsPlainTextEdit->clear();
        int productInStores;
        for (int productIndex = 0; productIndex < products.count(); ++productIndex) {
            productInStores = 0;
            for (int shopIndex = 0; shopIndex < shopsCount; ++shopIndex) {
                if ((*productsInShops)[shopIndex][productIndex]){
                    productInStores++;
                }
            }
            if (productInStores == 0){
                ui->productsNotInShopsPlainTextEdit->appendPlainText(products[productIndex]);
            }
            else if (productInStores == this->shopsCount){
                ui->productsInAllShopsPlainTextEdit->appendPlainText(products[productIndex]);
            }
            else {
                ui->productsInShopsSplainTextEdit->appendPlainText(products[productIndex]);
            }
        }
    }
}

