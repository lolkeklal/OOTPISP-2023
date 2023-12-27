using Lab_08.Shapes.Basic_Shapes;

namespace Lab_08.Shapes.Prototype_Shapes;

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
