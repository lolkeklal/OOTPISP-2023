using System;
using System.Windows;
using System.Windows.Input;

namespace Lab_02;

public class SaveCommand : ICommand
{
    private MainWindow _mainWindow;
    private Action<object, RoutedEventArgs> _onSave;
    public SaveCommand(MainWindow mainWindow, Action<object, RoutedEventArgs> onSave)
    {
        _mainWindow = mainWindow;
        _onSave = onSave;
    }

    public void Execute(object parameter)
    {
        _onSave(_mainWindow, null);
    }

    public bool CanExecute(object parameter)
    {
        return _mainWindow.SaveCanExecute;
    }

    public event EventHandler CanExecuteChanged;
}
