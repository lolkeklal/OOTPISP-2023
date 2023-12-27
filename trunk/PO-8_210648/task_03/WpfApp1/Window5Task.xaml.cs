using System.Collections.Generic;
using System.Data;
using System.Windows;

namespace WpfApp1;

public partial class Window5Task : Window
{
    public Window5Task()
    {
        InitializeComponent();
        dataTable = new DataTable();
        
        dataTable.Columns.Add("All country",typeof(string));
        dataTable.Columns.Add("Any country",typeof(string));
        dataTable.Columns.Add("One country", typeof(string));
    }

    private DataTable dataTable;
    private List<Brand> _brands = new List<Brand>();
    private List<string> _countrys = new List<string>();
    private void ButtonAdd_OnClick(object sender, RoutedEventArgs e)
    {
        List<string> list = new List<string>();
        string[] inputs = TextBoxImportCountry.Text.Split(',');
        foreach (var str in inputs)
        {
            if (str!="")
            {
                list.Add(str);
            }
            
        }

        
        Brand brand = new Brand(TextBoxBrand.Text,TextBoxCountry.Text,list);
        _brands.Add(brand);
        AddNewCountries(brand);
        UpdateMode();
        ShowInfo();

    }

    private void ShowInfo()
    {
        dataTable.Clear();
        List<string> all = new List<string>();
        List<string> any = new List<string>();
        List<string> one = new List<string>();
        foreach (var brand in _brands)
        {
            switch (brand.mode)
            {
                case 0:
                    one.Add(brand.Name);
                    break;
                case 1:
                    any.Add(brand.Name);
                    break;
                case 2:
                    all.Add(brand.Name);
                    break;
            }
        }

        while (true)
        {
            string vAll;
            string vAny;
            string vOne;
            bool b1 = true, b2 = true, b3 = true;
            if (all.Count > 0)
            {
                vAll = all[0];
                all.RemoveAt(0);
            }
            else
            {
                vAll = "";
                b1 = false;
            }
            if (any.Count > 0)
            {
                vAny = any[0];
                any.RemoveAt(0);
            }
            else
            {
                vAny = "";
                b2 = false;
            }
            if (one.Count > 0)
            {
                vOne = one[0];
                one.RemoveAt(0);
            }
            else
            {
                vOne = "";
                b3 = false;
            }
            if(!b1 && !b2 && !b3)
                break;
            dataTable.Rows.Add(vAll, vAny, vOne);
        }

        DataGrid.ItemsSource = dataTable.DefaultView;
    }
    private void UpdateMode()
    {
        foreach (var brand in _brands)
        {
            int counter = 0;
            foreach (var country in _countrys)
            {
                if (brand.CheckCountry(country))
                {
                    counter++;
                }
            }

            if (counter == 0)
                brand.mode = 0;
            else if (counter == _countrys.Count - 1)
                brand.mode = 2;
            else
                brand.mode = 1;
        }
    }
    private void AddNewCountries(Brand brand)
    {
        if (!_countrys.Contains(brand.Country))
        {
            _countrys.Add(brand.Country);
        }

        foreach (var impCntr in brand.ImportCountry)
        {
            if (!_countrys.Contains(impCntr))
            {
                _countrys.Add(impCntr);
            }

        }
    }
    
    private class Brand
    {
        public string Name;
        public string Country;
        public List<string> ImportCountry;
        public int mode;

        public Brand(string name, string country,List<string> importCountry)
        {
            Name = name;
            Country = country;
            ImportCountry = importCountry;
            mode = 0;
        }

        public bool CheckCountry(string country)
        {
            foreach (var impCntr in ImportCountry)
            {
                if (impCntr == country)
                    return true;
            }

            return false;
        }
        
        
    }
}