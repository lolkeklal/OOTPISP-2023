
# Лабораторная работа №2 #

## Основы Qt ##

## Реализация/ход работы ##

## Цель работы ##

Целью этой лабораторной работы является применение полученных на предыдущих лекциях знаний и повторение их на практических примерах. Задачей будет разработка законченного оконного приложения — текстового редактора, работающего с несколькими документами с возможностями открытия и сохранения, отмены действий, работы с буфером обмена и другими.

### Создание приложения TextEditor ###
### Вариант 4 ###
**Задание 1**
```csharp
using System;
using System.Windows;

namespace WpfApp1;

public partial class WindowT1 : Window
{
    public WindowT1()
    {
        InitializeComponent();
    }

    private void Button_OnClick(object sender, RoutedEventArgs e)
    {
        int a = Convert.ToInt32(TextBoxFirstValue.Text);
        int b = Convert.ToInt32(TextBoxSecondValue.Text);
        if (a == b)
        {
            a = 0;
            b = 0;
        }
        else
        {
            a += b;
            b = a;
        }

        LabelResult.Content = $"Result a: {a}, b: {b}";
    }
}
```
#### Результат работы программы ####

![img.png](src/img1.png)

**Задание 2**
```csharp
using System;
using System.Collections.Generic;
using System.Windows;

namespace WpfApp1;

public partial class Window2Task : Window
{
    public Window2Task()
    {
        InitializeComponent();
    }

    private void Button1_OnClick(object sender, RoutedEventArgs e)
    {
        string[] str1 = TextBox1.Text.Split(",");
        string[] str2 = TextBox2.Text.Split(",");
        int n = Convert.ToInt32(str1[0]);
        int x = Convert.ToInt32(str2[0]);
        int y = Convert.ToInt32(str2[1]);
        int[] arr = new int[n];
        int[,] arr2 = new int[x, y];
        for (int i = 0; i < n; i++)
        {
            arr[i] = Convert.ToInt32(str1[i + 1]);
        }

        int index = 2;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                arr2[i, j] = Convert.ToInt32(str2[index]);
                index++;
            }
        }

        for (int i = 2; i < n-1; i+=2)
        {
            arr[i] += arr[0];
        }

        double[] avg = new double[x];

        for (int i = 0; i < x; i++)
        {
            int sum = 0;
            for (int j = 0; j < y; j++)
            {
                sum += arr2[i, j];
            }
            avg[i] = (double)sum / y;
            int counter = 0;
            for (int j = 0; j < y; j++)
            {
                if (arr2[i, j] > avg[i])
                {
                    counter++;
                }
            }

            avg[i] = counter;
        }
        
        
        string result = "{ ";
        foreach (var i in arr)
        {
            result += $"{i}, ";
        }

        result += "}\n{\n";

        for (int i = 0; i < x; i++)
        {
            result += "{ ";
            for (int j = 0; j < y; j++)
            {
                result += $"{arr2[i, j]}, ";
            }

            result += $"{'}'} num - {avg[i]}\n";
        }

        result += "}";
        TextBoxResult.Text = result;
    }
}
```
#### Результат работы программы ####
![img.png](src/img2.png)

**Задание 3**
```csharp
using System;
using System.Collections.Generic;
using System.Windows;

namespace WpfApp1;

public partial class Window3Task : Window
{
    public Window3Task()
    {
        InitializeComponent();
    }

    private void Button_OnClick(object sender, RoutedEventArgs e)
    {
        string result = "INP:\n{ ";
        Random rnd = new Random();
        LinkedList<int> linkedList1 = new LinkedList<int>();
        string[] inputs = Input.Text.Split(',');
        int count = Convert.ToInt32(inputs[0]);
        int n = Convert.ToInt32(inputs[1]);
        int k = Convert.ToInt32(inputs[2]);
        for (int i = 0; i < count; i++)
        {
            linkedList1.AddLast(rnd.Next(0, 10));
        }

        foreach (var i in linkedList1)
        {
            result += $"{i}, ";
        }

        result += "}\n";

        List<int> rem = new List<int>();
        int index = 0;
        foreach (var i in linkedList1)
        {
            if (index >= n && index <= k)
            {
                rem.Add(i);
            }

            index++;
        }

        foreach (var i in rem)
        {
            linkedList1.Remove(i);
        }
        result += "RES:\n{ ";
        foreach (var i in linkedList1)
        {
            result += $"{i}, ";
        }

        result += "}\n";
        LinkedList<int> linkedList2 = new LinkedList<int>();
        for (int i = 0; i < count; i++)
        {
            linkedList2.AddLast(rnd.Next(0,10));
        }

        result += "INP:\n{ ";
        List<int> list = new List<int>();
        foreach (var i in linkedList2)
        {
            result += $"{i}, ";
            list.Add(i);
        }
        list.Sort();
        result += "}\n";
        
        linkedList2.Clear();
        foreach (var i in list)
        {
            linkedList2.AddFirst(i);
        }

        result += "RES:\n{";
        foreach (var i in linkedList2)
        {
            result += $"{i}, ";
        }
        result += "}\n";
        TextBox.Text = result;
    }
}
```
#### Результат работы программы ####
![img.png](src/img3.png)

