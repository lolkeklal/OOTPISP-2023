#include <QDebug>

#include <iostream>

// Продукты
class Product {
public:
    virtual void use() const = 0;
};

class ConcreteProduct : public Product {
public:
    void use() const override {
        qDebug() << "Using Concrete Product\n";
    }
};

// Абстрактная фабрика
class Factory {
public:
    virtual Product* createProduct() const = 0;
};

// Конкретные фабрики
class ConcreteFactory : public Factory {
public:
    Product* createProduct() const override {
        return new ConcreteProduct();
    }
};

// Клиентский код
void clientCode(const Factory& factory) {
    Product* product = factory.createProduct();
    product->use();
    delete product;
}

//void func() {
//    // Пример использования фабричного метода с абстрактной фабрикой
//    ConcreteFactory concreteFactory;
//    clientCode(concreteFactory);
//}
