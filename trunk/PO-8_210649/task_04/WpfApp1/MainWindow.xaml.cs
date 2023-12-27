using System;
using System.Collections.Generic;
using System.Data;
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
            ComboBox.ItemsSource = new string[]
            {
                "Pyzirek",
                "Vstavkami"
                
            };
            turn = true;
            ComboBox.SelectedIndex = 0;
            DataGrid.IsReadOnly = true;
        }

        private int[] arr1 = new int[10];
        private int[] arr2 = new int[10];
        private int[] arr3 = new int[10];
        private bool type;
        private bool turn;
        int count;
        

        

        private void Vstavki(ref int[] arr)
        {
            int counter = 0;
            for (int i = 1; i < arr.Length; i++)
            {
                int x = arr[i];
                int j = i;
                while (j>0 && arr[j-1] >x)
                {
                    counter++;
                    arr[j] = arr[j - 1];
                    j -= 1;
                }

                arr[j] = x;
            }

            Label.Content = counter;
        }
        private void Puzirek(ref int[] arr)
        {
            int counter = 0;
            for (int i = 0; i < arr.Length-1; i++)
            {
                for (int j = 0; j < arr.Length-1; j++)
                {
                    counter++;
                    if (arr[j] > arr[j + 1])
                        (arr[j], arr[j + 1]) = (arr[j + 1], arr[j]);
                }
            }

            Label.Content = counter;
        }

        private void RandomValue_OnClick(object sender, RoutedEventArgs e)
        {
            Random random = new Random();
            for (int i = 0; i < 10; i++)
            {
                arr1[i] = random.Next(0, 10);
                arr2[i] = random.Next(0, 10);
                arr3[i] = random.Next(0, 10);
            }
            DisplayDg();
        }

        private void DisplayDg()
        {
            DataTable dataTable = new DataTable();
            for (int i = 0; i < 3; i++)
            {
                dataTable.Columns.Add();
            }

            for (int i = 0; i < 10; i++)
            {
                dataTable.Rows.Add(arr1[i], arr2[i], arr3[i]);
            }

            DataGrid.ItemsSource = dataTable.DefaultView;
        }

        private void ComboBox_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (ComboBox.SelectedItem == "Pyzirek")
            {
                type = true;
            }
            else
            {
                type = false;
            }
        }

        

        private void DataGrid_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            
            if (turn)
            {
                turn = false;
                switch (DataGrid.CurrentCell.Column.Header)
                {
                    case "Column1":
                        if (type)
                        {
                            Puzirek(ref arr1);
                        }
                        else
                        {   
                            Vstavki(ref arr1);
                        }
                        break;
                    case "Column2":
                        if (type)
                        {
                            Puzirek(ref arr2);
                        }
                        else
                        {   
                            Vstavki(ref arr2);
                        }
                        break;
                    case "Column3":
                        if (type)
                        {
                            Puzirek(ref arr3);
                        }
                        else
                        {   
                            Vstavki(ref arr3);
                        }
                        break;
                }
            
                DisplayDg();
                
            }
            else
            {
                count++;
                if (count ==2)
                {
                    turn = true;
                    count = 0;
                }
                
            }
            
        }
    }
}