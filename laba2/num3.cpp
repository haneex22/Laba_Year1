#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "ошибка открытия файла" << std::endl;
        return 1;
    }

    char ch;

    while (inputFile.get(ch)) {
        if (!std::isdigit(ch)) {
            outputFile << ch;
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Числа удалены, файл перезаписан в output.txt" << std::endl;

    return 0;
}