**Задание 4**
```csharp
using System;
using System.Collections;
using System.Collections.Generic;
using System.Windows;

namespace WpfApp1;

public partial class Window4Task : Window
{
    public Window4Task()
    {
        InitializeComponent();
    }

    private void ButtonRun_OnClick(object sender, RoutedEventArgs e)
    {
        Stack<int> stack = new Stack<int>();
        string[] inputs = TextBoxInput.Text.Split(',');
        for (int i = 0; i < 8; i++)
        {
            stack.Push(Convert.ToInt32(inputs[i]));
        }

        int[] arr = stack.ToArray();
        for (int i = 0; i < 8; i++)
        {
            arr[i] *= arr[7 - i];
        }
        
        stack.Clear();
        for (int i = 0; i < 8; i++)
        {
            stack.Push(arr[i]);
        }

        string result = "{ ";
        foreach (var i in stack)
        {
            result += $"{i}, ";
        }

        result += "}\n";
        
        Queue<int> queue = new Queue<int>();
        Random rnd = new Random();
        for (int i = 0; i < 8; i++)
        {
            queue.Enqueue(rnd.Next(-20,50));
        }
        result += "{ ";
        foreach (var d in queue)
        {
            result += $"{d}, ";
        }

        result += "}\n";

        Queue<double> queue1 = new Queue<double>();
        for (int i = 0; i < 4; i++)
        {
            int v1 = queue.Dequeue();
            int v2 = queue.Dequeue();
            queue1.Enqueue(((double)(v1+v2))/2);
        }

        result += "{ ";
        foreach (var d in queue1)
        {
            result += $"{d}, ";
        }

        result += "}\n";
        TextBoxResult.Text = result;
    }
}
```
#### Результат работы программы ####
![img.png](src/img4.png)

**Задание 5**
```csharp
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
```
#### Результат работы программы ####
![img.png](src/img5.png)

**Задание 6**
```csharp
using System;
using System.Collections.Generic;
using System.IO;
using System.Windows;
using Microsoft.Win32;

namespace WpfApp1;

public partial class Window6Task : Window
{
    public Window6Task()
    {
        InitializeComponent();
    }

    private void ButtonA_OnClick(object sender, RoutedEventArgs e)
    {
        OpenFileDialog openFileDialog = new OpenFileDialog();
        openFileDialog.ShowDialog();
        string text;
        using (StreamReader streamReader = new StreamReader(openFileDialog.FileName))
        {
            text =  streamReader.ReadToEnd();
        }

        string[] inputs = text.Split(',');
        List<int> list = new List<int>();
        foreach (var input in inputs)
        {
            list.Add(Convert.ToInt32(input));
        }

        string res = "";
        foreach (var item in list)
        {
            if (item % 2 == 0)
            {
                res += $"{item},";
            }
        }

        SaveFileDialog saveFileDialog = new SaveFileDialog();
        saveFileDialog.ShowDialog();
        using (StreamWriter streamWriter = new StreamWriter(saveFileDialog.FileName))
        {
            streamWriter.WriteLineAsync(res);
        }
    }

    private void ButtonB_OnClick(object sender, RoutedEventArgs e)
    {
        OpenFileDialog openFileDialog = new OpenFileDialog();
        openFileDialog.ShowDialog();
        string text;
        using (StreamReader streamReader = new StreamReader(openFileDialog.FileName))
        {
            text =  streamReader.ReadToEnd();
        }

        string[] inputs = text.Split(',');
        List<int> list = new List<int>();
        foreach (var input in inputs)
        {
            list.Add(Convert.ToInt32(input));
        }

        string res = "";
        foreach (var item in list)
        {
            if (item % 3 == 0 && item % 7 != 0)
            {
                res += $"{item},";
            }
        }

        SaveFileDialog saveFileDialog = new SaveFileDialog();
        saveFileDialog.ShowDialog();
        using (StreamWriter streamWriter = new StreamWriter(saveFileDialog.FileName))
        {
            streamWriter.WriteLineAsync(res);
        }
    }

    private void ButtonC_OnClick(object sender, RoutedEventArgs e)
    {
        OpenFileDialog openFileDialog = new OpenFileDialog();
        openFileDialog.ShowDialog();
        string text;
        using (StreamReader streamReader = new StreamReader(openFileDialog.FileName))
        {
            text =  streamReader.ReadToEnd();
        }

        string[] inputs = text.Split(',');
        List<int> list = new List<int>();
        foreach (var input in inputs)
        {
            list.Add(Convert.ToInt32(input));
        }

        string res = "";
        foreach (var item in list)
        {
            if (Math.Sqrt(item) % 1 == 0)
            {
                res += $"{item},";
            }
        }

        SaveFileDialog saveFileDialog = new SaveFileDialog();
        saveFileDialog.ShowDialog();
        using (StreamWriter streamWriter = new StreamWriter(saveFileDialog.FileName))
        {
            streamWriter.WriteLineAsync(res);
        }
    }

   
}
```
#### Результат работы программы ####
![img.png](src/img6.png)

#### Вывод ####

Разработали законченное оконное приложение — текстовый редактор, работающий с несколькими документами с возможностями открытия и сохранения, отмены действий, работы с буфером обмена и другими.
