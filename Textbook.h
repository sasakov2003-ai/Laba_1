#pragma once // Директива предотвращения повторного включения
#include "Base.h" // Подключаем базовый класс
#include <string> // Подключаем строки

class Textbook : public Base { // Класс Учебник, наследник Base
private:
    std::string title, author, institution; // Строковые поля
    int year, studyYear, pages; // Числовые поля
public:
    Textbook(); // Конструктор по умолчанию
    Textbook(double p, const std::string& t, const std::string& a, int y, const std::string& inst, int sy, int pg); // Конструктор с параметрами
    Textbook(const Textbook& other); // Конструктор копирования
    ~Textbook(); // Деструктор
    void display() const override; // Переопределение вывода
    void readFromConsole() override; // Переопределение ввода
    void writeToFile(std::ofstream& out) const override; // Переопределение записи в файл
    void readFromFile(std::ifstream& in) override; // Переопределение чтения из файла
    Base* clone() const override; // Переопределение виртуального конструктора
    void edit() override; // Переопределение редактирования
};
