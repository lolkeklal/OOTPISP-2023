#include <iostream>

#include "AbstractFactory.h"


int main() {
    AbstractFactory* Factory = new LinuxFactory();

    Head* head = Factory->createHead();
    Body* body = Factory->createBody();
    Ending* ending = Factory->createEnding();

    head->render();
    body->render();
    ending->render();

    delete Factory;
    delete head;
    delete body;
    delete ending;
    
    return 0;
}
