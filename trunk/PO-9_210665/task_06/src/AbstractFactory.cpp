#include "AbstractFactory.h"

void conHead::render() const {
    std::cout << "head otchete" << std::endl;
}
Head* conHead::clone() {
    return new conHead();
}




void conBody::render() const {
    std::cout << "body otcheta" << std::endl;
}
Body* conBody::clone() {
    return new conBody();
}





void conEnding::render() const  {
    std::cout << "Ending otcheta" << std::endl;
}
Ending* conEnding::clone()  {
    return new conEnding();
}





AbstractPrototypeFactory::AbstractPrototypeFactory(Head* h,  Body* b, Ending* e) {
    headPrototype = h;
    bodyPrototype = b;
    endingPrototype = e;
}

AbstractPrototypeFactory::~AbstractPrototypeFactory() {
    delete headPrototype;
    delete bodyPrototype;
    delete endingPrototype;
}

Head* AbstractPrototypeFactory::createHead() const {
    return headPrototype->clone();
}

Body* AbstractPrototypeFactory::createBody() const {
    return bodyPrototype->clone();
}

Ending* AbstractPrototypeFactory::createEnding() const {
    return endingPrototype->clone();
}





Head* Factory::createHead() const {
    return new conHead();
}

Body* Factory::createBody() const {
    return new conBody();
}

Ending* Factory::createEnding() const {
    return new conEnding();
}




SingletonFactory::SingletonFactory() {}

SingletonFactory* SingletonFactory::getInstance() {
    if (instance == nullptr) {
        instance = new SingletonFactory();
    }
    return instance;
}

Head* SingletonFactory::createHead() const {
    return new conHead();
}

Body* SingletonFactory::createBody() const {
    return new conBody();
}

Ending* SingletonFactory::createEnding() const {
    return new conEnding();
}
