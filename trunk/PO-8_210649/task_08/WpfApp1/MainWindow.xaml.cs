using System.Security.Cryptography;
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
using Rectangle = System.Drawing.Rectangle;


namespace WpfApp1;

/// <summary>
/// Interaction logic for MainWindow.xaml
/// </summary>
public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
        
    }

    private List<System.Windows.Shapes.Rectangle> _rectangles = new List<System.Windows.Shapes.Rectangle>();
    //private System.Windows.Shapes.Rectangle rectangle;
    
    private double x = 1;
    private bool isEmpty = true;
    private bool rendering = false;
    private Path _path;
    private void Button_OnClick(object sender, RoutedEventArgs e)
    {
        if (!rendering)
        {
            _rectangles.Clear();
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
            CombinedGeometry combinedGeometry = new CombinedGeometry();
            GeometryGroup geometryGroup = new GeometryGroup();
            geometryGroup.Children.Add(new EllipseGeometry(new Rect(0,0,100,100)));
            geometryGroup.Children.Add(new LineGeometry(new Point(50,100), new Point(150,200)));
            geometryGroup.Children.Add(new LineGeometry(new Point(50,100), new Point(-50,200)));
            geometryGroup.Children.Add(new LineGeometry(new Point(-50,200), new Point(150,200)));
            
            _path.Data = geometryGroup;
            _path.Fill = Brushes.Black;
            _path.Stroke = Brushes.Red;
            Canvas.Children.Add(_path);
            isEmpty = false;
        }
        else
        {
            double y;
            if (10000 - x > 0)
            {
               y = Math.Sqrt((Math.Pow(x,3)/(10000 - x)));
            }
            else
            {
                y = 0;
            }
            
            Canvas.SetTop(_path, y + 200);
            Canvas.SetLeft(_path, x + 100);
            x += 1;
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