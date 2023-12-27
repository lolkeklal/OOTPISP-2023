// t5.cpp
#include "t5.h"
#include "ui_t5.h"
#include <QStack>
#include <QQueue>
#include <QRandomGenerator>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <QString>

class Product {
public:
    Product(const std::string& name, double price, Ui::t5* ui) : name(name), price(price), ui(ui) {}

    QString display() const {
        QString str = "Product: " + QString::fromStdString(name) + ", Price: $" + QString::number(price) + "\n";
        return str;
    }

private:
    std::string name;
    double price;
    Ui::t5* ui;
};

class Shop {
public:
    Shop(Ui::t5* ui) : ui(ui) {}

    void addProduct(const Product& product) {
        products.push_back(product);
    }

    QString displayProducts() const {
        QString str = "Shop Inventory:\n";
        for (const auto& product : products) {
            str += product.display();
        }
        str += "\n";
        return str;
    }

private:
    std::vector<Product> products;
    Ui::t5* ui;
};

t5::t5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t5)
{
    ui->setupUi(this);
    setWindowTitle("t5");

    // Связываем слот с сигналом кнопки "Run"
    connect(ui->runButton, &QPushButton::clicked, this, &t5::onRunButtonClicked);

    // Инициализация при первом запуске
    onRunButtonClicked();
}

t5::~t5()
{
    delete ui;
}

void t5::onRunButtonClicked()
{
    srand(time(nullptr));
    QString fullText = "";

    const int numShops = 3;
    const int maxProductsPerShop = 5;

    std::vector<Shop> shops;

    for (int i = 0; i < numShops; ++i) {
        Shop shop(ui); // Pass the ui pointer to the Shop constructor

        int numProducts = rand() % (maxProductsPerShop + 1);

        for (int j = 0; j < numProducts; ++j) {
            std::string productName = "Product" + std::to_string(j + 1);
            double productPrice = (rand() % 1000) / 10.0; // Random price between 0 and 100
            Product product(productName, productPrice, ui); // Pass the ui pointer to the Product constructor
            shop.addProduct(product);
        }

        shops.push_back(shop);
    }

    // Display the inventory of each shop
    for (int i = 0; i < numShops; ++i) {
        // Отображаем результаты в текстовых виджетах
        fullText += "Shop " + QString::number(i + 1) + "\n";
        fullText += shops[i].displayProducts();
    }
    ui->infoTextEdit->clear();
    ui->infoTextEdit->append(fullText);
}
