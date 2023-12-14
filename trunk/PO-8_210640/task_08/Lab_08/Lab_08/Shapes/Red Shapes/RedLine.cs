using Lab_08.Shapes.Basic_Shapes;
using System.Drawing;

namespace Lab_08.Shapes.Red_Shapes;

public class RedLine : Line
{
    public Color Color { get; set; } = Color.Red;
    public RedLine()
    {
        Console.WriteLine("RedLine");
    }
}
