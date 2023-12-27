using Lab_08.Shapes.Basic_Shapes;

namespace Lab_08.Shapes.Prototype_Shapes;

public class PrototypeRectangle : Rectangle, ICloneable
{
    public PrototypeRectangle()
    {
        Console.WriteLine("Prototype Rectangle");
    }

    public object Clone()
    {
        return this.MemberwiseClone();
    }
}
