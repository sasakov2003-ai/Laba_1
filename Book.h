#pragma once // Директива предотвращения повторного включения
#include "Base.h" // Подключаем базовый класс
#include <string> // Подключаем строки
class Book : public Base { // Класс Книга, наследник Base
private:
    std::string title, author, annotation, genre; // Строковые поля
    int year, pages; // Числовые поля
public:
    Book(); // Конструктор по умолчанию
    Book(double p, const std::string& t, const std::string& a, int y, const std::string& ann, const std::string& g, int pg); // Конструктор с параметрами
    Book(const Book& other); // Конструктор копирования
    ~Book(); // Деструктор
    void display() const override; // Переопределение вывода
    void readFromConsole() override; // Переопределение ввода
    void writeToFile(std::ofstream& out) const override; // Переопределение записи в файл
    void readFromFile(std::ifstream& in) override; // Переопределение чтения из файла
    Base* clone() const override; // Переопределение виртуального конструктора
    void edit() override; // Переопределение редактирования
    // Геттеры и сеттеры (для краткости оставлены только для специфичных полей, остальные в Base)
    std::string getTitle() const; // Геттер названия
    void setTitle(const std::string& t); // Сеттер названия
};
