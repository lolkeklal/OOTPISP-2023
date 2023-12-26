using System;
using System.Windows;

namespace lab3;

public partial class Task2Window : Window
{
    public Task2Window()
    {
        InitializeComponent();
    }

    private void RunButton_OnClick(object sender, RoutedEventArgs e)
    {
        string[] inp1 = Arr1TextBox.Text.Split(' ');
        string[] inp2 = Arr2TextBox.Text.Split(' ');
        int[] arr1 = new int[Convert.ToInt32(inp1[0])];
        int[,] arr2 = new int[Convert.ToInt32(inp2[0]), Convert.ToInt32(inp2[1])];
        for (int i = 0; i < arr1.Length; i++)
        {
            arr1[i] = Convert.ToInt32(inp1[i + 1]);
        }

        int index = 0;
        for (int i = 0; i < Convert.ToInt32(inp2[0]); i++)
        {
            for (int j = 0; j < Convert.ToInt32(inp2[1]); j++)
            {
                arr2[i, j] = Convert.ToInt32(inp2[index + 2]);
                index++;
            }
        }

        string result = "";
        string temp = "";
        foreach (var item in arr1)
        {
            if (item % 2 == 0)
            {
                result += $"{item} ";
            }
            else
            {
                temp += $"{item} ";
            }
        }

        result += $"\n{temp}";

        result += "\n\n";
        for (int i = 0; i < Convert.ToInt32(inp2[0]); i++)
        {
            int max = arr2[i, 0];
            int maxIndex = 0;
            int min = arr2[i, 0];
            int minIndex = 0;
            for (int j = 1; j < Convert.ToInt32(inp2[1]); j++)
            {
                if (arr2[i, j] > max)
                {
                    max = arr2[i, j];
                    maxIndex = j;
                }

                if (arr2[i, j] < min)
                {
                    min = arr2[i, j];
                    minIndex = j;
                }
            }

            (arr2[i, minIndex], arr2[i, maxIndex]) = (arr2[i, maxIndex], arr2[i, minIndex]);
            for (int j = 0; j < Convert.ToInt32(inp2[1]); j++)
            {
                result += $"{arr2[i, j]}";
            }

            result += "\n";
        }

        ResultLabel.Content = result;
    }
}