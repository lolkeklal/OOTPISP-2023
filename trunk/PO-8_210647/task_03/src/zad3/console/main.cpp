#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <random>

int main() {
    std::list<int> myList;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    // Зaполнение списка случайными элементами
    for (int i = 0; i < 10; ++i) {
        myList.push_back(dis(gen));
    }

    // Вывод содержимого спискa до сортировки
    std::cout << "Список до сортировки:\n";
    for (auto const &item : myList) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Сортировкa списка по убыванию
    myList.sort(std::greater<int>());

    // Вывод содержимого списка после сортировки
    std::cout << "Список после сортировки:\n";
    for (auto const &item : myList) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}