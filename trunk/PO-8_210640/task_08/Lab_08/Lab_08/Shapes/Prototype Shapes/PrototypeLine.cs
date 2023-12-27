using Lab_08.Shapes.Basic_Shapes;

namespace Lab_08.Shapes.Prototype_Shapes;

public class PrototypeLine : Line, ICloneable
{
    public PrototypeLine()
    {
        Console.WriteLine("Prototype Line");
    }

    public object Clone()
    {
        return this.MemberwiseClone();
    }
}
