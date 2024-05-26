#include <iostream>
#include <memory> // Для использования умных указателей
#include <stdexcept> // Для обработки исключений

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
        } else {
            // Если элемент уже существует, выбрасываем исключение
            throw std::invalid_argument("Элемент уже существует в дереве");
        }
    }

    // Поиск элемента в дереве
    bool search(const T& value) const {
        return search(value, root);
    }

    // Вспомогательная функция для поиска элемента
    bool search(const T& value, const std::unique_ptr<Node>& node) const {
        if (!node) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return search(value, node->left);
        } else {
            return search(value, node->right);
        }
    }

    // Удаление элемента из дерева
    void remove(const T& value) {
        remove(value, root);
    }

    // Вспомогательная функция для удаления элемента
    void remove(const T& value, std::unique_ptr<Node>& node) {
        if (!node) {
            throw std::invalid_argument("Элемент не найден в дереве");
        }

        if (value == node->data) {
            if (!node->left && !node->right) {
                node.reset(); // Если у узла нет детей, просто удаляем его
            } else if (!node->left) {
                node = std::move(node->right); // Если у узла нет левого ребенка, заменяем его правым
            } else if (!node->right) {
                node = std::move(node->left); // Если у узла нет правого ребенка, заменяем его левым
            } else {
                // Если у узла есть оба ребенка, находим наименьший элемент в правом поддереве
                // и заменяем данный узел этим элементом
                T min_value = findMin(node->right);
                node->data = min_value;
                remove(min_value, node->right);
            }
        } else if (value < node->data) {
            remove(value, node->left);
        } else {
            remove(value, node->right);
        }
    }

    // Находим минимальный элемент в дереве
    T findMin(const std::unique_ptr<Node>& node) const {
        if (!node->left) {
            return node->data;
        }
        return findMin(node->left);
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

// Функция для тестирования
void testBinaryTree() {
    BinaryTree<int> tree;

    // Вставляем элементы
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Печатаем дерево
    std::cout << "Двоичное дерево:" << std::endl;
    tree.print();

    // Проверяем наличие элементов
    std::cout << "Поиск 30: " << (tree.search(30) ? "Найден" : "Не найден") << std::endl;
    std::cout << "Поиск 45: " << (tree.search(45) ? "Найден" : "Не найден") << std::endl;

    // Удаляем элементы
    tree.remove(20);
    tree.remove(70);

    // Печатаем измененное дерево
    std::cout << "Двоичное дерево после удаления:" << std::endl;
    tree.print();
}

int main() {
    try {
        testBinaryTree();
    } catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
