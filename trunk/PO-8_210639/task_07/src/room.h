#pragma once
#ifndef ROOM_H
#define ROOM_H

class Room {
public:
	virtual void initialize(int _roomNumber)=0;
	virtual Room* clone() const=0;
	virtual void print()=0;
protected:
	int roomNumber;
};

#endif