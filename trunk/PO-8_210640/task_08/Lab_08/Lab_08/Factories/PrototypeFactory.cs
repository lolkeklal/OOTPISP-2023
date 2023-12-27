using Lab_08.Shapes.Basic_Shapes;
using Lab_08.Shapes.Prototype_Shapes;

namespace Lab_08.Factories;

public class PrototypeFactory : ShapeFactory
{
    private readonly PrototypeEllipse ellipse;
    private readonly PrototypeLine line;
    private readonly PrototypeRectangle rectangle;
    private readonly PrototypeText text;

    public PrototypeFactory(PrototypeEllipse ellipse, PrototypeLine line, PrototypeRectangle rectangle, PrototypeText text)
    {
        this.ellipse = ellipse;
        this.line = line;
        this.rectangle = rectangle;
        this.text = text;
    }
    public override Ellipse GetEllipse()
    {
        return (PrototypeEllipse)ellipse.Clone();
    }

    public override Line GetLine()
    {
        return (PrototypeLine)line.Clone();
    }

    public override Rectangle GetRectangle()
    {
        return (PrototypeRectangle)rectangle.Clone();
    }

    public override Text GetText()
    {
        return (PrototypeText)text.Clone();
    }
}
