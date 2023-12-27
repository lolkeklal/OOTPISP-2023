#include <iostream>

#include "AbstractFactory.h"


int main() {
    AbstractFactory* factory = new Factory();

    Head* head = factory->createHead();
    Body* body = factory->createBody();
    Ending* ending = factory->createEnding();

    head->render();
    body->render();
    ending->render();

    delete factory;
    delete head;
    delete body;
    delete ending;
    
    return 0;
}
