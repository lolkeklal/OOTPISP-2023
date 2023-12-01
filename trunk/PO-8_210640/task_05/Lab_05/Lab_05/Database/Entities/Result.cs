using System.ComponentModel;

namespace Lab_05.Database.Entities;

public class Result : INotifyPropertyChanged
{
    public int Id { get; set; }

    private Student _student;
    public virtual Student Student
    {
        get => _student;
        set
        {
            if (_student == value)
            {
                return;
            }

            _student = value;
            PropertyChanged?.Invoke(this, new(nameof(Student)));
        }
    }

    private Session _session;
    public virtual Session Session
    {
        get => _session;
        set
        {
            if (_session == value)
            {
                return;
            }

            _session = value;
            PropertyChanged?.Invoke(this, new(nameof(Session)));
        }
    }

    private bool _passed;
    public bool Passed
    {
        get => _passed;
        set
        {
            if (_passed == value) 
            {
                return;
            }

            _passed = value;
            PropertyChanged?.Invoke(this, new(nameof(Passed)));
        }
    }


    public event PropertyChangedEventHandler? PropertyChanged;

    public override string ToString()
    {
        return $"{Student} {Session} {(Passed ? "Passed" : "Failed")}";
    }
}
