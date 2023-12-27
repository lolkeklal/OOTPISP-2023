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