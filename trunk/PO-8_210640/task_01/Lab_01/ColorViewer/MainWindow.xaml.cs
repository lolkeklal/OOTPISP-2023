using Stopbyte.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ColorViewer
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            RGBCanvas.Background = new SolidColorBrush(Color.FromRgb(0, 0, 0));
        }

        private void Red_ValueChanged(object sender, EventArgs e)
        {
            if (sender is Slider slider)
            {
                var value = Convert.ToByte(slider.Value);
                SpinnerR.Value = value;

                if (RGBCanvas.Background is SolidColorBrush brush)
                {
                    var color = brush.Color;
                    color.R = value;
                    brush.Color = color;
                }
            }

            if (sender is NumericSpinner spinner)
            {
                var value = Convert.ToByte(spinner.Value);
                SliderR.Value = value;

                if (RGBCanvas.Background is SolidColorBrush brush)
                {
                    var color = brush.Color;
                    color.R = value;
                    brush.Color = color;
                }
            }
        }

        private void Green_ValueChanged(object sender, EventArgs e)
        {
            if (sender is Slider slider)
            {
                var value = Convert.ToByte(slider.Value);
                SpinnerG.Value = value;

                if (RGBCanvas.Background is SolidColorBrush brush)
                {
                    var color = brush.Color;
                    color.G = value;
                    brush.Color = color;
                }
            }

            if (sender is NumericSpinner spinner)
            {
                var value = Convert.ToByte(spinner.Value);
                SliderG.Value = value;

                if (RGBCanvas.Background is SolidColorBrush brush)
                {
                    var color = brush.Color;
                    color.G = value;
                    brush.Color = color;
                }
            }
        }

        private void Blue_ValueChanged(object sender, EventArgs e)
        {
            if (sender is Slider slider)
            {
                var value = Convert.ToByte(slider.Value);
                SpinnerB.Value = value;

                if (RGBCanvas.Background is SolidColorBrush brush)
                {
                    var color = brush.Color;
                    color.B = value;
                    brush.Color = color;
                }
            }

            if (sender is NumericSpinner spinner)
            {
                var value = Convert.ToByte(spinner.Value);
                SliderB.Value = value;

                if (RGBCanvas.Background is SolidColorBrush brush)
                {
                    var color = brush.Color;
                    color.B = value;
                    brush.Color = color;
                }
            }
        }
    }
}
