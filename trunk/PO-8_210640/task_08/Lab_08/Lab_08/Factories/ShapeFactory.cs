using Lab_08.Shapes.Basic_Shapes;

namespace Lab_08.Factories;

public abstract class ShapeFactory
{
    protected static ShapeFactory? _instance;

    protected ShapeFactory() { }


    public abstract Rectangle GetRectangle();
    public abstract Line GetLine();
    public abstract Ellipse GetEllipse();
    public abstract Text GetText();
}