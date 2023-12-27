# Лабораторная работа № 8 #

## Паттерны проектирования ##

## Цель работы ##

Изучить паттерны проектирования в С++.

## Задания для выполнения ##

## Вариант 1 ##

1. Применить паттерн абстрактная фабрика при построении  схемы из простых графических объектов. Продукты фабрики: прямоугольник, линия, овал, текст.
2. Применить паттерн проектирования “Prototype” совместно с абстрактной фабрикой, то есть внести изменения в проект “Порождающие паттерны. Абстрактная фабрика”. То есть теперь в проекте абстрактная фабрика должна параметризоваться прототипами.
3. Применить паттерн проектирования  “Singleton” совместно с абстрактной фабрикой, то есть внести изменения в проект, разработанный на лабораторной работе “Порождающие паттерны. Абстрактная фабрика”.
4. Применить паттерн “Строитель” для построения
    - Отчета по частям
    - Части: Header – Заголовок, Block – Блок содержащий данные по отчету (результат SQL запроса), Ending – Концевик
    - ConcreteBuilder: HtmlBuilder, TxtBuilder, XlsBuilder, DocBuilder
5. Применить паттерн  “Фабричный метод” при создании конкретного строителя и передачи его клиенту.  Самостоятельно продумать контекст в каркасе для вызова шаблонного метода.

```c++

// Create an instance of the Fabric class
Fabric fabric = new Fabric();

// Create an instance of the BeautifulFabric class
BeautifulFabric beautifulFabric = new BeautifulFabric();

// Create an instance of the FabricPrototype class with some BeautifulShapes
FabricPrototype fabricPrototype = new FabricPrototype(new BeautifulRectangle(1, 2), new BeautifulLine(6),
    new BeatifulOval(10), new BeautifulText(4));

// Call the CreateAllFigures method with different types of fabrics
CreateAllFigures(fabric);
CreateAllFigures(beautifulFabric);
CreateAllFigures(fabricPrototype);

// Define the CreateAllFigures method that takes a Fabric object as a parameter
void CreateAllFigures(Fabric f)

    // Create different types of shapes using the Fabric object
    Rectangle rectangle = f.CreateRectangle(1,2);
    Line line = f.CreateLine(6);
    Oval oval = f.CreateOval(10);
    Text text = f.CreateText(4);

    // Show each of the created shapes on the console
    rectangle.Show();
    line.Show();
    oval.Show();
    text.Show();
 

// This code creates different types of shapes using different types of fabrics and shows them on the console.


```

```c++

FabricSingleton.cs
// Define a singleton class for creating fabric objects
public class FabricSingleton

    // Use lazy initialization to ensure only one instance is created
    private static readonly Lazy<FabricSingleton> instance =
        new Lazy<FabricSingleton>(() => new FabricSingleton());
    
    // Define a public property to access the singleton instance
    public static FabricSingleton Instance
        get  return instance.Value; 
    

    // Define methods for creating different types of shapes using the fabric object
    public  Rectangle CreateRectangle(int a, int b)
        return new Rectangle(a, b);

    public  Line CreateLine(int length)
        return new Line(length);

```

```c++

Builder
public abstract class Builder
{
    public abstract void BuildHeader();
    public abstract void BuildBlock();
    public abstract void BuildEnding();
    public abstract Product GetResult();
}

```

```c++

public class FabricPrototype : Fabric
{
    private Rectangle _rectanglePrototype;
    private Line _linePrototype;
    private Oval _ovalPrototype;
    private Text _textPrototype;

    public FabricPrototype(Rectangle rectangle, Line line, Oval oval, Text text)
    {
        _rectanglePrototype = rectangle;
        _linePrototype = line;
        _ovalPrototype = oval;
        _textPrototype = text;
    }

```

### Результат работы программы ###


```c++

Rectangle a: 1 b: 2
Line Length: 6
Oval radius: 10
Text Length: 4
Beautiful Rectangle a: 1 b: 2 color: 7
Beautiful Line length: 6 color: 5
Beautiful Oval radius: 10 color: 8
Beautiful Text length: 4 color: 5
Beautiful Rectangle a: 1 b: 2 color: 1
Beautiful Line length: 6 color: 0
Beautiful Oval radius: 10 color: 1
Beautiful Text length: 4 color: 6

```

```c++

Header text \n
Table data Created by Sasha

```

### Вывод ###

Изучила паттерны проектирования в С++.
