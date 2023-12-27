using System;
using System.Collections.Generic;
using System.Windows;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Shapes;
using System.Windows.Media;
using System.Windows.Controls;

namespace Lab_07;

internal class CircleComposition
{
    private Canvas Canvas { get; set; }
    private readonly List<Ellipse> EllipseList = [];

    private double Radius { get; set; }

    private int Vertices { get; set; }
    private double Phi0 { get; set; }
    

    public CircleComposition(Canvas canvas, int vertices, double radius, Color[] colors, double phi0 = 0)
    {
        Canvas = canvas;

        Vertices = vertices;
        Phi0 = phi0;

        Radius = radius / Math.Sin(Math.PI / vertices) / 2;


        var random = new Random();
        var buffer = new byte[3];

        var n = colors.Length;
        for (int i = 0; i < Vertices; i++)
        {
            Color color;
            
            if (i < n)
            {
                color = colors[i];
            }
            else
            {
                random.NextBytes(buffer);
                var r = buffer[0];
                var g = buffer[1];
                var b = buffer[2];

                color = Color.FromRgb(r, g, b);
            }

            var ellipse = new Ellipse
            {
                Height = radius,
                Width = radius,
                Fill = new SolidColorBrush(color),
            };

            EllipseList.Add(ellipse);
            Canvas.Children.Add(ellipse);
        }
    }

    public void Draw(Point center, double phi = 0)
    {
        var xc = center.X;
        var yc = center.Y;

        var tau = Math.Tau;
        var n = Vertices;

        var degrees = phi * Math.PI / 180;

        for (int i = 0; i < n; i++)
        {
            var xi = xc + Radius * Math.Cos(Phi0 + degrees + tau * i / n);
            var yi = yc + Radius * Math.Sin(Phi0 + degrees + tau * i / n);

            var ellipse = EllipseList[i];
            Canvas.SetLeft(ellipse, xi);
            Canvas.SetTop(ellipse, yi);
        }
    }

    public void Collapse()
    {
        foreach (var ellipse in EllipseList)
        {
            Canvas.Children.Remove(ellipse);
        }
    }
}
