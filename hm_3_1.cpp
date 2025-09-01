#include <iostream>

class Calculator
{
private:
    double num1{};
    double num2{};

public:

    bool set_num1(double num1)
    {
        if (num1 == 0)
            return false;
        else
            this->num1 = num1;

        return true;
    }

    bool set_num2(double num2)
    {
        if (num2 == 0)
            return false;
        else
            this->num2 = num2;

        return true;
    }

    double add()
    {
        return num1 + num2;
    }

    double multiply()
    {
        return num1 * num2;
    }

    double subtract_1_2()
    {
        return num1 - num2;
    }

    double subtract_2_1()
    {
        return num2 - num1;
    }

    double divide_1_2()
    {
        return num1 / num2;
    }

    double divide_2_1()
    {
        return num2 / num1;
    }
};

void showResults(Calculator& calc, double num1, double num2);

int main()
{
    setlocale(LC_ALL, "Russian");

    double num1{ 0.0 };
    double num2{ 0.0 };

    Calculator calculator{ };

    while (true)
    {
        std::cout << "Введите num1: ";
        std::cin >> num1;

        std::cout << "Введите num2: ";
        std::cin >> num2;

        showResults(calculator, num1, num2);
    };


    return EXIT_SUCCESS;
}

void showResults(Calculator& calc, double num1, double num2)
{
    bool isNum1Correct{ calc.set_num1(num1) };
    bool isNum2Correct{ calc.set_num2(num2) };

    if (!isNum1Correct || !isNum2Correct)
        std::cout << "Неверный ввод!" << std::endl;
    else
    {
        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }
}