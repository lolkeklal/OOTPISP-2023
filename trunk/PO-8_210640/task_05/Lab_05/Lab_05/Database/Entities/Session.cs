using System.ComponentModel;

namespace Lab_05.Database.Entities;

public enum SessionType
{
    Exam,
    Credit,
}

public class Session : INotifyPropertyChanged
{
    public int Id { get; set; }


    private string _discipline = string.Empty;
    public string Discipline
    {
        get => _discipline;
        set
        {
            if (_discipline == value) 
            {
                return;
            }

            _discipline = value;
            PropertyChanged?.Invoke(this, new(nameof(Discipline)));
        }
    }

    private SessionType _type;
    public SessionType Type
    {
        get => _type;
        set
        {
            if (_type == value) 
            {
                return;
            }

            _type = value;
            PropertyChanged?.Invoke(this, new(nameof(Type)));
        }
    }


    public event PropertyChangedEventHandler? PropertyChanged;

    public override string ToString()
    {
        return $"{Discipline} ({Type})";
    }
}
