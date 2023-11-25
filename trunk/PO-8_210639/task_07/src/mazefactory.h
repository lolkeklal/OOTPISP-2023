#pragma once
#ifndef MAZEFACTORY_H
#define MAZEFACTORY_H

#include "door.h"

class MazeFactory {
public:
	static MazeFactory* Instance();
	virtual Room* makeRoom(int n) = 0;
	virtual Door* makeDoor(Room* r1, Room* r2) = 0;
	
protected:
	virtual Room* cloneRoom() = 0;
	virtual Door* cloneDoor() = 0;
	MazeFactory() {};
private:
	static MazeFactory* instance;
};

#endif