using Lab_08.Shapes.Basic_Shapes;
using System.Drawing;
using Rectangle = Lab_08.Shapes.Basic_Shapes.Rectangle;

namespace Lab_08.Shapes.Red_Shapes;

public class RedRectangle : Rectangle
{
    public Color Color { get; set; } = Color.Red;
    public RedRectangle()
    {
        Console.WriteLine("RedRectangle");
    }
}
