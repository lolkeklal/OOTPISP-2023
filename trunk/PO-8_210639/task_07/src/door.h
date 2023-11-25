#pragma once
#ifndef DOOR_H
#define DOOR_H

#include "room.h"

class Door {
public:
	virtual void initialize(Room* _r1, Room* _r2)=0;
	virtual Door* clone() const=0;
	virtual void print()=0;
protected:
	Room* r1;
	Room* r2;
};

#endif