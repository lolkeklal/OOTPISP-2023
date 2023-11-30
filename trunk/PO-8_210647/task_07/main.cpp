#include <iostream>

#include "AbstractFactory.h"


int main() {
    AbstractFactory* linuxFactory = new LinuxFactory();

    List* list = linuxFactory->createList();
    InputField* inputField = linuxFactory->createInputField();
    Button* button = linuxFactory->createButton();
    Language* language = linuxFactory->createLanguage(); //210647

    list->render();
    inputField->render();
    button->render();
    language->display();

    delete linuxFactory;
    delete list;
    delete inputField;
    delete button;
    delete language;
    
    return 0;
}
