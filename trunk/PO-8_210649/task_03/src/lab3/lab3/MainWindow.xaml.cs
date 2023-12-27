using System;
using System.Collections.Generic;
using System.IO;
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
using Microsoft.Win32;

namespace lab3
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

        private void Task1Button_OnClick(object sender, RoutedEventArgs e)
        {
            Task1Window task1Window = new Task1Window();
            task1Window.Show();
        }

        private void Task2Button_OnClick(object sender, RoutedEventArgs e)
        {
            Task2Window task2Window = new Task2Window();
            task2Window.Show();
        }

        private void Task3Button_OnClick(object sender, RoutedEventArgs e)
        {
            Task3Window task3Window = new Task3Window();
            task3Window.Show();
        }

        private void Task4Button_OnClick(object sender, RoutedEventArgs e)
        {
            Task4Window task4Window = new Task4Window();
            task4Window.Show();
        }

        private void Task5Button_OnClick(object sender, RoutedEventArgs e)
        {
            Task5Window task5Window = new Task5Window();
            task5Window.Show();
        }

        private void Task6Button_OnClick(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.ShowDialog();
            string text;
            using (StreamReader streamReader = new StreamReader(openFileDialog.FileName))
            {
                text =  streamReader.ReadToEnd();
            }

            string[] inputs = text.Split(' ');
            List<int> list = new List<int>();
            foreach (var input in inputs)
            {
                list.Add(Convert.ToInt32(input));
            }

            string res = "";
            string res2 = "";
            foreach (var item in list)
            {
                if (item % 2 == 0)
                {
                    res += $"{item},";
                }
                else
                {
                    res2 += $"{item} ";
                }
            }

            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.ShowDialog();
            using (StreamWriter streamWriter = new StreamWriter(saveFileDialog.FileName))
            {
                streamWriter.WriteLineAsync(res);
            }
            SaveFileDialog saveFileDialog2 = new SaveFileDialog();
            saveFileDialog2.ShowDialog();
            using (StreamWriter streamWriter = new StreamWriter(saveFileDialog2.FileName))
            {
                streamWriter.WriteLineAsync(res2);
            }
        }
    }
}