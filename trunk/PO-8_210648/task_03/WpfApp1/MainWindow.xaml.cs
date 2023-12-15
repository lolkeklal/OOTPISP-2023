using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp1
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

        private void Task1_OnClick(object sender, RoutedEventArgs e)
        {
            WindowT1 windowT1 = new WindowT1();
            windowT1.Show();
        }

        private void Task2_OnClick(object sender, RoutedEventArgs e)
        {
            Window2Task window2Task = new Window2Task();
            window2Task.Show();
        }

        private void Task3_OnClick(object sender, RoutedEventArgs e)
        {
            Window3Task window3Task = new Window3Task();
            window3Task.Show();
        }

        private void Task4_OnClick(object sender, RoutedEventArgs e)
        {
            Window4Task window4Task = new Window4Task();
            window4Task.Show();
        }

        private void Task5_OnClick(object sender, RoutedEventArgs e)
        {
            Window5Task window5Task = new Window5Task();
            window5Task.Show();
        }

        private void Task6_OnClick(object sender, RoutedEventArgs e)
        {
            Console.WriteLine($"{Math.Sqrt(3) % 1}");
            Window6Task window6Task = new Window6Task();
            window6Task.Show();
        }
    }
}