#pragma once
#ifndef CONCRETEROOM_H
#define CONCRETEROOM_H

#include "room.h"

class concreteRoom :public Room {
public:
	concreteRoom(int _roomNumber);
	void initialize(int _roomNumber) override;
	Room* clone() const override;
	void print() override;
};

#endif