#pragma once // Директива предотвращения повторного включения
#include "Base.h" // Подключаем базовый класс
#include <string> // Подключаем строки

class Stationery : public Base { // Класс Канцелярия, наследник Base
private:
    std::string type, color, purpose; // Строковые поля
public:
    Stationery(); // Конструктор по умолчанию
    Stationery(double p, const std::string& t, const std::string& c, const std::string& pur); // Конструктор с параметрами
    Stationery(const Stationery& other); // Конструктор копирования
    ~Stationery(); // Деструктор
    void display() const override; // Переопределение вывода
    void readFromConsole() override; // Переопределение ввода
    void writeToFile(std::ofstream& out) const override; // Переопределение записи в файл
    void readFromFile(std::ifstream& in) override; // Переопределение чтения из файла
    Base* clone() const override; // Переопределение виртуального конструктора
    void edit() override; // Переопределение редактирования
};
