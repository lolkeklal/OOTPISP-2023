namespace ConsoleApp1;

public class FabricSingleton : AbstractFabric
{
    private static readonly Lazy<FabricSingleton> instance =
        new Lazy<FabricSingleton>(() => new FabricSingleton());
    
    public static FabricSingleton Instance
    {
        get { return instance.Value; }
    }
    public override Room CreateRoom(int n)
    {
        return new Room(n);
    }

    public override Door CreateDoor(Room r1, Room r2)
    {
        return new Door(r1, r2);
    }

    private FabricSingleton()
    {
        
    }
    
}