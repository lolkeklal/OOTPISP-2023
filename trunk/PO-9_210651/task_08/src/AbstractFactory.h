#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>

class List {
public:
    virtual void render() const = 0;
    virtual List* clone() = 0;
    virtual ~List() {}
};

class InputField {
public:
    virtual void render() const = 0;
    virtual InputField* clone() = 0;
    virtual ~InputField() {}
};

class Button {
public:
    virtual void render() const = 0;
    virtual Button* clone() = 0;
    virtual ~Button() {}
};

class Language {
public:
    virtual void display() const = 0;
    virtual Language* clone() = 0;
    virtual ~Language() {}
};


class SomeAppList : public List {
public:
    void render() const override {
        std::cout << "Some App List" << std::endl;
    }

    List* clone() override {
        return new SomeAppList();
    }
};

class SomeAppInputField : public InputField {
public:
    void render() const override {
        std::cout << "Some App Input Field" << std::endl;
    }

    InputField* clone() override {
        return new SomeAppInputField();
    }
};

class SomeAppButton : public Button {
public:
    void render() const override {
        std::cout << "Some App Button" << std::endl;
    }

    Button* clone() override {
        return new SomeAppButton();
    }
};

class SomeAppLanguage : public Language {
public:
    void display() const override {
        std::cout << "Some App language" << std::endl;
    }

    Language* clone() override {
        return new SomeAppLanguage();
    }
};


class AbstractFactory {
public:
    virtual List* createList() const = 0;
    virtual InputField* createInputField() const = 0;
    virtual Button* createButton() const = 0;
    virtual Language* createLanguage() const = 0;
    virtual ~AbstractFactory() {}
};

class AbstractPrototypeFactory : public AbstractFactory {
public:
    AbstractPrototypeFactory(List* ls,  InputField* ifl, Button* btn, Language* lng) {
        listPrototype = ls;
        inputFieldPrototype = ifl;
        buttonPrototype = btn;
        languagePrototype = lng;
    }

    virtual ~AbstractPrototypeFactory() {
        delete listPrototype;
        delete inputFieldPrototype;
        delete buttonPrototype;
        delete languagePrototype;
    }

    List* createList() const override {
        return listPrototype->clone();
    }

    InputField* createInputField() const override {
        return inputFieldPrototype->clone();
    }

    Button* createButton() const override {
        return buttonPrototype->clone();
    }

    Language* createLanguage() const override {
        return languagePrototype->clone();
    }
private:
    List* listPrototype;
    InputField* inputFieldPrototype;
    Button* buttonPrototype;
    Language* languagePrototype;
};


class SomeAppFactory : public AbstractFactory {
public:
    List* createList() const override {
        return new SomeAppList();
    }

    InputField* createInputField() const override {
        return new SomeAppInputField();
    }

    Button* createButton() const override {
        return new SomeAppButton();
    }

    Language* createLanguage() const override {
        return new SomeAppLanguage();
    }
};


class SingletonSomeAppFactory : public AbstractFactory {
private:
    SingletonSomeAppFactory() {}
    static SingletonSomeAppFactory* instance;

public:
    static SingletonSomeAppFactory* getInstance() {
        if (instance == nullptr) {
            instance = new SingletonSomeAppFactory();
        }
        return instance;
    }

    List* createList() const override {
        return new SomeAppList();
    }

    InputField* createInputField() const override {
        return new SomeAppInputField();
    }

    Button* createButton() const override {
        return new SomeAppButton();
    }

    Language* createLanguage() const override {
        return new SomeAppLanguage();
    }
};

SingletonSomeAppFactory* SingletonSomeAppFactory::instance = nullptr;

#endif // ABSTRACTFACTORY_H
