#include <iostream>
#include <string>

class RightTriangle {
private:
    double katet1; // Поле 1 - первый катет
    double katet2; // Поле 2 - второй катет

public:
    // Конструктор для инициализации объекта
    RightTriangle(double k1, double k2) : katet1(k1), katet2(k2) {}

    // Метод для формирования строки с информацией об объекте
    std::string toString() const {
        std::cout << "Прямоугольный треугольник с катетами " << katet1 << " и " << katet2;
        
    }

    // Метод для вычисления площади прямоугольного треугольника
    double calculateArea() const {
        return 0.5 * katet1 * katet2;
    }
};

int main() {
    // Ввод значений катетов
    double katet1, katet2;
    std::cout << "Введите первый катет: ";
    std::cin >> katet1;
    std::cout << "Введите второй катет: ";
    std::cin >> katet2;

    // Создание объекта класса RightTriangle
    RightTriangle triangle(katet1, katet2);

    // Вывод информации об объекте
    std::cout << triangle.toString() << std::endl;

    // Вычисление и вывод площади треугольного треугольника
    double area = triangle.calculateArea();
    std::cout << "Площадь прямоугольного треугольника: " << area << std::endl;

    return 0;
}
