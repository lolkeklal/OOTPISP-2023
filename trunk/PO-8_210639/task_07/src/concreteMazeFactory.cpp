#include "concreteMazeFactory.h"
#include "concreteRoom.h"
#include "concreteDoor.h"

concreteMazeFactory::concreteMazeFactory(Room* r, Door* d)
{
	concreteRoomPrototype = r;
	concreteDoorPrototype = d;
}
Room* concreteMazeFactory::cloneRoom() {
	return concreteRoomPrototype->clone();
}
Room* concreteMazeFactory::makeRoom(int n)
{
	Room* newRoom = static_cast<Room*>(cloneRoom());
	newRoom->initialize(n);
	return newRoom;
}



Door* concreteMazeFactory::makeDoor(Room* r1, Room* r2)
{
	Door* newDoor = static_cast<Door*>(cloneDoor());
	newDoor->initialize(r1, r2);
	return newDoor;
}

Door* concreteMazeFactory::cloneDoor() {
	return concreteDoorPrototype->clone();
}