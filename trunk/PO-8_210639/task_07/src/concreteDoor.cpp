#include "concreteDoor.h"
#include <QDebug>

concreteDoor::concreteDoor(Room* _r1, Room* _r2)
{
		r1 = _r1;
		r2 = _r2;
}

void concreteDoor::initialize(Room* _r1, Room* _r2) {
	r1 = _r1;
	r2 = _r2;
}

Door* concreteDoor::clone() const {
	return new concreteDoor(*this);
}

void concreteDoor::print() {
	qDebug() << "concreteDoor between rooms: ";
	r1->print();
	r2->print();
}