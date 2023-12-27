namespace ConsoleApp1;

public class Line
{
    protected int _length;

    public Line(int length)
    {
        _length = length;
    }
    public virtual void Show()
    {
        Console.WriteLine($"Length: {_length}");
    }

    public virtual Line Clone()
    {
        return new Line(_length);
    }
}

public class BeautifulLine : Line
{
    private int _color;

    public BeautifulLine(int length) : base(length)
    {
        Random rnd = new Random();
        _color = rnd.Next(10);
    }
    public override void Show()
    {
        Console.WriteLine($"length: {_length} color: {_color}");
    }
    public override BeautifulLine Clone()
    {
        BeautifulLine beautifulLine =  new BeautifulLine(_length);
        beautifulLine._color = _color;
        return beautifulLine;
    }
}