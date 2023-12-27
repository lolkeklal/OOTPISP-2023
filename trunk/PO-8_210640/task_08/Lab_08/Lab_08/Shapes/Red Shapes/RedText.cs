using Lab_08.Shapes.Basic_Shapes;
using System.Drawing;

namespace Lab_08.Shapes.Red_Shapes;

public class RedText : Text
{
    public Color Color { get; set; } = Color.Red;
    public RedText()
    {
        Console.WriteLine("Red Text");
    }
}
