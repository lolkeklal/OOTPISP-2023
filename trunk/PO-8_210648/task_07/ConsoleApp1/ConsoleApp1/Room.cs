namespace ConsoleApp1;

public class Room
{
    protected int _n;

    public Room(int n)
    {
        _n = n;
    }

    public override string ToString()
    {
        return $"Room: {_n}";
    }

    public virtual Room Clone()
    {
        return new Room(_n);
    }
}

public class ArmoredRoom : Room
{
    private int _armor;

    public ArmoredRoom(int n, int armored) : base(n)
    {
        _armor = armored;
    }

    public override string ToString()
    {
        return $"Armored Room: {_n} armor: {_armor}";
    }
    public override Room Clone()
    {
        return new ArmoredRoom(_n,_armor);
    }
}