#pragma once
#ifndef CONCRETEMAZEFACTORY_H
#define CONCRETEMAZEFACTORY_H

#include "mazefactory.h"

class concreteMazeFactory : public MazeFactory {
public:
	concreteMazeFactory(Room* r, Door* d);
	Room* makeRoom(int n) override;
	Door* makeDoor(Room* r1, Room* r2) override;
private:
	Room* cloneRoom() override;
	Door* cloneDoor() override;
	Room* concreteRoomPrototype;
	Door* concreteDoorPrototype;
};

#endif