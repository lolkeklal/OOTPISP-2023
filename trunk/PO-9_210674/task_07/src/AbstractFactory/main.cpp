#include <iostream>

class Room {
public:
    virtual void enter() const = 0;
    virtual ~Room() {}
};

class Door {
public:
    virtual void open() const = 0;
    virtual ~Door() {}
};


class OrdinaryRoom : public Room {
public:
    void enter() const override {
        std::cout << "You entered an ordinary room." << std::endl;
    }
};

class MagicRoom : public Room {
public:
    void enter() const override {
        std::cout << "You entered a magic room." << std::endl;
    }
};

class OrdinaryDoor : public Door {
public:
    void open() const override {
        std::cout << "You opened an ordinary door." << std::endl;
    }
};

class MagicDoor : public Door {
public:
    void open() const override {
        std::cout << "You opened a magic door." << std::endl;
    }
};

// Abstract Factory
class MazeFactory {
public:
    virtual Room* makeRoom() const = 0;
    virtual Door* makeDoor() const = 0;
    virtual ~MazeFactory() {}
};

// Abstract factory for ordinary doors and rooms
class OrdinaryMazeFactory : public MazeFactory {
public:
    Room* makeRoom() const override {
        return new OrdinaryRoom();
    }

    Door* makeDoor() const override {
        return new OrdinaryDoor();
    }
};

// Abstract factory for magic doors and rooms
class MagicMazeFactory : public MazeFactory {
public:
    Room* makeRoom() const override {
        return new MagicRoom();
    }

    Door* makeDoor() const override {
        return new MagicDoor();
    }
};


void createMaze(MazeFactory& factory) {
    Room* room = factory.makeRoom();
    Door* door = factory.makeDoor();

    room->enter();
    door->open();


    delete room;
    delete door;
}

int main() {

    OrdinaryMazeFactory ordinaryFactory;
    std::cout << "Creating ordinary maze:" << std::endl;
    createMaze(ordinaryFactory);

    MagicMazeFactory magicFactory;
    std::cout << "\nCreating magic maze:" << std::endl;
    createMaze(magicFactory);

    return 0;
}
