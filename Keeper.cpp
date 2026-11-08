#include "Keeper.h" // Подключаем заголовок
#include "Book.h" // Подключаем класс Книга
#include "Textbook.h" // Подключаем класс Учебник
#include "Stationery.h" // Подключаем класс Канцелярия
#include "Exceptions.h" // Подключаем исключения
#include <iostream> // Подключаем ввод-вывод

Keeper::Keeper() : size(0), capacity(2) { // Конструктор по умолчанию
    std::cout << "Вызван конструктор по умолчанию Keeper\n"; // Вывод сообщения
    items = new Base * [capacity]; // Выделение динамической памяти
}

Keeper::Keeper(const Keeper& other) : size(other.size), capacity(other.capacity) { // Конструктор копирования
    std::cout << "Вызван конструктор копирования Keeper\n"; // Вывод сообщения
    items = new Base * [capacity]; // Выделение памяти
    for (int i = 0; i < size; ++i) items[i] = other.items[i]->clone(); // Глубокое копирование
}

Keeper::~Keeper() { // Деструктор
    std::cout << "Вызван деструктор Keeper\n"; // Вывод сообщения
    for (int i = 0; i < size; ++i) delete items[i]; // Удаление объектов
    delete[] items; // Освобождение массива
}

void Keeper::resize() { // Метод изменения размера
    capacity *= 2; // Увеличиваем вместимость в 2 раза
    Base** newItems = new Base * [capacity]; // Создаем новый массив
    for (int i = 0; i < size; ++i) newItems[i] = items[i]; // Копируем указатели
    delete[] items; // Удаляем старый массив
    items = newItems; // Присваиваем новый массив
}

void Keeper::add(Base* item) { // Добавление элемента
    if (!item) throw MemoryException("Попытка добавить нулевой указатель"); // Проверка на null
    if (size == capacity) resize(); // Если место кончилось, расширяем массив
    items[size++] = item; // Добавляем элемент и увеличиваем size
}

void Keeper::remove(int index) { // Удаление элемента
    if (index < 0 || index >= size) throw IndexException("Индекс вне диапазона"); // Проверка границ
    delete items[index]; // Удаляем объект из памяти
    for (int i = index; i < size - 1; ++i) items[i] = items[i + 1]; // Сдвигаем элементы
    size--; // Уменьшаем размер
}

void Keeper::displayAll() const { // Вывод всех элементов
    if (size == 0) { std::cout << "Список пуст.\n"; return; } // Проверка на пустоту
    for (int i = 0; i < size; ++i) { std::cout << "[" << i << "] "; items[i]->display(); } // Вывод каждого элемента
}

void Keeper::editItem(int index) { // Редактирование элемента
    if (index < 0 || index >= size) throw IndexException("Индекс вне диапазона"); // Проверка границ
    items[index]->edit(); // Вызов метода редактирования у объекта
}

void Keeper::saveToFile(const std::string& filename) const { // Сохранение в файл
    std::ofstream out(filename); // Открываем файл для записи
    if (!out) throw FileException("Не удалось открыть файл для записи"); // Проверка открытия
    out << size << "\n"; // Записываем количество элементов
    for (int i = 0; i < size; ++i) items[i]->writeToFile(out); // Записываем каждый объект
    out.close(); // Закрываем файл
}

void Keeper::loadFromFile(const std::string& filename) { // Загрузка из файла
    std::ifstream in(filename); // Открываем файл для чтения
    if (!in) throw FileException("Не удалось открыть файл для чтения"); // Проверка открытия
    int count; in >> count; in.ignore(); // Читаем количество элементов
    for (int i = 0; i < size; ++i) delete items[i]; // Удаляем старые объекты
    size = 0; // Обнуляем размер
    for (int i = 0; i < count; ++i) { // Цикл чтения объектов
        char type; in >> type; in.ignore(); // Читаем маркер типа
        Base* newItem = nullptr; // Указатель на новый объект
        if (type == 'B') newItem = new Book(); // Создаем Книгу
        else if (type == 'T') newItem = new Textbook(); // Создаем Учебник
        else if (type == 'S') newItem = new Stationery(); // Создаем Канцелярию
        else throw FileException("Неизвестный тип объекта в файле"); // Исключение
        newItem->readFromFile(in); // Читаем данные объекта
        add(newItem); // Добавляем в контейнер
    }
    in.close(); // Закрываем файл
}

int Keeper::getSize() const { return size; } // Геттер размера

Keeper& Keeper::operator=(const Keeper& other) { // Оператор присваивания
    if (this != &other) { // Проверка на самоприсваивание
        for (int i = 0; i < size; ++i) delete items[i]; // Удаляем старые объекты
        delete[] items; // Удаляем старый массив
        size = other.size; capacity = other.capacity; // Копируем размеры
        items = new Base * [capacity]; // Выделяем новую память
        for (int i = 0; i < size; ++i) items[i] = other.items[i]->clone(); // Глубокое копирование
    }
    return *this; // Возвращаем ссылку на себя
}
