#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>
#include <string>

class Head {
public:
    std::string getInfo() const {
        return "Head";
    }
};

class Body {
public:
    std::string getInfo() const {
        return "Body";
    }
};

class Ending {
public:
    std::string getInfo() const {
        return "Ending";
    }
};

class FILA {
private:
    Head* head{nullptr};
    Body* body{nullptr};
    Ending* ending{nullptr};
public:
    void setHead(Head* newHead) {
        head = newHead;
    }

    void setBody(Body* newBody) {
        body = newBody;
    }

    void setEnding(Ending* newEnding) {
        ending = newEnding;
    }
};

class Builder {
public:
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildEnding() = 0;
    virtual ~Builder() {}
};

class ConcreteBuilder : public Builder {
private:
    FILA* fila;

public:
    void buildHead() override {
        fila->setHead(new Head());
    }

    void buildBody() override {
        fila->setBody(new Body());
    }

    void buildEnding() override {
        fila->setEnding(new Ending());
    }

    FILA* getFILA() {
        return fila;
    }
};

class Director {
public:
    void buildFILA(Builder* builder) {
        builder->buildHead();
        builder->buildBody();
        builder->buildEnding();
    }
};

#endif // BUILDER_H
