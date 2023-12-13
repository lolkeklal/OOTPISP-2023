#include <iostream>

#include "AbstractFactory.h"

int main() {
    AbstractFactory* winFactory = new WindowsFactory();

    List* list = winFactory->createList();
    InputField* inputField = winFactory->createInputField();
    Button* button = winFactory->createButton();
    Language* language = winFactory->createLanguage();

    list->render();
    inputField->render();
    button->render();
    language->display();

    delete winFactory;
    delete list;
    delete inputField;
    delete button;
    delete language;
}