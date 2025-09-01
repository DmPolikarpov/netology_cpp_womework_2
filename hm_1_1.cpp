#include <iostream>

int getMonth(int month);

enum Months { BYE, JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

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
    case JANUARY:
        std::cout << "Январь" << std::endl;
        break;
    case FEBRUARY:
        std::cout << "Февраль" << std::endl;
        break;
    case MARCH:
        std::cout << "Март" << std::endl;
        break;
    case APRIL:
        std::cout << "Апрель" << std::endl;
        break;
    case MAY:
        std::cout << "Май" << std::endl;
        break;
    case JUNE:
        std::cout << "Июнь" << std::endl;
        break;
    case JULY:
        std::cout << "Июль" << std::endl;
        break;
    case AUGUST:
        std::cout << "Август" << std::endl;
        break;
    case SEPTEMBER:
        std::cout << "Сентябрь" << std::endl;
        break;
    case OCTOBER:
        std::cout << "Октябрь" << std::endl;
        break;
    case NOVEMBER:
        std::cout << "Ноябрь" << std::endl;
        break;
    case DECEMBER:
        std::cout << "Декабрь" << std::endl;
        break;
    case BYE:
        std::cout << "До свидания" << std::endl;
        result = 1;
        break;
    default:
        std::cout << "Неправильный номер!" << std::endl;
        break;
    }

    return result;
}


