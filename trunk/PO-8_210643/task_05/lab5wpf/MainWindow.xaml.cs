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

namespace lab5wpf
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            
        }

        private void ButtonAddData_OnClick(object sender, RoutedEventArgs e)
        {
            AddDataWindow addDataWindow = new AddDataWindow();
            addDataWindow.Show();


        }

        private void ButtonCreateDb_OnClick(object sender, RoutedEventArgs e)
        {
            DataBase.CreateDb();
            MessageBox.Show("Success");
        }

        private void ButtonShowRequest_OnClick(object sender, RoutedEventArgs e)
        {
            ShowRequest showRequest = new ShowRequest();
            showRequest.Show();

        }
    }
}