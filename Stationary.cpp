#include "Stationery.h" // Подключаем заголовок
#include "Exceptions.h" // Подключаем исключения
#include <iostream> // Подключаем ввод-вывод
#include <fstream> // Подключаем файловый ввод-вывод

Stationery::Stationery() : Base(), type(""), color(""), purpose("") { std::cout << "Вызван конструктор по умолчанию Stationery\n"; } // Конструктор по умолчанию
Stationery::Stationery(double p, const std::string& t, const std::string& c, const std::string& pur) : Base(p), type(t), color(c), purpose(pur) { std::cout << "Вызван конструктор с параметрами Stationery\n"; } // Конструктор с параметрами
Stationery::Stationery(const Stationery& other) : Base(other), type(other.type), color(other.color), purpose(other.purpose) { std::cout << "Вызван конструктор копирования Stationery\n"; } // Конструктор копирования
Stationery::~Stationery() { std::cout << "Вызван деструктор Stationery\n"; } // Деструктор

void Stationery::display() const { // Метод вывода на экран
    std::cout << "--- Канцелярия ---\n"; // Вывод заголовка
    std::cout << "Тип: " << type << "\n"; // Вывод типа
    std::cout << "Цвет: " << color << "\n"; // Вывод цвета
    std::cout << "Назначение: " << purpose << "\n"; // Вывод назначения
    std::cout << "Стоимость: " << getPrice() << "\n"; // Вывод стоимости
}

void Stationery::readFromConsole() { // Метод ввода с клавиатуры
    std::cin.ignore(); // Игнорируем символ переноса строки
    std::cout << "Тип: "; std::getline(std::cin, type); // Ввод типа
    std::cout << "Цвет: "; std::getline(std::cin, color); // Ввод цвета
    std::cout << "Назначение: "; std::getline(std::cin, purpose); // Ввод назначения
    std::cout << "Стоимость: "; std::cin >> price; // Ввод стоимости
}

void Stationery::writeToFile(std::ofstream& out) const { // Запись в файл
    out << "S\n"; // Маркер типа объекта
    out << type << "\n" << color << "\n" << purpose << "\n" << getPrice() << "\n"; // Запись полей
}

void Stationery::readFromFile(std::ifstream& in) { // Чтение из файла
    std::getline(in, type); std::getline(in, color); std::getline(in, purpose); in >> price; // Чтение полей
}

Base* Stationery::clone() const { return new Stationery(*this); } // Виртуальный конструктор копирования

void Stationery::edit() { // Метод редактирования
    std::cout << "Редактирование канцелярии. Оставьте поле пустым, чтобы не менять.\n"; // Подсказка
    std::string temp; // Временная строка
    std::cin.ignore(); // Игнорируем перенос
    std::cout << "Тип (" << type << "): "; std::getline(std::cin, temp); if (!temp.empty()) type = temp; // Редактирование типа
    std::cout << "Цвет (" << color << "): "; std::getline(std::cin, temp); if (!temp.empty()) color = temp; // Редактирование цвета
    std::cout << "Назначение (" << purpose << "): "; std::getline(std::cin, temp); if (!temp.empty()) purpose = temp; // Редактирование назначения
    std::cout << "Стоимость (" << getPrice() << "): "; std::getline(std::cin, temp); if (!temp.empty()) setPrice(std::stod(temp)); // Редактирование стоимости
}
