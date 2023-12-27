namespace ConsoleApp1;

public class Rectangle
{
    protected int _a;
    protected int _b;
    public Rectangle(int a, int b)
    {
        _a = a;
        _b = b;
    }

    public virtual Rectangle Clone()
    {
        return new Rectangle(_a, _b);
    }
    public virtual void Show()
    {
        Console.WriteLine($"Rectangle a: {_a} b: {_b}");
    }
    
}

public class BeautifulRectangle : Rectangle
{
    private int _color;
    public BeautifulRectangle(int a, int b) : base(a, b)
    {
        Random rnd = new Random();
        _color = rnd.Next(10);
    }

    public override BeautifulRectangle Clone()
    {
        BeautifulRectangle beautifulRectangle = new BeautifulRectangle(_a, _b);
        beautifulRectangle._color = _color;
        return beautifulRectangle;
    }
    public override void Show()
    {
        Console.WriteLine($"Beautiful Rectangle a: {_a} b: {_b} color: {_color}");
    }
}