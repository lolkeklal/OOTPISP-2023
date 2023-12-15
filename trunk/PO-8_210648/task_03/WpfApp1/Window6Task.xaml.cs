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