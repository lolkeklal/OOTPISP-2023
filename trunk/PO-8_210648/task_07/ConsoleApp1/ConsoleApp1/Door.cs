namespace ConsoleApp1;

public class Door
{
    protected Room _room1;
    protected Room _room2;

    public Door(Room room1, Room room2)
    {
        _room1 = room1;
        _room2 = room2;
    }

    public override string ToString()
    {
       return $"Door: r1: {_room1} r2: {_room2}";
    }

    public virtual Door Clone()
    {
        return new Door(_room1, _room2);
    }
}

public class ArmoredDoor : Door
{
    private int _armor;

    public ArmoredDoor(Room room1, Room room2, int armor) : base(room1, room2)
    {
        _armor = armor;
    }

    public override string ToString()
    {
        return $"Armored Door: r1:{_room1} r2:{_room2} armor:{_armor}";
    }
    
    public override Door Clone()
    {
        return new ArmoredDoor(_room1, _room2,_armor);
    }
}