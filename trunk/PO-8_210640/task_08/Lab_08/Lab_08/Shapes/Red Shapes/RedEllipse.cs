using Lab_08.Shapes.Basic_Shapes;
using System.Drawing;

namespace Lab_08.Shapes.Red_Shapes;

public class RedEllipse : Ellipse
{
    public Color Color { get; set; } = Color.Red;
    public RedEllipse()
    {
        Console.WriteLine("Red Ellipse");
    }
}
