#include <iostream> // Подключаем ввод-вывод
#include <string> // Подключаем строки
#include "Keeper.h" // Подключаем контейнер
#include "Book.h" // Подключаем Книгу
#include "Textbook.h" // Подключаем Учебник
#include "Stationery.h" // Подключаем Канцелярию
#include "Exceptions.h" // Подключаем исключения
#include <Windows.h> // управление параметрами системы (для изменения кодовой страницы)

using namespace std; // Используем стандартное пространство имен

int main() { // Главная функция

 //   SetConsoleCP(65001); // Принудительная установка консоли ввода на UTF-8  или setlocale(LC_CTYPE, "ru_RU.UTF-8");
 //   SetConsoleOutputCP(65001); // Принудительная установка консоли вывода на UTF-8 или SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);       // Принудительная установка консоли ввода на кириллицу windows
    SetConsoleOutputCP(1251); // Принудительная установка консоли вывода на кириллицу windows
    
    Keeper store; // Создаем объект контейнера
    bool running = true; // Флаг работы цикла
    while (running) { // Цикл меню
        cout << "\n--- Меню Книжного магазина ---\n"; // Вывод заголовка
        cout << "1. Добавить товар\n"; // Пункт 1
        cout << "2. Удалить товар\n"; // Пункт 2
        cout << "3. Показать все товары\n"; // Пункт 3
        cout << "4. Редактировать товар\n"; // Пункт 4
        cout << "5. Сохранить в файл\n"; // Пункт 5
        cout << "6. Загрузить из файла\n"; // Пункт 6
        cout << "0. Выход\n"; // Пункт 0
        cout << "Выберите пункт: "; // Подсказка ввода
        int choice; cin >> choice; // Ввод выбора
        try { // Блок обработки исключений
            if (choice == 1) { // Если выбрано добавление
                cout << "1. Книга\n2. Учебник\n3. Канцелярия\nВыберите тип: "; // Выбор типа
                int type; cin >> type; // Ввод типа
                Base* newItem = nullptr; // Указатель на объект
                if (type == 1) newItem = new Book(); // Создание Книги
                else if (type == 2) newItem = new Textbook(); // Создание Учебника
                else if (type == 3) newItem = new Stationery(); // Создание Канцелярии
                else throw InputException("Неверный тип товара"); // Исключение
                cout << "Введите данные:\n"; // Подсказка
                newItem->readFromConsole(); // Ввод данных
                store.add(newItem); // Добавление в контейнер
                cout << "Товар добавлен!\n"; // Подтверждение
            }
            else if (choice == 2) { // Если выбрано удаление
                store.displayAll(); // Показываем список
                cout << "Введите индекс для удаления: "; // Подсказка
                int idx; cin >> idx; // Ввод индекса
                store.remove(idx); // Удаление
                cout << "Товар удален!\n"; // Подтверждение
            }
            else if (choice == 3) { // Если выбран показ
                store.displayAll(); // Показываем список
            }
            else if (choice == 4) { // Если выбрано редактирование
                store.displayAll(); // Показываем список
                cout << "Введите индекс для редактирования: "; // Подсказка
                int idx; cin >> idx; // Ввод индекса
                store.editItem(idx); // Редактирование
            }
            else if (choice == 5) { // Если выбрано сохранение
                string fname; cout << "Имя файла: "; cin >> fname; // Ввод имени файла
                store.saveToFile(fname); // Сохранение
                cout << "Данные сохранены!\n"; // Подтверждение
            }
            else if (choice == 6) { // Если выбрана загрузка
                string fname; cout << "Имя файла: "; cin >> fname; // Ввод имени файла
                store.loadFromFile(fname); // Загрузка
                cout << "Данные загружены!\n"; // Подтверждение
            }
            else if (choice == 0) { // Если выбран выход
                running = false; // Завершение цикла
                cout << "Выход из программы...\n"; // Прощание
            }
            else { // Если введен неверный пункт
                throw InputException("Неверный пункт меню"); // Исключение
            }
        }
        catch (const exception& e) { // Ловим стандартные и наши исключения
            cout << "Ошибка: " << e.what() << "\n"; // Вывод текста ошибки
        }
    }
    return 0; // Завершение программы
}
