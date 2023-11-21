using System.Data;
using System.Windows;
using Microsoft.Data.SqlClient;
using MessageBox = System.Windows.Forms.MessageBox;

namespace lab5wpf;

public class ShowRequest : Window
{
    public ShowRequest()
    {
        InitializeComponent();
        RadioButtonState.IsChecked = true;
    }

    private int selectedValue;
    private string sqlCommand;

    private void ButtonFind_OnClick(object sender, RoutedEventArgs e)
    {
        switch (selectedValue)
        {
            case 0:
                RadioButtonReysTime.IsChecked = true;
                RadioButtonState.IsChecked = true;
                break;
            case 1:
                RadioButtonState.IsChecked = true;
                RadioButtonReysTime.IsChecked = true;
                break;
            default:
                MessageBox.Show("!");
                break;
        }
        SqlConnection sqlConnection = new SqlConnection(DataBase.connectionString);
        SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(sqlCommand, sqlConnection);
        DataTable dataTable = new DataTable();
        sqlDataAdapter.Fill(dataTable);
        DataGrid.ItemsSource = dataTable.DefaultView;
    }

    private void RadioButtonState_OnChecked(object sender, RoutedEventArgs e)
    {
        selectedValue = 0;
        sqlCommand = $"SELECT machine.Nom, reys.T_in, reys.T_all,reys.T_out, states.Name FROM machine, reys, states, reys_states WHERE machine.Id_Reys = reys.Id AND reys.Id = reys_states.Id_reys AND states.Id = reys_states.Id_state AND states.name = '{TextBoxState.Text}'";
    }

    private void RadioButtonReysTime_OnChecked(object sender, RoutedEventArgs e)
    {
        selectedValue = 1;
        sqlCommand = $"SELECT machine.Nom, reys.T_in, reys.T_all, reys.T_out FROM machine, reys" +
                     $" WHERE machine.Id_Reys = reys.Id";
        if (CheckBoxTin.IsChecked == true)
        {
            sqlCommand += $" AND reys.T_in = '{TextBoxTin.Text}'";
        }
        if (CheckBoxTall.IsChecked == true)
        {
            sqlCommand += $" AND reys.T_all = '{TextBoxTall.Text}'";
        }
        if (CheckBoxTout.IsChecked == true)
        {
            sqlCommand += $" AND reys.T_out = '{TextBoxTout.Text}'";
        }
    }
}