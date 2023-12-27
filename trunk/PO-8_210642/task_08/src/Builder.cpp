#include <iostream>
#include <string>
#include <memory>  // Include for std::unique_ptr

// Product Parts
class Eyes {
public:
    std::string color;
    std::string figure;
};

class Nose {
public:
    std::string color;
    std::string figure;
};

class Mouth {
public:
    std::string color;
    std::string figure;
};

class Ears {
public:
    std::string color;
    std::string figure;
};

class Hair {
public:
    std::string color;
    std::string figure;
};

// Product
class Face {
public:
    Eyes eyes;
    Nose nose;
    Mouth mouth;
    Ears ears;
    Hair hair;

    void display() const {
        std::cout << "Face Details:" << std::endl;
        std::cout << "Eyes: " << eyes.color << ", " << eyes.figure << std::endl;
        std::cout << "Nose: " << nose.color << ", " << nose.figure << std::endl;
        std::cout << "Mouth: " << mouth.color << ", " << mouth.figure << std::endl;
        std::cout << "Ears: " << ears.color << ", " << ears.figure << std::endl;
        std::cout << "Hair: " << hair.color << ", " << hair.figure << std::endl;
    }
};

// Builder Interface
class FaceBuilder {
protected:
    Face* face;

public:
    FaceBuilder() : face(new Face()) {}

    // Copy constructor
    FaceBuilder(const FaceBuilder& other) : face(new Face(*(other.face))) {}

    // Assignment operator
    FaceBuilder& operator=(const FaceBuilder& other) {
        if (this != &other) {
            delete face;
            face = new Face(*(other.face));
        }
        return *this;
    }

    virtual void buildEyes() = 0;
    virtual void buildNose() = 0;
    virtual void buildMouth() = 0;
    virtual void buildEars() = 0;
    virtual void buildHair() = 0;

    // Transfer ownership in getFace method
    virtual std::unique_ptr<Face> getFace() {
        std::unique_ptr<Face> result(face);
        face = nullptr;  // Release ownership
        return result;
    }

    virtual ~FaceBuilder() {
        delete face;
    }
};

// Concrete Builder: UglyFaceBuilder
class UglyFaceBuilder : public FaceBuilder {
public:
    void buildEyes() override {
        face->eyes.color = "Red";
        face->eyes.figure = "Small";
    }

    void buildNose() override {
        face->nose.color = "Green";
        face->nose.figure = "Crooked";
    }

    void buildMouth() override {
        face->mouth.color = "Blue";
        face->mouth.figure = "Big";
    }

    void buildEars() override {
        face->ears.color = "Yellow";
        face->ears.figure = "Large";
    }

    void buildHair() override {
        face->hair.color = "Purple";
        face->hair.figure = "Messy";
    }
};

// Concrete Builder: GoodFaceBuilder
class GoodFaceBuilder : public FaceBuilder {
public:
    void buildEyes() override {
        face->eyes.color = "Brown";
        face->eyes.figure = "Normal";
    }

    void buildNose() override {
        face->nose.color = "Pink";
        face->nose.figure = "Straight";
    }

    void buildMouth() override {
        face->mouth.color = "Red";
        face->mouth.figure = "Average";
    }

    void buildEars() override {
        face->ears.color = "Beige";
        face->ears.figure = "Medium";
    }

    void buildHair() override {
        face->hair.color = "Black";
        face->hair.figure = "Neat";
    }
};

// Director
class FaceDirector {
public:
    void buildFace(FaceBuilder* builder) {
        builder->buildEyes();
        builder->buildNose();
        builder->buildMouth();
        builder->buildEars();
        builder->buildHair();
    }
};

int main() {
    // Using Builder Pattern
    UglyFaceBuilder uglyBuilder;
    GoodFaceBuilder goodBuilder;

    FaceDirector director;

    std::cout << "Ugly Face:" << std::endl;
    director.buildFace(&uglyBuilder);
    std::unique_ptr<Face> uglyFace = uglyBuilder.getFace();
    uglyFace->display();

    std::cout << "\nGood Face:" << std::endl;
    director.buildFace(&goodBuilder);
    std::unique_ptr<Face> goodFace = goodBuilder.getFace();
    goodFace->display();

    return 0;
}
