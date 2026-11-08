#pragma once // Директива предотвращения повторного включения
#include "Base.h" // Подключаем базовый класс
#include <fstream> // Подключаем файловый ввод-вывод

class Keeper { // Класс контейнер
private:
    Base** items; // Динамический массив указателей на базовый класс
    int size; // Текущее количество элементов
    int capacity; // Текущая вместимость массива
    void resize(); // Метод изменения размера массива
public:
    Keeper(); // Конструктор по умолчанию
    Keeper(const Keeper& other); // Конструктор копирования
    ~Keeper(); // Деструктор
    void add(Base* item); // Добавление элемента
    void remove(int index); // Удаление элемента по индексу
    void displayAll() const; // Вывод всех элементов
    void editItem(int index); // Редактирование элемента
    void saveToFile(const std::string& filename) const; // Сохранение в файл
    void loadFromFile(const std::string& filename); // Загрузка из файла
    int getSize() const; // Геттер размера
    Keeper& operator=(const Keeper& other); // Оператор присваивания
};
