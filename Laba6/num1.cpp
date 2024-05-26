#include <iostream>
#include <list>
#include <string>

// Класс для представления квартиры
class Apartment {
private:
    int rooms;
    double area;
    int floor;
    std::string district;

public:
    // Конструктор
    Apartment(int r, double a, int f, const std::string& d) : rooms(r), area(a), floor(f), district(d) {}

    // Метод для получения информации о квартире
    void print() const {
        std::cout << "Квартира: " << rooms << " комнат, " << area << " кв. м, этаж " << floor << ", район " << district << std::endl;
    }

    // Геттеры
    int getRooms() const { return rooms; }
    double getArea() const { return area; }
    int getFloor() const { return floor; }
    const std::string& getDistrict() const { return district; }
};

// Класс для заявки на обмен
class ExchangeRequest {
private:
    Apartment required;
    Apartment offered;

public:
    // Конструктор
    ExchangeRequest(const Apartment& req, const Apartment& off) : required(req), offered(off) {}

    // Метод для проверки соответствия квартир требованиям
    bool matchApartments() const {
        // Проверяем совпадение по количеству комнат и этажности
        if (required.getRooms() == offered.getRooms() && required.getFloor() == offered.getFloor()) {
            // Проверяем разницу в площади не более 10%
            double difference = std::abs(required.getArea() - offered.getArea());
            double percentDifference = (difference / required.getArea()) * 100;
            if (percentDifference <= 10) {
                return true;
            }
        }
        return false;
    }

    // Метод для вывода информации о заявке
    void print() const {
        std::cout << "Требуемая ";
        required.print();
        std::cout << "Имеющаяся ";
        offered.print();
    }
};

// Класс для учета заявок на обмен
class ExchangeRegistry {
private:
    std::list<ExchangeRequest> exchangeRequests;

public:
    // Метод для добавления заявки на обмен
    void addRequest(const Apartment& req, const Apartment& off) {
        ExchangeRequest request(req, off);
        exchangeRequests.push_back(request);
    }

    // Метод для поиска варианта обмена
    void findMatch() {
        bool found = false;
        for (auto it = exchangeRequests.begin(); it != exchangeRequests.end(); ++it) {
            if (it->matchApartments()) {
                std::cout << "Найден вариант обмена:" << std::endl;
                it->print();
                it = exchangeRequests.erase(it); // Удаляем найденную заявку из списка
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Подходящий вариант обмена не найден." << std::endl;
        }
    }

    // Метод для вывода всей картотеки
    void printRegistry() const {
        std::cout << "Картотека заявок на обмен:" << std::endl;
        for (const auto& request : exchangeRequests) {
            request.print();
        }
    }
};

int main() {
    ExchangeRegistry registry;

    int choice;
    do {
        std::cout << "1. Ввод заявки на обмен" << std::endl;
        std::cout << "2. Поиск варианта обмена" << std::endl;
        std::cout << "3. Вывод всей картотеки" << std::endl;
        std::cout << "4. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int reqRooms, offRooms, reqFloor, offFloor;
                double reqArea, offArea;
                std::string reqDistrict, offDistrict;

                std::cout << "Введите требуемые характеристики квартиры:" << std::endl;
                std::cout << "Количество комнат: ";
                std::cin >> reqRooms;
                std::cout << "Площадь: ";
                std::cin >> reqArea;
                std::cout << "Этаж: ";
                std::cin >> reqFloor;
                std::cout << "Район: ";
                std::cin >> reqDistrict;

                std::cout << "Введите имеющиеся характеристики квартиры:" << std::endl;
                std::cout << "Количество комнат: ";
                std::cin >> offRooms;
                std::cout << "Площадь: ";
                std::cin >> offArea;
                std::cout << "Этаж: ";
                std::cin >> offFloor;
                std::cout << "Район: ";
                std::cin >> offDistrict;

                Apartment required(reqRooms, reqArea, reqFloor, reqDistrict);
                Apartment offered(offRooms, offArea, offFloor, offDistrict);
                registry.addRequest(required, offered);
                break;
            }
            case 2:
                registry.findMatch();
                break;
            case 3:
                registry.printRegistry();
                break;
            case 4:
                std::cout << "До свидания!" << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте еще раз." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
