using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp2;

/// <summary>
/// Interaction logic for MainWindow.xaml
/// </summary>
public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    private bool rendering = false;
    private bool isEmpty = true;
    private Path _path;
    private double _radius = 20;
    private double x = 0;
    private void Button_OnClick(object sender, RoutedEventArgs e)
    {
        x = 0;
        if (!rendering)
        {
            Canvas.Children.Clear();
            CompositionTarget.Rendering += RenderFrame;
            rendering = true;
        }
    }

    private void RenderFrame(object? sender, EventArgs e)
    {
        if (isEmpty)
        {
            _path = new Path();
            
            GeometryGroup geometryGroup = new GeometryGroup();
            geometryGroup.Children.Add(new EllipseGeometry(new Point(50,0), 20,20));
            geometryGroup.Children.Add(new RectangleGeometry(new Rect(0,20,100,50)));
            _path.Data = geometryGroup;
            _path.Fill = Brushes.Black;
            _path.Stroke = Brushes.Red;
            Canvas.Children.Add(_path);
            isEmpty = false;
        }
        else
        {
            double y = 50 * Math.Sin(x + 100);
            x += 10;
            Canvas.SetTop(_path,y+100);
            Canvas.SetLeft(_path, x);

        }
    }
    private void ButtonStop_OnClick(object sender, RoutedEventArgs e)
    {
        StopRendering();
    }
    private void StopRendering()
    {
        CompositionTarget.Rendering -= RenderFrame;
        rendering = false;
        isEmpty = true;
    }
}