#include <iostream>
#include "AbstractFactory.h"
#include "Builder.h"

int main() {
    // Abstract Factory Pattern
    std::cout << "Abstract Factory Pattern:\n";
    AbstractFactory* factory = new PlannerAppFactory();
    List* list = factory->createList();
    InputField* inputField = factory->createInputField();
    Button* button = factory->createButton();
    Language* language = factory->createLanguage();

    list->render();
    inputField->render();
    button->render();
    language->display();

    delete list;
    delete inputField;
    delete button;
    delete language;
    delete factory;

    std::cout << "\n";

    // Singleton Pattern
    std::cout << "Singleton Pattern:\n";
    SingletonPlannerAppFactory* singletonFactory = SingletonPlannerAppFactory::getInstance();
    list = singletonFactory->createList();
    inputField = singletonFactory->createInputField();
    button = singletonFactory->createButton();
    language = singletonFactory->createLanguage();

    list->render();
    inputField->render();
    button->render();
    language->display();

    delete list;
    delete inputField;
    delete button;
    delete language;

    std::cout << "\n";

    // Prototype Pattern
    std::cout << "Prototype Pattern:\n";
    AbstractFactory* prototypeFactory = new AbstractPrototypeFactory(new PlannerAppList(), new PlannerAppInputField(), new PlannerAppButton(), new PlannerAppLanguage());
    list = prototypeFactory->createList();
    inputField = prototypeFactory->createInputField();
    button = prototypeFactory->createButton();
    language = prototypeFactory->createLanguage();

    list->render();
    inputField->render();
    button->render();
    language->display();

    delete list;
    delete inputField;
    delete button;
    delete language;
    delete prototypeFactory;

    std::cout << "\n";

    // Builder Pattern
    std::cout << "Builder Pattern:\n";
    Director director;
    ConcreteRobotBuilder robotBuilder;
    director.buildRobot(&robotBuilder);
    Robot* robot = robotBuilder.getRobot();

    std::cout << "Built a robot with: " << robot->getHead()->getInfo() << ", " << robot->getBody()->getInfo() << ", " << robot->getEngine()->getInfo() << std::endl;

    delete robot;
    return 0;
}
