#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

class Rectangle {
protected:
    double x1, y1, x2, y2;

public:
    // Конструктор по умолчанию
    Rectangle() : x1(0), y1(0), x2(0), y2(0) {
        std::cout << "Rectangle создан по умолчанию." << std::endl;
    }

    // Конструктор с параметрами
    Rectangle(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
        std::cout << "Rectangle создан с параметрами." << std::endl;
    }

    // Деструктор
    ~Rectangle() {
        std::cout << "Rectangle уничтожен." << std::endl;
    }

    // Функция вычисления длины диагонали
    double calculateDiagonal() const {
        return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

    // Функция формирования строки с информацией об объекте
    std::string toString() const {
        std::cout << "Прямоугольник с координатами: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")";
        
    }

};

int main() {
    // Создание объекта с константными значениями
    Rectangle rect1(0, 0, 3, 4);
    std::cout << rect1.toString() << std::endl;
    std::cout << "Длина диагонали: " << rect1.calculateDiagonal() << std::endl;

    // Ввод значений координат
    double x1, y1, x2, y2;
    std::cout << "Введите x1: ";
    std::cin >> x1;
    std::cout << "Введите y1: ";
    std::cin >> y1;
    std::cout << "Введите x2: ";
    std::cin >> x2;
    std::cout << "Введите y2: ";
    std::cin >> y2;

    // Создание объекта с введенными значениями
    Rectangle rect2(x1, y1, x2, y2);
    std::cout << rect2.toString() << std::endl;
    std::cout << "Длина диагонали: " << rect2.calculateDiagonal() << std::endl;

    return 0;
}
