using System;
using System.Windows;

namespace lab3;

public partial class Task1Window : Window
{
    public Task1Window()
    {
        InitializeComponent();
    }

    private void RunButton_OnClick(object sender, RoutedEventArgs e)
    {
        string[] inp = TextBoxInput.Text.Split(' ');
        int[] arr = new int[3];
        int maxIndex = -1;
        int max = int.MinValue;
        for (int i = 0; i < 3; i++)
        {
            arr[i] = Convert.ToInt32(inp[i]);
            if (arr[i] > max)
            {
                max = arr[i];
                maxIndex = i;
            }
        }

        switch (maxIndex)
        {
            case 0:
                arr[0] = arr[1] - arr[2];
                break;
            case 1:
                arr[1] = arr[0] - arr[2];
                break;
            case 2:
                arr[2] = arr[0] - arr[1];
                break;
        }

        ResultLAbel.Content = $"Result: {arr[0]} {arr[1]} {arr[2]}";

    }
}