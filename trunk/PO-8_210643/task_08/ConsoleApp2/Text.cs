namespace ConsoleApp1;

public class Text
{
    protected int _length;

    public Text(int length)
    {
        _length = length;
    }
    public virtual void Show()
    {
        Console.WriteLine($"Length: {_length}");
    }

    public virtual Text Clone()
    {
        return new Text(_length);
    }
}

public class BeautifulText : Text
{
    private int _color;
    public BeautifulText(int length) : base(length)
    {
        Random rnd = new Random();
        _color = rnd.Next(10);
    }
    public override void Show()
    {
        Console.WriteLine($"length: {_length} color: {_color}");
    }

    public override BeautifulText Clone()
    {
        BeautifulText beautifulText = new BeautifulText(_length);
        beautifulText._color = _color;
        return beautifulText;
    }
}