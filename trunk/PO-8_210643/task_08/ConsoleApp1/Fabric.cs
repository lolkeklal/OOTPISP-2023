namespace ConsoleApp1;


public class Fabric
{
    public virtual Rectangle CreateRectangle(int a, int b)
    {
        return new Rectangle(a, b);
    }


    public virtual Line CreateLine(int length)
    {
        return new Line(length);
    }

    public virtual Oval CreateOval(int radius)
    {
        return new Oval(radius);
    }

    public virtual Text CreateText(int length)
    {
        return new Text(length);
    }
    
}

public class FabricPrototype : Fabric
{
    private readonly Rectangle _rectanglePrototype;
    private readonly Line _linePrototype;
    private readonly Oval _ovalPrototype;
    private readonly Text _textPrototype;

    public FabricPrototype(Rectangle rectangle, Line line, Oval oval, Text text)
    {
        _rectanglePrototype = rectangle;
        _linePrototype = line;
        _ovalPrototype = oval;
        _textPrototype = text;
    }

    public override Rectangle CreateRectangle(int a, int b)
    {
        return _rectanglePrototype.Clone();
    }

    public override Line CreateLine(int length)
    {
        return _linePrototype.Clone();
    }

    public override Oval CreateOval(int radius)
    {
        return _ovalPrototype.Clone();
    }

    public override Text CreateText(int length)
    {
        return _textPrototype.Clone();
    }
}

public class BeautifulFabric : Fabric
{
    public override BeautifulRectangle CreateRectangle(int a, int b)
    {
        return new BeautifulRectangle(a, b);
    }
    public override BeautifulLine CreateLine(int length)
    {
        return new BeautifulLine(length);
    }

    public override BeatifulOval CreateOval(int radius)
    {
        return new BeatifulOval(radius);
    }

    public override BeautifulText CreateText(int lenght)
    {
        return new BeautifulText(lenght);
    }
}

