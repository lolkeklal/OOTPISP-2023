using Lab_08.Shapes.Basic_Shapes;

namespace Lab_08.Shapes.Prototype_Shapes;

public class PrototypeText : Text, ICloneable
{
    public PrototypeText()
    {
        Console.WriteLine("Prototype Text");
    }

    public object Clone()
    {
        return this.MemberwiseClone();
    }
}
