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