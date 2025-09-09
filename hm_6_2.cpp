#include <iostream>
#include <Windows.h>
#include "counter.h"

void startWork(Counter counter);


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    bool isCorrect{};
    int option{ 0 };

    while (!isCorrect)
    {
        std::string answer{};
        std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> answer;

        if (answer == "да" || answer == "Да")
        {
            option = 1;
            isCorrect = true;
        }
        else if (answer == "Нет" || answer == "нет")
        {
            option = 0;
            isCorrect = true;
        }
        else
            isCorrect = false;
    }

    if (option)
    {
        int initVal{ 0 };
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initVal;
        Counter counter{ initVal };
        startWork(counter);
    }
    else
    {
        Counter counter{};
        startWork(counter);
    }


    return EXIT_SUCCESS;
}

void startWork(Counter counter)
{
    char command{};
    bool isRunning{ true };

    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        switch (command)
        {
        case 'x':
            std::cout << "До свидания!";
            isRunning = false;
            break;
        case '+':
            counter.incrementValue();
            break;
        case '-':
            counter.decrementValue();
            break;
        case '=':
            counter.showCurrentValue();
            break;
        default:
            std::cout << "Такой команды нет!";
            break;
        }
    } while (isRunning);
}