# Цель работы 
Изучить паттерны проектирования.
### Вариант 16(1)
1. Применить паттерн абстрактная фабрика при построении  схемы из простых графических объектов. Продукты фабрики: прямоугольник, линия, овал, текст.  
2. Применить паттерн проектирования “Prototype” совместно с абстрактной фабрикой, то есть внести изменения в проект “Порождающие паттерны. Абстрактная фабрика”. То есть теперь в проекте абстрактная фабрика должна параметризоваться прототипами.
3. Применить паттерн проектирования  “Singleton” совместно с абстрактной фабрикой, то есть внести изменения в проект, разработанный на лабораторной работе “Порождающие паттерны. Абстрактная фабрика”.
4. Применить паттерн “Строитель” для построения отчета по частям
   
   Части: Header – Заголовок, Block – Блок содержащий данные по отчету (результат SQL запроса), Ending – Концевик
   
   ConcreteBuilder: HtmlBuilder, TxtBuilder, XlsBuilder, DocBuilder

6. Применить паттерн  “Фабричный метод” при создании конкретного строителя и передачи его клиенту.  Самостоятельно продумать контекст в каркасе для вызова шаблонного метода.
#### Abstract Factory (+Singleton)
```C#
public abstract class ShapeFactory
{
    protected static ShapeFactory? _instance = null;

    protected ShapeFactory() { }


    public abstract Rectangle GetRectangle();
    public abstract Line GetLine();
    public abstract Ellipse GetEllipse();
    public abstract Text GetText();
}
```
#### Concrete Factory (+Singleton) 
```C#
public class RedShapeFactory : ShapeFactory
{
    public static ShapeFactory GetInstance()
    {
        if (_instance == null)
        {
            _instance = new RedShapeFactory();
        }

        return _instance;
    }

    public override Ellipse GetEllipse()
    {
        return new RedEllipse();
    }

    public override Line GetLine()
    {
        return new RedLine();
    }

    public override Rectangle GetRectangle()
    {
        return new RedRectangle();
    }

    public override Text GetText()
    {
        return new RedText();
    }
}
```
#### Prototype 
```C#
public class PrototypeFactory : ShapeFactory
{
    private PrototypeEllipse ellipse;
    private PrototypeLine line;
    private PrototypeRectangle rectangle;
    private PrototypeText text;

    public PrototypeFactory(PrototypeEllipse ellipse, PrototypeLine line, PrototypeRectangle rectangle, PrototypeText text)
    {
        this.ellipse = ellipse;
        this.line = line;
        this.rectangle = rectangle;
        this.text = text;
    }
    public override Ellipse GetEllipse()
    {
        return (PrototypeEllipse)ellipse.Clone();
    }

    public override Line GetLine()
    {
        return (PrototypeLine)line.Clone();
    }

    public override Rectangle GetRectangle()
    {
        return (PrototypeRectangle)rectangle.Clone();
    }

    public override Text GetText()
    {
        return (PrototypeText)text.Clone();
    }
}
```
#### PrototypeEllipse
```C#
public class PrototypeEllipse : Ellipse, ICloneable
{
    public PrototypeEllipse()
    {
        Console.WriteLine("Prototype Ellipse");
    }

    public object Clone()
    {
        return this.MemberwiseClone();
    }
}
```
#### Builder 
```C#
public abstract class Builder
{
    protected Report report;

    public void CreateReport()
    {
        report = new Report();
    }

    public abstract void SetHeader(string header);
    public abstract void SetBlock(string block);
    public abstract void SetEnding(string ending);

    public Report GetReport()
    {
        return report;
    }
}
```
#### Concrete Builder 
```C#
public class XlsBuilder : Builder
{
    public override void SetHeader(string header)
    {
        report.Header = header;
    }

    public override void SetBlock(string block)
    {
        report.Block = ToXls(block);
        Console.WriteLine(nameof(XlsBuilder));
    }

    public override void SetEnding(string ending)
    {
        report.Ending = ending;
    }

    private static string ToXls(string block)
    {
        // some operations
        return block;
    }
}
```
#### Factory 
```C#
public abstract class Creator
{
    public abstract Builder Create();

    public static Builder Create<T>() where T : Builder, new()
    {
        return new T();
    }
}
```
#### Concrete Factory 
```C#
public class HtmlCreator : Creator
{
    public override Builder Create()
    {
        return new HtmlBuilder();
    }
}
```
#### Вывод 
Изучил паттерны проектирования.
