#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>

class Head {
public:
    virtual void render() const = 0;
    virtual Head* clone() = 0;
    virtual ~Head() {}
};

class Body {
public:
    virtual void render() const = 0;
    virtual Body* clone() = 0;
    virtual ~Body() {}
};

class Ending {
public:
    virtual void render() const = 0;
    virtual Ending* clone() = 0;
    virtual ~Ending() {}
};

class conHead : public Head {
public:
    void render() const override;

    Head* clone() override;
};

class conBody : public Body {
public:
    void render() const override;

    Body* clone() override;
};

class conEnding : public Ending {
public:
    void render() const override;

    Ending* clone() override;
};



class AbstractFactory {
public:
    virtual Head* createHead() const = 0;
    virtual Body* createBody() const = 0;
    virtual Ending* createEnding() const = 0;
    virtual ~AbstractFactory() {}
};

class AbstractPrototypeFactory : public AbstractFactory {
public:
    AbstractPrototypeFactory(Head* h,  Body* b, Ending* e);

    virtual ~AbstractPrototypeFactory();

    Head* createHead() const override;

    Body* createBody() const override;

    Ending* createEnding() const override;
private:
    Head* headPrototype;
    Body* bodyPrototype;
    Ending* endingPrototype;
};


class Factory : public AbstractFactory {
public:
    Head* createHead() const override;
    Body* createBody() const override;
    Ending* createEnding() const override;
};


class SingletonFactory : public AbstractFactory {
private:
    SingletonFactory();
     SingletonFactory* instance;

public:
     SingletonFactory* getInstance();

    Head* createHead() const override;

    Body* createBody() const override;

    Ending* createEnding() const override;
};

//SingletonFactory* SingletonFactory::instance = nullptr;

#endif // ABSTRACTFACTORY_H
