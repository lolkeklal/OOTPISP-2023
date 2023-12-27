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