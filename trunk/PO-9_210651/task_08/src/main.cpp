#include <QCoreApplication>
#include "AbstractFactory.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout<< "Abstract factory"<<std::endl;
        AbstractFactory* Factory = new SomeAppFactory();

        List* list = Factory->createList();
        InputField* inputField = Factory->createInputField();
        Button* button = Factory->createButton();
        Language* language = Factory->createLanguage();

        list->render();
        inputField->render();
        button->render();
        language->display();

        delete list;
        delete inputField;
        delete button;
        delete language;
        delete Factory;

    return a.exec();
}
