#pragma once // Директива предотвращения повторного включения
#include <string> // Подключаем строки
#include <iostream> // Подключаем ввод-вывод

class Base { // Объявление абстрактного базового класса
protected:
    double price; //protected поле для стоимости (общее для всех)
public:
    Base(); // Конструктор по умолчанию
    Base(double p); // Конструктор с параметрами
    Base(const Base& other); // Конструктор копирования
    virtual ~Base(); // Виртуальный деструктор
    virtual void display() const = 0; // Чисто виртуальный метод вывода
    virtual void readFromConsole() = 0; // Чисто виртуальный метод ввода
    virtual void writeToFile(std::ofstream& out) const = 0; // Запись в файл
    virtual void readFromFile(std::ifstream& in) = 0; // Чтение из файла
    virtual Base* clone() const = 0; // Виртуальный конструктор копирования
    virtual void edit() = 0; // Метод редактирования
    double getPrice() const; // Геттер цены
    void setPrice(double p); // Сеттер цены
    Base& operator=(const Base& other); // Оператор присваивания
};
