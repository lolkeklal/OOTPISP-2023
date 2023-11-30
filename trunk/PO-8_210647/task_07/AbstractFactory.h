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


class LinuxList : public List {
public:
    void render() const override {
        std::cout << "linux list" << std::endl;
    }

    List* clone() override {
        return new LinuxList();
    }
};

class LinuxInputField : public InputField {
public:
    void render() const override {
        std::cout << "linux input field" << std::endl;
    }

    InputField* clone() override {
        return new LinuxInputField();
    }
};

class LinuxButton : public Button {
public:
    void render() const override {
        std::cout << "linux button" << std::endl;
    }

    Button* clone() override {
        return new LinuxButton();
    }
};

class LinuxLanguage : public Language {
public:
    void display() const override {
        std::cout << "English лангуаге" << std::endl;
    }

    Language* clone() override {
        return new LinuxLanguage();
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


class LinuxFactory : public AbstractFactory {
public:
    List* createList() const override {
        return new LinuxList();
    }

    InputField* createInputField() const override {
        return new LinuxInputField();
    }

    Button* createButton() const override {
        return new LinuxButton();
    }

    Language* createLanguage() const override {
        return new LinuxLanguage();
    }
};


class SingletonLinuxFactory : public AbstractFactory {
private:
    SingletonLinuxFactory() {}
    static SingletonLinuxFactory* instance;

public:
    static SingletonLinuxFactory* getInstance() {
        if (instance == nullptr) {
            instance = new SingletonLinuxFactory();
        }
        return instance;
    }

    List* createList() const override {
        return new LinuxList();
    }

    InputField* createInputField() const override {
        return new LinuxInputField();
    }

    Button* createButton() const override {
        return new LinuxButton();
    }

    Language* createLanguage() const override {
        return new LinuxLanguage();
    }
};

SingletonLinuxFactory* SingletonLinuxFactory::instance = nullptr;

#endif // ABSTRACTFACTORY_H
