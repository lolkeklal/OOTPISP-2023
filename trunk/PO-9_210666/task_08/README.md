# Лабораторная работа №8

## Паттерны проектирования

## Вариант 17

## Цель лабораторной работы

Отработка умений и навыков применения паттернов проектирования.

## Задание №2
- Применить паттерн абстрактная фабрика при построении интерфейса пользователя. 
  Продукты фабрики: список, поле ввода, кнопка, язык отображения. 
  
  Применить паттерн проектирования “Prototype” совместно с абстрактной фабрикой, то есть внести изменения в проект “Порождающие паттерны. Абстрактная фабрика”, чтобы абстрактная фабрика параметризировалась прототипами.

  Применить паттерн проектирования  “Singleton” совместно с абстрактной фабрикой.

- Применить паттерн “Строитель” для построения представления робота в игровой программе.
  
  Части: Head, Body, Engine.
  
  ConcreteBuilder выбрать самостоятельно

  Применить паттерн  “Фабричный метод” при создании конкретного строителя и передачи его клиенту. 


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
};

class AbstractPrototypeFactory : public AbstractFactory {
public:
    AbstractPrototypeFactory(List* ls,  InputField* ifl, Button* btn, Language* lng) {
        listPrototype = ls;
        inputFieldPrototype = ifl;
        buttonPrototype = btn;
        languagePrototype = lng;
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
```

## Вывод

Я реализовал паттерны проектирования.
