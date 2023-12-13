#include <iostream>
#include <string>

// Abstract Product: Room
class Room {
public:
    virtual void enter() const = 0;
    virtual Room* clone() const = 0;
    virtual ~Room() {}
};

// Concrete Product: MazeRoom
class MazeRoom : public Room {
public:
    void enter() const override {
        std::cout << "Entering Maze Room" << std::endl;
    }

    Room* clone() const override {
        return new MazeRoom(*this);
    }
};

// Abstract Product: Door
class Door {
public:
    virtual void open() const = 0;
    virtual Door* clone() const = 0;
    virtual ~Door() {}
};

// Concrete Product: MazeDoor
class MazeDoor : public Door {
public:
    void open() const override {
        std::cout << "Opening Maze Door" << std::endl;
    }

    Door* clone() const override {
        return new MazeDoor(*this);
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual Room* createRoom() const = 0;
    virtual Door* createDoor() const = 0;
    virtual ~AbstractFactory() {}
};

// Concrete Factory: MazeFactory
class MazeFactory : public AbstractFactory {
public:
    Room* createRoom() const override {
        return new MazeRoom();
    }

    Door* createDoor() const override {
        return new MazeDoor();
    }
};

// Prototype
class MazePrototypeFactory : public AbstractFactory {
private:
    Room* roomPrototype;
    Door* doorPrototype;

public:
    MazePrototypeFactory(Room* room, Door* door)
        : roomPrototype(room), doorPrototype(door) {}

    ~MazePrototypeFactory() {
        delete roomPrototype;
        delete doorPrototype;
    }

    Room* createRoom() const override {
        return roomPrototype->clone();
    }

    Door* createDoor() const override {
        return doorPrototype->clone();
    }
};

// Singleton Factory
class SingletonMazeFactory : public AbstractFactory {
private:
    SingletonMazeFactory() {}

public:
    static SingletonMazeFactory* getInstance() {
        static SingletonMazeFactory instance;
        return &instance;
    }

    Room* createRoom() const override {
        return new MazeRoom();
    }

    Door* createDoor() const override {
        return new MazeDoor();
    }
};

int main() {
    // Using Abstract Factory
    AbstractFactory* mazeFactory = new MazeFactory();
    Room* room = mazeFactory->createRoom();
    Door* door = mazeFactory->createDoor();

    room->enter();
    door->open();

    delete mazeFactory;
    delete room;
    delete door;

    // Using Prototype with Abstract Factory
    Room* prototypeRoom = new MazeRoom();
    Door* prototypeDoor = new MazeDoor();
    AbstractFactory* prototypeFactory = new MazePrototypeFactory(prototypeRoom, prototypeDoor);

    Room* roomClone = prototypeFactory->createRoom();
    Door* doorClone = prototypeFactory->createDoor();

    roomClone->enter();
    doorClone->open();

    delete prototypeFactory;
    delete roomClone;
    delete doorClone;

    // Using Singleton with Abstract Factory
    AbstractFactory* singletonFactory = SingletonMazeFactory::getInstance();
    Room* singletonRoom = singletonFactory->createRoom();
    Door* singletonDoor = singletonFactory->createDoor();

    singletonRoom->enter();
    singletonDoor->open();

    return 0;
}
