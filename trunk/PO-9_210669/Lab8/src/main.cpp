#include <iostream>
#include <string>

// Абстрактный строитель
class Builder {
public:
    virtual ~Builder() {}
    virtual void buildPart1() = 0;
    virtual void buildPart2() = 0;
    virtual std::string getResult() const = 0;
};

// Конкретный строитель
class ConcreteBuilder : public Builder {
private:
    std::string result;

public:
    void buildPart1() override {
        result += "Building Part1\n";
    }

    void buildPart2() override {
        result += "Building Part2\n";
    }

    std::string getResult() const override {
        return result;
    }
};

// Интерфейс фабрики
class Creator {
public:
    virtual ~Creator() {}
    virtual Builder* createBuilder() const = 0;

    std::string construct() const {
        Builder* builder = createBuilder();

        builder->buildPart1();
        builder->buildPart2();

        std::string result = builder->getResult();

        delete builder;

        return result;
    }
};

// Конкретная фабрика
class ConcreteCreator : public Creator {
public:
    Builder* createBuilder() const override {
        return new ConcreteBuilder();
    }
};

int main() {
    // Клиентский код
    Creator* creator = new ConcreteCreator();
    std::string result = creator->construct();

    std::cout << "Construction result:\n" << result;

    delete creator;

    return 0;
}
