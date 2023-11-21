using System.Data;
using System.Windows;
using System.Windows.Controls;
using Microsoft.Data.SqlClient;

namespace lab5wpf;

public class AddDataWindow : Window
{
    public AddDataWindow()
    {
        InitializeComponent();
        ComboBoxTables.ItemsSource = new string
        {
            "machine",
            "reys",
            "reys_states",
            "states"
        };
        ComboBoxTables.SelectedIndex = 3;

    }

    private DataTable _dataTable;
    
    private void ComboBoxTables_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
    {

        using (var connection = new SqlConnection(DataBase.connectionString))
        {
            connection.Open();

            SqlCommand command = new SqlCommand($"SELECT * FROM {ComboBoxTables.SelectedItem}", connection);
            SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
            _dataTable = new DataTable();
            sqlDataAdapter.Fill(_dataTable);
            DataGrid.ItemsSource = _dataTable.DefaultView;
        }
    }

    
    private void ButtonSave_OnClick(object sender, RoutedEventArgs e)
    {
        SqlConnection connection = new SqlConnection(DataBase.connectionString);
        SqlDataAdapter sqlDataAdapter = new SqlDataAdapter($"SELECT * FROM {ComboBoxTables.SelectedItem}",connection);
        new SqlCommandBuilder(sqlDataAdapter);
        sqlDataAdapter.Update(_dataTable);
        
    }
}