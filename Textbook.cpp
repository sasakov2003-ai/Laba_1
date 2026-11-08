#include "Textbook.h" // Подключаем заголовок
#include "Exceptions.h" // Подключаем исключения
#include <iostream> // Подключаем ввод-вывод
#include <fstream> // Подключаем файловый ввод-вывод

Textbook::Textbook() : Base(), title(""), author(""), institution(""), year(0), studyYear(0), pages(0) { std::cout << "Вызван конструктор по умолчанию Textbook\n"; } // Конструктор по умолчанию
Textbook::Textbook(double p, const std::string& t, const std::string& a, int y, const std::string& inst, int sy, int pg) : Base(p), title(t), author(a), year(y), institution(inst), studyYear(sy), pages(pg) { std::cout << "Вызван конструктор с параметрами Textbook\n"; } // Конструктор с параметрами
Textbook::Textbook(const Textbook& other) : Base(other), title(other.title), author(other.author), year(other.year), institution(other.institution), studyYear(other.studyYear), pages(other.pages) { std::cout << "Вызван конструктор копирования Textbook\n"; } // Конструктор копирования
Textbook::~Textbook() { std::cout << "Вызван деструктор Textbook\n"; } // Деструктор

void Textbook::display() const { // Метод вывода на экран
    std::cout << "--- Учебник ---\n"; // Вывод заголовка
    std::cout << "Название: " << title << "\n"; // Вывод названия
    std::cout << "Автор: " << author << "\n"; // Вывод автора
    std::cout << "Год выпуска: " << year << "\n"; // Вывод года
    std::cout << "Уч. заведение: " << institution << "\n"; // Вывод заведения
    std::cout << "Год обучения: " << studyYear << "\n"; // Вывод года обучения
    std::cout << "Страниц: " << pages << "\n"; // Вывод страниц
    std::cout << "Стоимость: " << getPrice() << "\n"; // Вывод стоимости
}

void Textbook::readFromConsole() { // Метод ввода с клавиатуры
    std::cin.ignore(); // Игнорируем символ переноса строки
    std::cout << "Название: "; std::getline(std::cin, title); // Ввод названия
    std::cout << "Автор: "; std::getline(std::cin, author); // Ввод автора
    std::cout << "Год выпуска: "; std::cin >> year; // Ввод года
    std::cin.ignore(); // Игнорируем перенос строки
    std::cout << "Уч. заведение: "; std::getline(std::cin, institution); // Ввод заведения
    std::cout << "Год обучения: "; std::cin >> studyYear; // Ввод года обучения
    std::cout << "Страниц: "; std::cin >> pages; // Ввод страниц
    std::cout << "Стоимость: "; std::cin >> price; // Ввод стоимости
}

void Textbook::writeToFile(std::ofstream& out) const { // Запись в файл
    out << "T\n"; // Маркер типа объекта
    out << title << "\n" << author << "\n" << year << "\n"; // Запись полей
    out << institution << "\n" << studyYear << "\n" << pages << "\n" << getPrice() << "\n"; // Запись оставшихся полей
}

void Textbook::readFromFile(std::ifstream& in) { // Чтение из файла
    std::getline(in, title); std::getline(in, author); in >> year; // Чтение полей
    in.ignore(); std::getline(in, institution); in >> studyYear; in >> pages; in >> price; // Чтение оставшихся полей
}

Base* Textbook::clone() const { return new Textbook(*this); } // Виртуальный конструктор копирования

void Textbook::edit() { // Метод редактирования
    std::cout << "Редактирование учебника. Оставьте поле пустым, чтобы не менять.\n"; // Подсказка
    std::string temp; // Временная строка
    std::cin.ignore(); // Игнорируем перенос
    std::cout << "Название (" << title << "): "; std::getline(std::cin, temp); if (!temp.empty()) title = temp; // Редактирование названия
    std::cout << "Автор (" << author << "): "; std::getline(std::cin, temp); if (!temp.empty()) author = temp; // Редактирование автора
    std::cout << "Год (" << year << "): "; std::getline(std::cin, temp); if (!temp.empty()) year = std::stoi(temp); // Редактирование года
    std::cout << "Заведение (" << institution << "): "; std::getline(std::cin, temp); if (!temp.empty()) institution = temp; // Редактирование заведения
    std::cout << "Год обучения (" << studyYear << "): "; std::getline(std::cin, temp); if (!temp.empty()) studyYear = std::stoi(temp); // Редактирование года обучения
    std::cout << "Страниц (" << pages << "): "; std::getline(std::cin, temp); if (!temp.empty()) pages = std::stoi(temp); // Редактирование страниц
    std::cout << "Стоимость (" << getPrice() << "): "; std::getline(std::cin, temp); if (!temp.empty()) setPrice(std::stod(temp)); // Редактирование стоимости
}
