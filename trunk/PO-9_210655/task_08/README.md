# Лабораторная работа №8

## Паттерны проектирования

## Вариант 6

### Зеленков Константин Игоревич

## Цель лабораторной работы

Отработка умений и навыков применения паттернов проектирования.

## Задание №2

- Применить паттерн абстрактная фабрика при построении интерфейса пользователя.
  Продукты фабрики: список, поле ввода, кнопка, язык отображения.

  Применить паттерн проектирования “Prototype” совместно с абстрактной фабрикой, то есть внести изменения в проект “Порождающие паттерны. Абстрактная фабрика”, чтобы абстрактная фабрика параметризировалась прототипами.

  Применить паттерн проектирования “Singleton” совместно с абстрактной фабрикой.

- Применить паттерн “Строитель” для построения представления робота в игровой программе.

  Части: Head, Body, Engine.

  ConcreteBuilder выбрать самостоятельно

  Применить паттерн “Фабричный метод” при создании конкретного строителя и передачи его клиенту.

## Ход работы

Паттерн строитель:

- [Builder.h](./src/Builder.h)

```c++
class Head {
public:
    std::string getInfo() const {
        return "Robot Head";
    }
};

class Body {
public:
    std::string getInfo() const {
        return "Robot Body";
    }
};

class Engine {
public:
    std::string getInfo() const {
        return "Robot Engine";
    }
};

class Robot {
private:
    Head* head{nullptr};
    Body* body{nullptr};
    Engine* engine{nullptr};
public:
    void setHead(Head* newHead) {
        head = newHead;
    }

    void setBody(Body* newBody) {
        body = newBody;
    }

    void setEngine(Engine* newEngine) {
        engine = newEngine;
    }
};

class RobotBuilder {
public:
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    virtual ~RobotBuilder() {}
};

class ConcreteRobotBuilder : public RobotBuilder {
private:
    Robot* robot;

public:
    void buildHead() override {
        robot->setHead(new Head());
    }

    void buildBody() override {
        robot->setBody(new Body());
    }

    void buildEngine() override {
        robot->setEngine(new Engine());
    }

    Robot* getRobot() {
        return robot;
    }
};

class Director {
public:
    void buildRobot(RobotBuilder* builder) {
        builder->buildHead();
        builder->buildBody();
        builder->buildEngine();
    }
};
```

Паттерн абстрактная фабрика:

- [AbstractFactory.h](./src/AbstractFactory.h)

```c++
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
```

- [main.cpp](./src/main.cpp)

```c++
int main() {
    setlocale(LC_ALL, "");

    AbstractFactory* linuxFactory = new WinFactory();

    List* list = linuxFactory->createList();
    InputField* inputField = linuxFactory->createInputField();
    Button* button = linuxFactory->createButton();
    Language* language = linuxFactory->createLanguage();

    list->render();
    inputField->render();
    button->render();
    language->display();

    delete linuxFactory;
    delete list;
    delete inputField;
    delete button;
    delete language;

    return 0;
}
```

## Вывод

В данной лабораторной работе были реализованы паттерны проектирования.
