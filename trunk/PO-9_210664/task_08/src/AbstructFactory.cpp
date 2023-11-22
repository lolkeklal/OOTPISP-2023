#include <QDebug>

#include <iostream>
#include <map>

// Прототипы
class Room {
public:
    virtual void print() const = 0;
    virtual Room* clone() const = 0;
};

class Door {
public:
    virtual void print() const = 0;
    virtual Door* clone() const = 0;
};

// Абстрактная фабрика
class MazeFactory {
public:
    virtual Room* makeRoom() const = 0;
    virtual Door* makeDoor(Room* r1, Room* r2) const = 0;
    virtual Room* cloneRoom(const Room* room) const = 0;
    virtual Door* cloneDoor(const Door* door) const = 0;
};

// Пример конкретных продуктов
class ConcreteRoom : public Room {
public:
    void print() const override {
        qDebug() << "Concrete Room\n";
    }

    Room* clone() const override {
        return new ConcreteRoom(*this);
    }
};

class ConcreteDoor : public Door {
public:
    ConcreteDoor(Room* r1, Room* r2) : room1(r1), room2(r2) {}

    void print() const override {
        qDebug() << "Concrete Door\n";
    }

    Door* clone() const override {
        return new ConcreteDoor(*this);
    }

private:
    Room* room1;
    Room* room2;
};

// Пример конкретной фабрики
class ConcreteMazeFactory : public MazeFactory {
public:
    Room* makeRoom() const override {
        return new ConcreteRoom();
    }

    Door* makeDoor(Room* r1, Room* r2) const override {
        return new ConcreteDoor(r1, r2);
    }

    Room* cloneRoom(const Room* room) const override {
        return room->clone();
    }

    Door* cloneDoor(const Door* door) const override {
        return door->clone();
    }
};
