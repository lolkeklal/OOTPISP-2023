namespace ConsoleApp2;

public class Product
{
    private string[] _eyes;
    private string[] _nose;
    private string[] _mouth;
    private string[] _ears;
    private string[] _hair;
    
    public string[] Eyes => _eyes;
    public string[] Nose => _nose; 
    public string[] Mouth => _mouth; 
    public string[] Ears => _ears; 
    public string[] Hair => _hair;

    public void AddEyes(string[] eyes)
    {
        _eyes = eyes;
    }

    public void AddNose(string[] nose)
    {
        _nose = nose;
    }

    public void AddMouth(string[] mouth)
    {
        _mouth = mouth;
    }

    public void AddEars(string[] ears)
    {
        _ears = ears;
    }

    public void AddHair(string[] hair)
    {
        _hair = hair;
    }

    public void Show()
    {
        Console.WriteLine($"Eyes: {_eyes[0]} {_eyes[1]}\n" +
                          $"Nose: {_nose[0]} {_nose[1]}\n" +
                          $"Mouth: {_mouth[0]} {_mouth[1]}\n" +
                          $"Ears: {_ears[0]} {_ears[1]}\n" +
                          $"Hair: {_hair[0]} {_hair[1]}\n\n");
    }
}