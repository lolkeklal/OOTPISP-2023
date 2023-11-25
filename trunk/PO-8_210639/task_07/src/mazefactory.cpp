#include "mazefactory.h"
#include "concretemazefactory.h"
#include "concreteRoom.h"
#include "concreteDoor.h"

MazeFactory* MazeFactory::instance = 0;

MazeFactory* MazeFactory::Instance()
{
	if (instance == 0)
	{
		concreteRoom* r1 = new concreteRoom(1);
		concreteRoom* r2 = new concreteRoom(2);
		concreteDoor* d = new concreteDoor(r1, r2);
		instance = new concreteMazeFactory(r1, d);
	}
	return instance;
}