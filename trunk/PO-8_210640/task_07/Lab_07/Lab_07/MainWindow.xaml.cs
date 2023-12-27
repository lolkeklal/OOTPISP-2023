using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Animation;

namespace Lab_07
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private CircleComposition CircleComposition { get; set; }
        private Point Center { get; set; }
        private double Angle { get; set; }

        private bool rendering;

        private void Start_Clicked(object sender, RoutedEventArgs e)
        {
            if (!rendering)
            {
                InitializeAnimation();

                CompositionTarget.Rendering += RenderFrame;
                rendering = true;
            }
        }

        private void InitializeAnimation()
        {
            Center = new Point(700, -25);
            Angle = 0;

            CircleComposition?.Collapse();

            CircleComposition = new CircleComposition(MyCanvas, 3, 50, [Colors.Red, Colors.Green, Colors.Blue]);
            CircleComposition.Draw(Center);
        }









        private void Stop_Clicked(object sender, RoutedEventArgs e)
        {
            StopRendering();
        }

        private void StopRendering()
        {
            CompositionTarget.Rendering -= RenderFrame;
            rendering = false;
        }

        private double Velocity { get; set; } = -2;
        private double Rotation { get; set; } = 2;


        private void RenderFrame(object sender, EventArgs e)
        {
            if (!rendering)
            {
                return;
            }

            if (Center.X < 50 && Velocity < 0)
            {
                Velocity = -Velocity;
            }

            if (Center.X > 700 && Velocity > 0)
            {
                Velocity = -Velocity;
            }

            var x = Center.X + Velocity;
            var centeredX = MyCanvas.ActualWidth / 2 - x;
            var centeredY = Math.Pow(centeredX, 3) / Math.Pow(MyCanvas.ActualWidth / 2, 3) * (MyCanvas.ActualHeight / 2);
            var y = MyCanvas.ActualHeight / 2 + centeredY - 10;

            var point = new Point(x, y);
            Center = point;

            Angle += Rotation;

            CircleComposition.Draw(point, Angle);
        }
    }
}