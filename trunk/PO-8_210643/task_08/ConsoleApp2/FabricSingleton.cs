namespace ConsoleApp1;

public class FabricSingleton
{
    private static readonly Lazy<FabricSingleton> instance =
        new Lazy<FabricSingleton>(() => new FabricSingleton());
    
    public static FabricSingleton Instance
    {
        get { return instance.Value; }
    }
    public  Rectangle CreateRectangle(int a, int b)
    {
        return new Rectangle(a, b);
    }

    private FabricSingleton()
    {
        
    }
    public  Line CreateLine(int length)
    {
        return new Line(length);
    }

    public  Oval CreateOval(int radius)
    {
        return new Oval(radius);
    }

    public  Text CreateText(int lenght)
    {
        return new Text(lenght);
    }
}