#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Структура для хранения информации о клиентах кабельной сети
struct CableClient {
    std::string fullName;
    double paymentAmount;
    int paidMonths;
    int prepaidMonths;
};

// Функция для записи информации о клиентах в бинарный файл
void writeClientsToBinaryFile(const std::vector<CableClient>& clients, const std::string& filename) {
    std::ofstream outputFile(filename, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Error creating file." << std::endl;
        return;
    }

    for (const auto& client : clients) {
        outputFile.write(reinterpret_cast<const char*>(&client), sizeof(client));
    }

    outputFile.close();
}

// Функция для переписывания бинарного файла с учетом скидки на услуги
void applyDiscountForPrepaidClients(const std::string& filename) {
    std::ifstream inputFile(filename, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::vector<CableClient> clients;

    CableClient client;
    while (inputFile.read(reinterpret_cast<char*>(&client), sizeof(client))) {
        if (client.prepaidMonths > 3) {
            // Применяем скидку на стоимость услуг для клиентов, оплативших вперед более чем за 3 месяца
            client.paymentAmount *= 0.95;
        }
        clients.push_back(client);
    }

    inputFile.close();

    // Перезаписываем файл с обновленными данными о клиентах
    writeClientsToBinaryFile(clients, filename);
}

int main() {
    // Создаем вектор с информацией о клиентах
    std::vector<CableClient> clients = {
        {"Иванов И.И.", 100.0, 6, 4},
        {"Петров П.П.", 150.0, 12, 2},
        {"Сидоров С.С.", 120.0, 9, 5}
    };

    // Записываем информацию о клиентах в бинарный файл
    writeClientsToBinaryFile(clients, "clients.bin");

    // Применяем скидку для клиентов, оплативших вперед более чем за 3 месяца
    applyDiscountForPrepaidClients("clients.bin");

    std::cout << "Скидка применена " << std::endl;

    return 0;
}
