using ConsoleApp1;

AbstractFabric abstractFabric = new AbstractFabric();
CreateMaze(abstractFabric);
FabricArmored fabricArmored = new FabricArmored();
CreateMaze(fabricArmored);
FabricSingleton fabricSingleton = FabricSingleton.Instance;
CreateMaze(fabricSingleton);

PrototypeFabric prototypeFabric = new PrototypeFabric(new Room(1), new Door(new Room(1), new Room(2)));
CreateMaze(prototypeFabric);

void CreateMaze(AbstractFabric abstractFabric)
{
    Room room1 = abstractFabric.CreateRoom(1);
    Room room2 = abstractFabric.CreateRoom(2);
    Door door = abstractFabric.CreateDoor(room1, room2);
    Console.WriteLine(room1);
    Console.WriteLine(room2);
    Console.WriteLine(door);
    
}