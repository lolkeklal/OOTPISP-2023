#include <iostream>
#include <string>

// Prototype for User
class User {
public:
    virtual User* clone() const = 0;
    virtual void introduce() const = 0;
    virtual ~User() {}
};


class OrdinaryUser : public User {
private:
    std::string name;

public:
   explicit OrdinaryUser(const std::string& name) : name(name) {}

    User* clone() const override {
        return new OrdinaryUser(*this);
    }

    void introduce() const override {
        std::cout << "I'm an ordinary user named " << name << "." << std::endl;
    }
};


class MagicUser : public User {
private:
    std::string name;

public:
    explicit MagicUser(const std::string& name) : name(name) {}

    User* clone() const override {
        return new MagicUser(*this);
    }

    void introduce() const override {
        std::cout << "I'm a magic user named " << name << "." << std::endl;
    }
};


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
        std::cout << "Entering an ordinary room." << std::endl;
    }
};


class OrdinaryDoor : public Door {
public:
    void open() const override {
        std::cout << "Opening an ordinary door." << std::endl;
    }
};


class MagicRoom : public Room {
public:
    void enter() const override {
        std::cout << "Entering a magic room." << std::endl;
    }
};


class MagicDoor : public Door {
public:
    void open() const override {
        std::cout << "Opening a magic door." << std::endl;
    }
};

template <class RoomType, class DoorType, class UserType>
class MazeFactory {
public:
    virtual RoomType* makeRoom() const = 0;
    virtual DoorType* makeDoor() const = 0;
    virtual UserType* makeUser(const std::string& name) const = 0;
    virtual ~MazeFactory() {}
};

// abstract factory for ordinary rooms, doors and users
class OrdinaryMazeFactory : public MazeFactory<Room, Door, OrdinaryUser> {
public:
    Room* makeRoom() const override {
        return new OrdinaryRoom();
    }

    Door* makeDoor() const override {
        return new OrdinaryDoor();
    }

    OrdinaryUser* makeUser(const std::string& name) const override {
        return new OrdinaryUser(name);
    }
};

// abstract factory for magic rooms, doors and users
class MagicMazeFactory : public MazeFactory<Room, Door, MagicUser> {
public:
    Room* makeRoom() const override {
        return new MagicRoom();
    }

    Door* makeDoor() const override {
        return new MagicDoor();
    }

    MagicUser* makeUser(const std::string& name) const override {
        return new MagicUser(name);
    }
};

template <class RoomType, class DoorType, class UserType>
void createMaze(const MazeFactory<RoomType, DoorType, UserType>& factory, const std::string& userName) {
    RoomType* room = factory.makeRoom();
    DoorType* door = factory.makeDoor();
    UserType* user = factory.makeUser(userName);

    room->enter();
    door->open();
    user->introduce();

    delete room;
    delete door;
    delete user;
}

int main() {

    OrdinaryMazeFactory ordinaryFactory;
    std::cout << "Creating ordinary maze:" << std::endl;
    createMaze(ordinaryFactory, "John");

    MagicMazeFactory magicFactory;
    std::cout << "\nCreating magic maze:" << std::endl;
    createMaze(magicFactory, "Alice");

    return 0;
}
 
