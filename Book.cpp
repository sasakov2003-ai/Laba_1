#include "Book.h" // Подключаем заголовок
#include "Exceptions.h" // Подключаем исключения
#include <iostream> // Подключаем ввод-вывод
#include <fstream> // Подключаем файловый ввод-вывод

Book::Book() : Base(), title(""), author(""), annotation(""), genre(""), year(0), pages(0) { std::cout << "Вызван конструктор по умолчанию Book\n"; } // Конструктор по умолчанию
Book::Book(double p, const std::string& t, const std::string& a, int y, const std::string& ann, const std::string& g, int pg) : Base(p), title(t), author(a), year(y), annotation(ann), genre(g), pages(pg) { std::cout << "Вызван конструктор с параметрами Book\n"; } // Конструктор с параметрами
Book::Book(const Book& other) : Base(other), title(other.title), author(other.author), year(other.year), annotation(other.annotation), genre(other.genre), pages(other.pages) { std::cout << "Вызван конструктор копирования Book\n"; } // Конструктор копирования
Book::~Book() { std::cout << "Вызван деструктор Book\n"; } // Деструктор

void Book::display() const { // Метод вывода на экран
    std::cout << "--- Книга ---\n"; // Вывод заголовка
    std::cout << "Название: " << title << "\n"; // Вывод названия
    std::cout << "Автор: " << author << "\n"; // Вывод автора
    std::cout << "Год: " << year << "\n"; // Вывод года
    std::cout << "Аннотация: " << annotation << "\n"; // Вывод аннотации
    std::cout << "Жанр: " << genre << "\n"; // Вывод жанра
    std::cout << "Страниц: " << pages << "\n"; // Вывод страниц
    std::cout << "Стоимость: " << getPrice() << "\n"; // Вывод стоимости
}

void Book::readFromConsole() { // Метод ввода с клавиатуры
    std::cin.ignore(); // Игнорируем символ переноса строки
    std::cout << "Название: "; std::getline(std::cin, title); // Ввод названия
    std::cout << "Автор: "; std::getline(std::cin, author); // Ввод автора
    std::cout << "Год: "; std::cin >> year; // Ввод года
    std::cin.ignore(); // Игнорируем перенос строки
    std::cout << "Аннотация: "; std::getline(std::cin, annotation); // Ввод аннотации
    std::cout << "Жанр: "; std::getline(std::cin, genre); // Ввод жанра
    std::cout << "Страниц: "; std::cin >> pages; // Ввод страниц
    std::cout << "Стоимость: "; std::cin >> price; // Ввод стоимости
}

void Book::writeToFile(std::ofstream& out) const { // Запись в файл
    out << "B\n"; // Маркер типа объекта
    out << title << "\n" << author << "\n" << year << "\n"; // Запись полей
    out << annotation << "\n" << genre << "\n" << pages << "\n" << getPrice() << "\n"; // Запись оставшихся полей
}

void Book::readFromFile(std::ifstream& in) { // Чтение из файла
    std::getline(in, title); std::getline(in, author); in >> year; // Чтение полей
    in.ignore(); std::getline(in, annotation); std::getline(in, genre); in >> pages; in >> price; // Чтение оставшихся полей
}

Base* Book::clone() const { return new Book(*this); } // Виртуальный конструктор копирования

void Book::edit() { // Метод редактирования
    std::cout << "Редактирование книги. Оставьте поле пустым, чтобы не менять.\n"; // Подсказка
    std::string temp; int tempInt; double tempDouble; // Временные переменные
    std::cin.ignore(); // Игнорируем перенос
    std::cout << "Название (" << title << "): "; std::getline(std::cin, temp); if (!temp.empty()) title = temp; // Редактирование названия
    std::cout << "Автор (" << author << "): "; std::getline(std::cin, temp); if (!temp.empty()) author = temp; // Редактирование автора
    std::cout << "Год (" << year << "): "; std::getline(std::cin, temp); if (!temp.empty()) { year = std::stoi(temp); } // Редактирование года
    std::cout << "Аннотация (" << annotation << "): "; std::getline(std::cin, temp); if (!temp.empty()) annotation = temp; // Редактирование аннотации
    std::cout << "Жанр (" << genre << "): "; std::getline(std::cin, temp); if (!temp.empty()) genre = temp; // Редактирование жанра
    std::cout << "Страниц (" << pages << "): "; std::getline(std::cin, temp); if (!temp.empty()) { pages = std::stoi(temp); } // Редактирование страниц
    std::cout << "Стоимость (" << getPrice() << "): "; std::getline(std::cin, temp); if (!temp.empty()) { setPrice(std::stod(temp)); } // Редактирование стоимости
}

std::string Book::getTitle() const { return title; } // Геттер названия
void Book::setTitle(const std::string& t) { title = t; } // Сеттер названия
