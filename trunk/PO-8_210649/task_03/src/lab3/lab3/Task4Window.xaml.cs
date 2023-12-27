using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;

namespace lab3;

public partial class Task4Window : Window
{
    public Task4Window()
    {
        InitializeComponent();
    }

    private void Button_OnClick(object sender, RoutedEventArgs e)
    {
        string[] inp = InpTextBox.Text.Split(' ');
        Stack<int> stack = new Stack<int>();
        for (int i = 0; i < 5; i++)
        {
            stack.Push(Convert.ToInt32(inp[i]));
        }

        int[] arr = stack.ToArray();
        
        int max = int.MinValue;
        int maxI = 0;
        int min = int.MaxValue;
        int minI = 0;
        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                maxI = i;
            }

            if (arr[i] < min)
            {
                min = arr[i];
                minI = i;
            }
        }

        (arr[maxI], arr[minI]) = (arr[minI], arr[maxI]);
        string result = "Res:\n";
        foreach (var i in arr)
        {
            result += $"{i} ";
        }

        result += "\nInp:\n";
        Random rnd = new Random();
        Queue<int> queue = new Queue<int>();
        for (int i = 0; i < rnd.Next(4,10); i++)
        {
            queue.Enqueue(rnd.Next(0,50));
        }

        int[] arr1 = queue.ToArray();
        int sum = 0, counter = 0;
        for (int i = 0; i < arr1.Length; i++)
        {
            result += $"{arr1[i]} ";
            if (arr1[i] % 2 == 0)
            {
                sum += arr1[i];
                counter++;
            }
        }

        result += $"\nRes:\n";
        for (int i = 0; i < arr1.Length; i++)
        {
            if (arr1[i] % 2 == 0)
            {
                arr1[i] = sum / counter;
            }

            result += $"{arr1[i]} ";
        }

        Label.Content = result;


    }
}