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