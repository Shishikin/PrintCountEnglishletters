#include <fstream>
#include <iostream>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    std::ifstream is(__FILE__);
    char ch = '0';
    std::cout << std::setw(8) << "Символ" << std::setw(25) << "Количество вхождений" << '\n';
    for (int c = 'a'; c <= 'z'; c++) {
        int count = 0;
        is.clear(); // Сбрасываем флаги ошибок и конца файла
        is.seekg(0, std::ios::beg); // Перемещаем указатель чтения в начало файла
        while (is.get(ch)) {
            if ((int)ch == c) {
                count++;
            }
        }
        std::cout << std::setw(6) << (char)c << std::setw(20) << count << '\n';
    }

    is.close();
    return 0;
}