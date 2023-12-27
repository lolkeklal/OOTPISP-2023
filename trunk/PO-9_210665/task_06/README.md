# Лабораторная работа № 6 #

## UML - диаграммы ##

## Цель работы ##

Осознать эти диаграммы хоть немного, а ото ведь позорник и не
разбираюсь совсем.

## Задания для выполнения ##

Задание UML для лабораторной по паттернам.

В диаграмме описываются связи между классами
фабрик, частей, наследования....

Диаграмма как есть, но Mermaid:

```mermaid
---
title: Abstract Factory
---
classDiagram
    conBody <|-- Body
    conHead <|-- Head
    conEnding <|-- Ending
    SingletonFactory <|-- AbstractFactory
    Factory <|-- AbstractFactory
    AbstractPrototypeFactory <|-- AbstractFactory
    AbstractPrototypeFactory o-- Head
    AbstractPrototypeFactory o-- Body
    AbstractPrototypeFactory o-- Ending
    Factory <-- Head
    Factory <-- Body
    Factory <-- Ending
    SingletonFactory <-- Head
    SingletonFactory <-- Body
    SingletonFactory <-- Ending

    class Head {
    +virtual render()
    +virtual clone()
}

class Body {
    +virtual render()
    +virtual clone()
}

class Ending {
    +virtual render()
    +virtual clone()
}

class conHead{
    +render()
    +clone()
}

class conBody{
    +render()
    +clone()
}

class conEnding{
    +render()
    +clone()
}



class AbstractFactory {
    +virtual Head* createHead()
    +virtual Body* createBody()
    +virtual Ending* createEnding()
}

class AbstractPrototypeFactory{
    +AbstractPrototypeFactory(Head* h,  Body* b, Ending* e)
    +Head* createHead()
    +Body* createBody()
    +Ending* createEnding()
    -Head* headPrototype
    -Body* bodyPrototype
    -Ending* endingPrototype
}


class Factory{
    +Head* createHead()
    +Body* createBody()
    +Ending* createEnding()
}


class SingletonFactory{
    -static SingletonFactory* instance
    +static SingletonFactory* getInstance()
    +Head* createHead()
    +Body* createBody()
    +Ending* createEnding()
}
```

## Вывод ##

Я разобрался c UML и осознав, что всякая программа требует документации, принял mermaid.
