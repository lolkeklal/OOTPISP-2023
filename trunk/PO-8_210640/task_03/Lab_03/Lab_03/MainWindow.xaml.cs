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

namespace Lab_03
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

        #region Task 1
        private int? A { get; set; } = null;
        private int B { get; set; }
        private void Task1TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            Task1Button.IsEnabled = int.TryParse(Task1TextBox.Text, out int _);
        }

        private void Task1Button_Button_Click(object sender, RoutedEventArgs e)
        {
            if (A is null)
            {
                A = int.Parse(Task1TextBox.Text);
                Task1Label.Content = "Enter B";
                Task1TextBox.Text = "";
            }
            else
            {
                B = int.Parse(Task1TextBox.Text);
                int a = A.Value;
                if (a == B)
                {
                    A = B = 0;
                }
                else
                {
                    A = B = Math.Max(a, B);
                }

                Task1TextBox.IsEnabled = false;
                Task1Button.IsEnabled = false;

                Task1Label.Content = $"A = {A}\nB = {B}";
            }
        }

        #endregion
    }
}