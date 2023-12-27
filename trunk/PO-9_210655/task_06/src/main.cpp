#include <iostream>

#include "AbstractFactory.h"


int main() {
    setlocale(LC_ALL, "");

    AbstractFactory* linuxFactory = new WinFactory();

    List* list = linuxFactory->createList();
    InputField* inputField = linuxFactory->createInputField();
    Button* button = linuxFactory->createButton();
    Language* language = linuxFactory->createLanguage();

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
