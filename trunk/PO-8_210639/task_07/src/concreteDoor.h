#pragma once
#ifndef CONCRETEDOOR_H
#define CONCRETEDOOR_H

#include "door.h"

class concreteDoor :public Door {
public:
	concreteDoor(Room* _r1, Room* _r2);
	void initialize(Room* _r1, Room* _r2) override;
	Door* clone() const override;
	void print() override;
};

#endif