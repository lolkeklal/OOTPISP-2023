#include <iostream>
#include <vector>

int main() {
    int N;
    std::cout << "Введите размер массива: ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "Размер массива должен быть положительным." << std::endl; //+
        return 1;
    }

    std::vector<int> arr(N);
    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < N; i++) {
        std::cout << "Элемент " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    if (N >= 3) {
        int firstElement = arr[0];
        for (int i = 1; i < N - 1; i++) {
            if (arr[i] % 2 == 0) {
                arr[i] += firstElement;
            }
        }
    }

    std::cout << "Преобразованный массив:\n";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
