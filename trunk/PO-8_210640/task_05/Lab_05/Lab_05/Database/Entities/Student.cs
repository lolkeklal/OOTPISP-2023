using System.ComponentModel;

namespace Lab_05.Database.Entities;

public class Student : INotifyPropertyChanged
{
    public int Id { get; set; }

    private string _name = string.Empty;
    public string Name
    {
        get => _name;
        set
        {
            if (_name == value) 
            {
                return;
            }

            _name = value;
            PropertyChanged?.Invoke(this, new(nameof(Name)));
        }
    }

    private string _surname = string.Empty;
    public string Surname
    {
        get => _surname;
        set
        {
            if (_surname == value) 
            {
                return;
            }

            _surname = value;
            PropertyChanged?.Invoke(this, new(nameof(Surname)));
        }
    }

    private string _patronymic = string.Empty;
    public string Patronymic
    {
        get => _patronymic;
        set
        {
            if (_patronymic == value) 
            {
                return;
            }

            _patronymic = value;
            PropertyChanged?.Invoke(this, new(nameof(Patronymic)));
        }
    }

    public event PropertyChangedEventHandler? PropertyChanged;

    public override string ToString()
    {
        return $"{Name} {Surname} {Patronymic}";
    }
}
