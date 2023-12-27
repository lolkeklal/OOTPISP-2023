using ConsoleApp1;

namespace ConsoleApp1;

public class FabricSingleton : Fabric
{
    private static readonly Lazy<FabricSingleton> instance =
        new Lazy<FabricSingleton>(() => new FabricSingleton());
    
    public static FabricSingleton Instance
    {
        get { return instance.Value; }
    }
    public override Rectangle CreateRectangle(int a, int b)
    {
        return new Rectangle(a, b);
    }

    private FabricSingleton()
    {
        
    }
    public override Line CreateLine(int length)
    {
        return new Line(length);
    }

    public override Oval CreateOval(int radius)
    {
        return new Oval(radius);
    }

    public override Text CreateText(int lenght)
    {
        return new Text(lenght);
    }
}