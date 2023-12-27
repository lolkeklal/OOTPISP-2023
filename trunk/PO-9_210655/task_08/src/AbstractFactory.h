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


class WinList : public List {
public:
    void render() const override {
        std::cout << "Windows list" << std::endl;
    }

    List* clone() override {
        return new WinList();
    }
};

class WinInputField : public InputField {
public:
    void render() const override {
        std::cout << "Windows input field" << std::endl;
    }

    InputField* clone() override {
        return new WinInputField();
    }
};

class WinButton : public Button {
public:
    void render() const override {
        std::cout << "Windows button" << std::endl;
    }

    Button* clone() override {
        return new WinButton();
    }
};

class WinLanguage : public Language {
public:
    void display() const override {
        std::cout << "Russian language" << std::endl;
    }

    Language* clone() override {
        return new WinLanguage();
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


class WinFactory : public AbstractFactory {
public:
    List* createList() const override {
        return new WinList();
    }

    InputField* createInputField() const override {
        return new WinInputField();
    }

    Button* createButton() const override {
        return new WinButton();
    }

    Language* createLanguage() const override {
        return new WinLanguage();
    }
};


class SingletonWinFactory : public AbstractFactory {
private:
    SingletonWinFactory() {}
    static SingletonWinFactory* instance;

public:
    static SingletonWinFactory* getInstance() {
        if (instance == nullptr) {
            instance = new SingletonWinFactory();
        }
        return instance;
    }

    List* createList() const override {
        return new WinList();
    }

    InputField* createInputField() const override {
        return new WinInputField();
    }

    Button* createButton() const override {
        return new WinButton();
    }

    Language* createLanguage() const override {
        return new WinLanguage();
    }
};

SingletonWinFactory* SingletonWinFactory::instance = nullptr;

#endif // ABSTRACTFACTORY_H
