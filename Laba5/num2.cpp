#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <memory>

template<typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;

public:
    // Конструктор
    BinaryTree() : root(nullptr) {}

    // Вставка элемента в дерево
    void insert(const T& value) {
        insert(value, root);
    }

    // Вспомогательная функция для вставки элемента
    void insert(const T& value, std::unique_ptr<Node>& node) {
        if (!node) {
            node = std::unique_ptr<Node>(new Node(value));
            return;
        }

        if (value < node->data) {
            insert(value, node->left);
        } else if (value > node->data) {
            insert(value, node->right);
        }
    }

    // Выводим дерево
    void print() const {
        print(root, 0);
    }

    // Вспомогательная функция для вывода дерева
    void print(const std::unique_ptr<Node>& node, int level) const {
        if (node) {
            print(node->right, level + 1);
            for (int i = 0; i < level; ++i) {
                std::cout << "   ";
            }
            std::cout << node->data << std::endl;
            print(node->left, level + 1);
        }
    }
};

// Функция для чтения данных из файла и заполнения бинарного дерева
template<typename T>
void readDataAndSort(BinaryTree<T>& tree, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл");
    }

    T value;
    while (file >> value) {
        tree.insert(value);
    }
}

int main() {
    try {
        BinaryTree<int> intTree;
        BinaryTree<std::string> stringTree;

        // Считываем целые числа из файла и сортируем их
        readDataAndSort(intTree, "numbers.txt");

        // Считываем строки из файла и сортируем их
        readDataAndSort(stringTree, "strings.txt");

        // Выводим отсортированные данные
        std::cout << "Сортировка целых чисел:" << std::endl;
        intTree.print();

        std::cout << "Сортировка строк:" << std::endl;
        stringTree.print();

    } catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
