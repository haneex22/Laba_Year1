#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
// Функция для создания матрицы размером n x n с произвольными значениями
std::vector<std::vector<int>> createMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    int value = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = value++;
        }
    }
    return matrix;
}

// Функция для записи матриц в файл
void writeMatricesToFile(const std::vector<std::vector<std::vector<int>>>& matrices, const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error creating file." << std::endl;
        return;
    }

    for (const auto& matrix : matrices) {
        for (const auto& row : matrix) {
            for (int value : row) {
                outputFile << value << " ";
            }
            outputFile << std::endl;
        }
        outputFile << std::endl;
    }

    outputFile.close();
}

// Функция для чтения матриц из файла
std::vector<std::vector<std::vector<int>>> readMatricesFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::vector<std::vector<std::vector<int>>> matrices;
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return matrices;
    }

    std::vector<std::vector<int>> currentMatrix;
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            if (!currentMatrix.empty()) {
                matrices.push_back(currentMatrix);
                currentMatrix.clear();
            }
        } else {
            std::vector<int> row;
            std::istringstream iss(line);
            int value;
            while (iss >> value) {
                row.push_back(value);
            }
            currentMatrix.push_back(row);
        }
    }
    if (!currentMatrix.empty()) {
        matrices.push_back(currentMatrix);
    }

    inputFile.close();
    return matrices;
}

// Функция для добавления единичной матрицы в конец вектора матриц
void addIdentityMatrix(std::vector<std::vector<std::vector<int>>>& matrices, int n) {
    std::vector<std::vector<int>> identityMatrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        identityMatrix[i][i] = 1;
    }
    matrices.push_back(identityMatrix);
}

int main() {
    // Создание двух наборов матриц
    int n1 = 3; // Порядок матриц для первого файла
    int k1 = 2; // Количество матриц для первого файла
    int n2 = 2; // Порядок матриц для второго файла
    int k2 = 4; // Количество матриц для второго файла

    std::vector<std::vector<std::vector<int>>> matrices1;
    std::vector<std::vector<std::vector<int>>> matrices2;

    for (int i = 0; i < k1; ++i) {
        matrices1.push_back(createMatrix(n1));
    }
    for (int i = 0; i < k2; ++i) {
        matrices2.push_back(createMatrix(n2));
    }

    // Если k1 ≠ 1, добавляем недостающие единичные матрицы во второй файл
    if (k1 != 1) {
        for (int i = 0; i < k1 - k2; ++i) {
            addIdentityMatrix(matrices2, n2);
        }
    }
    // Если k2 ≠ 1, добавляем недостающие единичные матрицы в первый файл
    if (k2 != 1) {
        for (int i = 0; i < k2 - k1; ++i) {
            addIdentityMatrix(matrices1, n1);
        }
    }

    // Записываем матрицы в файлы
    writeMatricesToFile(matrices1, "file1.txt");
    writeMatricesToFile(matrices2, "file2.txt");

    // Выводим содержимое файлов на экран
    std::cout << "Contents of file1.txt:" << std::endl;
    std::vector<std::vector<std::vector<int>>> readMatrices1 = readMatricesFromFile("file1.txt");
    for (const auto& matrix : readMatrices1) {
        for (const auto& row : matrix) {
            for (int value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "\nContents of file2.txt:" << std::endl;
    std::vector<std::vector<std::vector<int>>> readMatrices2 = readMatricesFromFile("file2.txt");
    for (const auto& matrix : readMatrices2) {
        for (const auto& row : matrix) {
            for (int value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
