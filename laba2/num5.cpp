#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Структура для хранения данных о работнике
struct Worker {
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string address;
    std::string nationality;
    std::string birthDate;
    int workshopNumber;
    int employeeNumber;
    std::string education;
    int hireYear;
};

// Функция для чтения данных из файла и возврата списка работников
std::vector<Worker> readWorkers(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::vector<Worker> workers;

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return workers;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        Worker worker;
        std::string item;

        std::getline(ss, worker.surname, ';');
        std::getline(ss, worker.name, ';');
        std::getline(ss, worker.patronymic, ';');
        std::getline(ss, worker.address, ';');
        std::getline(ss, worker.nationality, ';');
        std::getline(ss, worker.birthDate, ';');
        std::getline(ss, item, ';');
        worker.workshopNumber = std::stoi(item);
        std::getline(ss, item, ';');
        worker.employeeNumber = std::stoi(item);
        std::getline(ss, worker.education, ';');
        std::getline(ss, item, ';');
        worker.hireYear = std::stoi(item);

        workers.push_back(worker);
    }

    inputFile.close();
    return workers;
}

// Функция для сохранения обработанных данных в новый файл
void saveWorkers(const std::vector<Worker>& workers, const std::string& filename) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return;
    }

    for (const auto& worker : workers) {
        outputFile << worker.surname << ";" << worker.name << ";" << worker.patronymic << ";" << worker.address << ";" << worker.nationality << ";" << worker.birthDate << ";" << worker.workshopNumber << ";" << worker.employeeNumber << ";" << worker.education << ";" << worker.hireYear << "\n";
    }

    outputFile.close();
}

int main() {
    // Шаг 1: Чтение данных из файла
    std::vector<Worker> workers = readWorkers("workers.txt");

    // Шаг 2: Фильтрация работников, поступивших на работу в 2010 году
    std::vector<Worker> workers2010;
    for (const auto& worker : workers) {
        if (worker.hireYear == 2010) {
            workers2010.push_back(worker);
        }
    }

    // Шаг 3: Сохранение отфильтрованных данных в новый файл
    saveWorkers(workers2010, "workers_2010.txt");

    return 0;
}
