using Lab_08.Shapes.Basic_Shapes;
using Lab_08.Shapes.Red_Shapes;

namespace Lab_08.Factories;

public class RedShapeFactory : ShapeFactory
{
    public static ShapeFactory GetInstance()
    {
        if (_instance == null)
        {
            _instance = new RedShapeFactory();
        }

        return _instance;
    }

    public override Ellipse GetEllipse()
    {
        return new RedEllipse();
    }

    public override Line GetLine()
    {
        return new RedLine();
    }

    public override Rectangle GetRectangle()
    {
        return new RedRectangle();
    }

    public override Text GetText()
    {
        return new RedText();
    }
}
