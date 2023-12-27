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
            turn = true;
            
            DataGrid.IsReadOnly = true;
        }

        private int[] arr1 = new int[10];
        private int[] arr2 = new int[10];
        private int[] arr3 = new int[10];
        private bool type;
        private bool turn;
        int count;
      
        private void Puzirek(ref int[] arr)
        {
            for (int i = 0; i < arr.Length-1; i++)
            {
                for (int j = 0; j < arr.Length-1; j++)
                {
                    if (arr[j] > arr[j + 1])
                        (arr[j], arr[j + 1]) = (arr[j + 1], arr[j]);
                }
            }
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
            DisplayDataGrid();
        }

        private void DisplayDataGrid()
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
        private void DataGrid_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            
            if (turn)
            {
                turn = false;
                switch (DataGrid.CurrentCell.Column.Header)
                {
                    case "Column1":
                        Puzirek(ref arr1);
                        break;
                    case "Column2":
                        Puzirek(ref arr2);
                        break;
                    case "Column3":
                        Puzirek(ref arr3);
                        break;
                }
                DisplayDataGrid();
                
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