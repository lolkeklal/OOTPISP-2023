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
    void render() const override {
        std::cout << "head otchete" << std::endl;
    }

    Head* clone() override {
        return new conHead();
    }
};

class conBody : public Body {
public:
    void render() const override {
        std::cout << "body otcheta" << std::endl;
    }

    Body* clone() override {
        return new conBody();
    }
};

class conEnding : public Ending {
public:
    void render() const override {
        std::cout << "Ending otcheta" << std::endl;
    }

    Ending* clone() override {
        return new conEnding();
    }
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
    AbstractPrototypeFactory(Head* h,  Body* b, Ending* e) {
        headPrototype = h;
        bodyPrototype = b;
        endingPrototype = e;
    }

    virtual ~AbstractPrototypeFactory() {
        delete headPrototype;
        delete bodyPrototype;
        delete endingPrototype;
    }

    Head* createHead() const override {
        return headPrototype->clone();
    }

    Body* createBody() const override {
        return bodyPrototype->clone();
    }

    Ending* createEnding() const override {
        return endingPrototype->clone();
    }
private:
    Head* headPrototype;
    Body* bodyPrototype;
    Ending* endingPrototype;
};


class LinuxFactory : public AbstractFactory {
public:
    Head* createHead() const override {
        return new conHead();
    }

    Body* createBody() const override {
        return new conBody();
    }

    Ending* createEnding() const override {
        return new conEnding();
    }
};


class SingletonFactory : public AbstractFactory {
private:
    SingletonFactory() {}
    static SingletonFactory* instance;

public:
    static SingletonFactory* getInstance() {
        if (instance == nullptr) {
            instance = new SingletonFactory();
        }
        return instance;
    }

    Head* createHead() const override {
        return new conHead();
    }

    Body* createBody() const override {
        return new conBody();
    }

    Ending* createEnding() const override {
        return new conEnding();
    }
};

SingletonFactory* SingletonFactory::instance = nullptr;

#endif // ABSTRACTFACTORY_H
