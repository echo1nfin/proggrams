#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

// Функция для чтения данных из файла
void readDataFromFile(const std::string& filename, std::vector<int>& data, int blockSize) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        exit(1);
    }

    int value;
    while (file >> value) {
        data.push_back(value);
        if (data.size() == blockSize) {
            std::sort(data.begin(), data.end());
            // Здесь можно было бы записать данные обратно в файл, но для простоты примера просто выводим их на экран
            for (int num : data) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            data.clear();
        }
    }

    if (!data.empty()) {
        std::sort(data.begin(), data.end());
        for (int num : data) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        data.clear();
    }

    file.close();
}

int main() {
    std::vector<int> data;
    const std::string filename = "data.txt"; // Путь к файлу с данными
    const int blockSize = 15; // Размер блока данных для сортировки

    readDataFromFile(filename, data, blockSize);

    return 0;
}
