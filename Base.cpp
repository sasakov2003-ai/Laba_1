#include "Base.h" // Подключаем заголовок базового класса
#include "Exceptions.h"
#include <fstream> // Подключаем файловый ввод-вывод

Base::Base() : price(0.0) { std::cout << "Вызван конструктор по умолчанию Base\n"; } // Реализация конструктора по умолчанию
Base::Base(double p) : price(p) { std::cout << "Вызван конструктор с параметром Base\n"; } // Реализация конструктора с параметром
Base::Base(const Base& other) : price(other.price) { std::cout << "Вызван конструктор копирования Base\n"; } // Реализация конструктора копирования
Base::~Base() { std::cout << "Вызван деструктор Base\n"; } // Реализация деструктора

double Base::getPrice() const { return price; } // Реализация геттера цены
void Base::setPrice(double p) { // Реализация сеттера цены
    if (p < 0) throw InputException("Цена не может быть отрицательной"); // Проверка на отрицательное значение
    price = p; // Присваиваем значение
}

Base& Base::operator=(const Base& other) { // Реализация оператора присваивания
    if (this != &other) { // Проверка на самоприсваивание
        price = other.price; // Копируем цену
    }
    return *this; // Возвращаем ссылку на себя
}
