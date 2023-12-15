namespace ConsoleApp1;

public class AbstractFabric
{
    public virtual Door CreateDoor(Room r1, Room r2)
    {
        return new Door(r1, r2);
    }

    public virtual Room CreateRoom(int n)
    {
        return new Room(n);
    }
    
}

public class PrototypeFabric : AbstractFabric
{
    private Room _room;
    private Door _door;


    public PrototypeFabric(Room room, Door door)
    {
        _room = room;
        _door = door;
    }

    public override Door CreateDoor(Room r1, Room r2)
    {
        return _door.Clone();
    }

    public override Room CreateRoom(int n)
    {
        return _room.Clone();
    }
}

public class FabricArmored : AbstractFabric
{
    public override Door CreateDoor(Room r1, Room r2)
    {
        return new ArmoredDoor(r1, r2, 10);
    }

    public override Room CreateRoom(int n)
    {
        return new ArmoredRoom(n, 10);
    }
}