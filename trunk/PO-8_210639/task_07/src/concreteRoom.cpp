#include "concreteRoom.h"
#include <QDebug>

concreteRoom::concreteRoom(int _roomNumber) {
	roomNumber = _roomNumber;
}

void concreteRoom::initialize(int _roomNumber){
	roomNumber = _roomNumber;
}

Room* concreteRoom::clone() const {
	return new concreteRoom(*this);
}

void concreteRoom::print() {
	qDebug() << "concreteRoom: "<<roomNumber;
}