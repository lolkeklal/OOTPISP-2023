# Отчет по лабораторной работе №8

## Паттерны проектирования

## Вариант №15

> \[!NOTE]
> Был выбран **вариант №3**. Так как всего 3 варианта, находим
> `15 % 3 = 0`

Вариант ~~ы~~ :

3\. Применить паттерн абстрактная фабрика при построении логической структуры лабиринта. Продукты фабрики: комната, дверь.

Применить паттерн проектирования “Prototype” совместно с абстрактной фабрикой. То есть теперь в проекте абстрактная фабрика должна параметризоваться прототипами.

Применить паттерн проектирования  “Singleton” совместно с абстрактной фабрикой.

Применить паттерн “Строитель” для построения:

- Отчета по частям

  - Части: Header – Заголовок, Block – Блок содержащий данные по отчету (результат SQL запроса), Ending – Концевик

  - ConcreteBuilder: HtmlBuilder, TxtBuilder, XlsBuilder, DocBuilder

- Представления робота в игровой программе

  - Части: Head, Body, Engine

  - ConcreteBuilder выбрать самостоятельно

- Представления лица героя в ролевой игровой программе
  - Части: Eyes  - параметры (Color, Figure), Nose (Color , Figure), Mouth (Color, Figure), Ears (Color, Figure), Hair (Color, Figure)

  - ConcreteBuilder: UglyFaceBuilder, GoodFaceBuilder, SmileFaceBuilder

Применить паттерн  “Фабричный метод” при создании конкретного строителя и передачи его клиенту.  Самостоятельно продумать контекст в каркасе для вызова шаблонного метода.

## Код программы

- [AbstructFactoryWithPrototypes.cpp](./src/AbstructFactory.cpp)

  ```c++
  #include <QDebug>

  #include <iostream>
  #include <map>

  // Прототипы
  class Room {
  public:
      virtual void print() const = 0;
      virtual Room* clone() const = 0;
  };

  class Door {
  public:
      virtual void print() const = 0;
      virtual Door* clone() const = 0;
  };

  // Абстрактная фабрика
  class MazeFactory {
  public:
      virtual Room* makeRoom() const = 0;
      virtual Door* makeDoor(Room* r1, Room* r2) const = 0;
      virtual Room* cloneRoom(const Room* room) const = 0;
      virtual Door* cloneDoor(const Door* door) const = 0;
  };

  // Пример конкретных продуктов
  class ConcreteRoom : public Room {
  public:
      void print() const override {
          qDebug() << "Concrete Room\n";
      }

      Room* clone() const override {
          return new ConcreteRoom(*this);
      }
  };

  class ConcreteDoor : public Door {
  public:
      ConcreteDoor(Room* r1, Room* r2) : room1(r1), room2(r2) {}

      void print() const override {
          qDebug() << "Concrete Door\n";
      }

      Door* clone() const override {
          return new ConcreteDoor(*this);
      }

  private:
      Room* room1;
      Room* room2;
  };

  // Пример конкретной фабрики
  class ConcreteMazeFactory : public MazeFactory {
  public:
      Room* makeRoom() const override {
          return new ConcreteRoom();
      }

      Door* makeDoor(Room* r1, Room* r2) const override {
          return new ConcreteDoor(r1, r2);
      }

      Room* cloneRoom(const Room* room) const override {
          return room->clone();
      }

      Door* cloneDoor(const Door* door) const override {
          return door->clone();
      }
  };

  ```

- [Builder.cpp](./src/Builder.cpp)

  ```c++
  #include <QDebug>
  #include <QString>

  #include <iostream>
  #include <string>

  // Части отчета
  class Header {
  public:
      void print() const {
          qDebug() << "Header\n";
      }
  };

  class Block {
  public:
      void print() const {
          qDebug() << "Block\n";
      }
  };

  class Ending {
  public:
      void print() const {
          qDebug() << "Ending\n";
      }
  };

  // Строитель отчета
  class ReportBuilder {
  public:
      virtual void buildHeader() = 0;
      virtual void buildBlock() = 0;
      virtual void buildEnding() = 0;
      virtual QString getResult() const = 0;
  };

  // Конкретные строители отчета
  class HtmlBuilder : public ReportBuilder {
  public:
      void buildHeader() override {
          header.print();
      }

      void buildBlock() override {
          block.print();
      }

      void buildEnding() override {
          ending.print();
      }

      QString getResult() const override {
          return "HTML Report";
      }

  private:
      Header header;
      Block block;
      Ending ending;
  };

  class TxtBuilder : public ReportBuilder {
  public:
      void buildHeader() override {
          header.print();
      }

      void buildBlock() override {
          block.print();
      }

      void buildEnding() override {
          ending.print();
      }

      QString getResult() const override {
          return "Text Report";
      }

  private:
      Header header;
      Block block;
      Ending ending;
  };

  // Класс-директор
  class ReportDirector {
  public:
      void construct(ReportBuilder* builder) {
          builder->buildHeader();
          builder->buildBlock();
          builder->buildEnding();
      }
  };
  ```

- [FactoryMethodWithAbstructFactory.cpp](./src/FactoryMethodWithAbstructFactory.cpp)

  ```c++
  #include <QDebug>

  #include <iostream>

  // Продукты
  class Product {
  public:
      virtual void use() const = 0;
  };

  class ConcreteProduct : public Product {
  public:
      void use() const override {
          qDebug() << "Using Concrete Product\n";
      }
  };

  // Абстрактная фабрика
  class Factory {
  public:
      virtual Product* createProduct() const = 0;
  };

  // Конкретные фабрики
  class ConcreteFactory : public Factory {
  public:
      Product* createProduct() const override {
          return new ConcreteProduct();
      }
  };

  // Клиентский код
  void clientCode(const Factory& factory) {
      Product* product = factory.createProduct();
      product->use();
      delete product;
  }
  ```
