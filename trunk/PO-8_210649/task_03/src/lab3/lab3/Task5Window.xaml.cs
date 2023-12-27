using System;
using System.Collections.Generic;
using System.Windows;

namespace lab3;

public partial class Task5Window : Window
{
    public Task5Window()
    {
        InitializeComponent();
    }

    private void Button_OnClick(object sender, RoutedEventArgs e)
    {
        int[] allFish = new int[]
        {
            1, 2, 3, 4, 5, 6, 7, 8
        };
        List<int> fish1 = new List<int>();
        List<int> fish2 = new List<int>();
        List<int> fish3 = new List<int>();
        string[] inp1 = TextBox1.Text.Split(' ');
        string[] inp2 = TextBox2.Text.Split(' ');
        string[] inp3 = TextBox3.Text.Split(' ');
        foreach (var s in inp1)
        {
            fish1.Add(Convert.ToInt32(s));
        }
        foreach (var s in inp2)
        {
            fish2.Add(Convert.ToInt32(s));
        }
        foreach (var s in inp3)
        {
            fish3.Add(Convert.ToInt32(s));
        }

        List<int> resultList1 = new List<int>();
        List<int> resultList2 = new List<int>();
        foreach (var i in allFish)
        {
            if (fish1.Contains(i) && fish2.Contains(i) && fish3.Contains(i))
            {
                resultList1.Add(i);
            }
            else if(!fish1.Contains(i) && !fish2.Contains(i) && !fish3.Contains(i))
            {
                resultList2.Add(i);
            }
        }

        string result = "Y kazdogo:\n";
        foreach (var i in resultList1)
        {
            result += $"{i} ";
        }

        result += "\nNe y kogo:\n";
        foreach (var i in resultList2)
        {
            result += $"{i} ";
        }

        Label.Content = result;
    }
}