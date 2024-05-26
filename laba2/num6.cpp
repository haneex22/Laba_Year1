#include <iostream>
#include <fstream>
#include <vector>

// Функция для чтения данных из файла и возврата списка чисел
std::vector<int> readNumbers(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::vector<int> numbers;

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return numbers;
    }

    int number;
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    inputFile.close();
    return numbers;
}

// Функция для записи четных чисел в файл
void writeEvenNumbers(const std::vector<int>& numbers, const std::string& filename) {
    std::ofstream outputFile(filename);

    for (int num : numbers) {
        if (num % 2 == 0) {
            outputFile << num << std::endl;
        }
    }

    outputFile.close();
}

int main() {
    // Шаг 1: Чтение данных из файла
    std::vector<int> numbers = readNumbers("f.txt");

    // Шаг 2: Запись четных чисел в новый файл
    writeEvenNumbers(numbers, "even_numbers.txt");

    std::cout << "Четные числа записаны в even_numbers.txt." << std::endl;

    return 0;
}
