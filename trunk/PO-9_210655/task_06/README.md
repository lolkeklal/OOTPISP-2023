# Лабораторная работа № 6

## UML - диаграммы

## Зеленков Константин Игореич

## Цель работы

Изучить UML-диаграммы, применить их на практике.

## Задания для выполнения

Создание UML-диаграммы для лабораторной работы №8

```mermaid
---
title: AbstractFactory
---
classDiagram
    class List {
        + render()
        + clone()
    }

    class InputField {
        + render()
        + clone()
    }

    class Button {
        + render()
        + clone()
    }

    class Language {
        + display()
        + clone()
    }

    class WinList {
        + render()
        + clone()
    }

    class WinInputField {
        + render()
        + clone()
    }

    class WinButton {
        + render()
        + clone()
    }

    class WinLanguage {
        + display()
        + clone()
    }

    class AbstractFactory {
        + createList()
        + createInputField()
        + createButton()
        + createLanguage()
    }

    class AbstractPrototypeFactory {
        - listPrototype
        - inputFieldPrototype
        - buttonPrototype
        - languagePrototype
        + createList()
        + createInputField()
        + createButton()
        + createLanguage()
    }

    class WinFactory {
        + createList()
        + createInputField()
        + createButton()
        + createLanguage()
    }

    class SingletonWinFactory {
        - instance
        + getInstance()
        + createList()
        + createInputField()
        + createButton()
        + createLanguage()
    }

    List <|-- WinList
    InputField <|-- WinInputField
    Button <|-- WinButton
    Language <|-- WinLanguage
    AbstractFactory <|-- AbstractPrototypeFactory
    AbstractFactory <|-- WinFactory
    AbstractFactory <|-- SingletonWinFactory
```

```mermaid
---
title: Builder
---
classDiagram
    class Head {
        + getInfo(): string
    }

    class Body {
        + getInfo(): string
    }

    class Engine {
        + getInfo(): string
    }

    class Robot {
        - head: Head
        - body: Body
        - engine: Engine
        + setHead(newHead: Head)
        + setBody(newBody: Body)
        + setEngine(newEngine: Engine)
    }

    class RobotBuilder {
        + buildHead()
        + buildBody()
        + buildEngine()
    }

    class ConcreteRobotBuilder {
        - robot: Robot
        + buildHead()
        + buildBody()
        + buildEngine()
        + getRobot(): Robot
    }

    class Director {
        + buildRobot(builder: RobotBuilder)
    }

    Head --> Robot
    Body --> Robot
    Engine --> Robot
    RobotBuilder <|-- ConcreteRobotBuilder
    Director --> RobotBuilder
    Director --> ConcreteRobotBuilder
````

## Вывод

Изучили UML-диаграммы и применили их на практике.
