#include <iostream>

int getMonth(int month);

enum Months { Прощай, Январь, Февраль, Март, Апрель, Май, Июнь, Июль, Август, Сентябрь, Октябрь, Ноябрь, Декабрь };

int main()
{
    setlocale(LC_ALL, "Russian");

    int monthNumber{ 0 };
    int finished{ 0 };

    do
    {
        std::cout << "Введите номер месяца: ";
        std::cin >> monthNumber;
        finished = getMonth(monthNumber);
    } while (!finished);

    
     
    return EXIT_SUCCESS;
}

int getMonth(int monthNumber)
{
    Months months{ static_cast<Months>(monthNumber) };

    int result{ 0 };

    switch (months)
    {
    case Январь:
        std::cout << "Январь" << std::endl;
        break;
    case Февраль:
        std::cout << "Февраль" << std::endl;
        break;
    case Март:
        std::cout << "Март" << std::endl;
        break;
    case Апрель:
        std::cout << "Апрель" << std::endl;
        break;
    case Май:
        std::cout << "Май" << std::endl;
        break;
    case Июнь:
        std::cout << "Июнь" << std::endl;
        break;
    case Июль:
        std::cout << "Июль" << std::endl;
        break;
    case Август:
        std::cout << "Август" << std::endl;
        break;
    case Сентябрь:
        std::cout << "Сентябрь" << std::endl;
        break;
    case Октябрь:
        std::cout << "Октябрь" << std::endl;
        break;
    case Ноябрь:
        std::cout << "Ноябрь" << std::endl;
        break;
    case Декабрь:
        std::cout << "Декабрь" << std::endl;
        break;
    case Прощай:
        std::cout << "До свидания" << std::endl;
        result = 1;
        break;
    default:
        std::cout << "Неправильный номер!" << std::endl;
        break;
    }

    return result;
}


