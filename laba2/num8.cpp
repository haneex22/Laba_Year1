#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Структура для хранения информации о компьютере
struct Computer {
    std::string name;
    double cpuFrequency;
    int ram;
    int hdd;
    double price;
};

// Функция для записи информации о компьютерах в бинарный файл
void writeComputersToBinaryFile(const std::vector<Computer>& computers, const std::string& filename) {
    std::ofstream outputFile(filename, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Error creating file." << std::endl;
        return;
    }

    for (const auto& computer : computers) {
        outputFile.write(reinterpret_cast<const char*>(&computer), sizeof(computer));
    }

    outputFile.close();
}

// Функция для подсчета общей стоимости компьютеров
double calculateTotalPrice(const std::vector<Computer>& computers) {
    double totalPrice = 0.0;
    for (const auto& computer : computers) {
        totalPrice += computer.price;
    }
    return totalPrice;
}

// Функция для печати информации о компьютерах фирмы "Asus" с частотой процессора более 2 ГГц
void printAsusComputersWithHighCpuFrequency(const std::vector<Computer>& computers) {
    std::cout << "Компьютеры Asus c частотой процессора более 2 ГГц:" << std::endl;
    for (const auto& computer : computers) {
        if (computer.name == "Asus" && computer.cpuFrequency > 2.0) {
            std::cout << "Name: " << computer.name << ", CPU Frequency: " << computer.cpuFrequency
                      << " GHz, RAM: " << computer.ram << " GB, HDD: " << computer.hdd << " GB, Price: $" << computer.price << std::endl;
        }
    }
}

int main() {
    // Создание вектора с информацией о компьютерах
    std::vector<Computer> computers = {
        {"Asus", 2.4, 8, 512, 1200.0},
        {"Dell", 3.0, 16, 1024, 1800.0},
        {"Lenovo", 2.2, 4, 256, 900.0},
        {"Asus", 2.8, 16, 512, 1500.0},
        {"HP", 2.5, 8, 512, 1100.0}
    };

    // Запись информации о компьютерах в бинарный файл
    writeComputersToBinaryFile(computers, "computers.bin");

    // Подсчет общей стоимости компьютеров
    double totalPrice = calculateTotalPrice(computers);
    std::cout << "Цена за все компьютеры: $" << totalPrice << std::endl;

    // Печать информации о компьютерах фирмы "Asus" с частотой процессора более 2 ГГц
    printAsusComputersWithHighCpuFrequency(computers);

    return 0;
}
