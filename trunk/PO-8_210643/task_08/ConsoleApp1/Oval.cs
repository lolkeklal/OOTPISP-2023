namespace ConsoleApp1;

public class Oval
{
    protected int _radius;

    public Oval (int radius)
    {
        _radius = radius;
    }
    public virtual void Show()
    {
        Console.WriteLine($"Oval radius: {_radius}");
    }

    public virtual Oval Clone()
    {
        return new Oval(_radius);
    }
}

public class BeatifulOval : Oval
{
    private int _color;
    public BeatifulOval(int radius) : base(radius)
    {
        Random rnd = new Random();
        _color = rnd.Next(10);
    }
    public override void Show()
    {
        Console.WriteLine($"Beautiful Oval radius: {_radius} color: {_color}");
    }

    public override BeatifulOval Clone()
    {
        BeatifulOval beatifulOval = new BeatifulOval(_radius);
        beatifulOval._color = _color;
        return beatifulOval;
    }
}