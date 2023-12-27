using System;
using System.Collections.Generic;
using System.Windows;

namespace lab3;

public partial class Task3Window : Window
{
    public Task3Window()
    {
        InitializeComponent();
    }

    private void RunButton_OnClick(object sender, RoutedEventArgs e)
    {
        List<int> list1 = new List<int>();
        List<int> list2 = new List<int>();
        Random rnd = new Random();
        for (int i = 0; i < rnd.Next(1,10); i++)
        {
            list1.Add(rnd.Next(-10,10));
            list2.Add(rnd.Next(-10,10));
        }
        string result = "input:\n ";
        foreach (var i in list1)
        {
            result += $"{i} ";
        }

        result += "\n";
        foreach (var i in list2)
        {
            result += $"{i} ";
        }

        result += "\n";

        int min = int.MaxValue;
        foreach (var i in list2)
        {
            if (i < min)
                min = i;
        }

        for (int i = 0; i < list1.Count; i++)
        {
            if (list1[i] < 0)
            {
                list1[i] = min;
            }
        }

        result += "result:\n ";
        foreach (var i in list1)
        {
            result += $"{i} ";
        }

        result += "\n";
        foreach (var i in list2)
        {
            result += $"{i} ";
        }
        
        result += "\ninput2:\n";
        List<string> list3 = new List<string>();
        for (int i = 0; i < rnd.Next(6,10); i++)
        {
            list3.Add(GenStr());
        }
        foreach (var i in list3)
        {
            result += $"{i} ";
        }

        result += "\nresult:\n";
        foreach (var i in list3)
        {
            if (i.Length < Convert.ToInt32(InputTextBox.Text))
                result += $"{i} ";
        }
        
        ResultLabel.Content = result;
    }

    private string GenStr()
    {
        Random rnd = new Random();
        string str = "";
        for (int i = 0; i < rnd.Next(1,10); i++)
        {
            str += "l";
        }

        return str;
    }
}