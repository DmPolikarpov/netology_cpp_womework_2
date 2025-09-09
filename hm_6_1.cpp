#include <iostream>
#include <Windows.h>
#include "math61.h"

void printResult(int type, double val1, double val2);

int main()
{
	SetConsoleOutputCP(1251);

	double val1{};
	double val2{};
	int type{};

	std::cout << "Введите первое число:";
	std::cin >> val1;

	std::cout << "Введите второе число:";
	std::cin >> val2;

	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень):";
	std::cin >> type;

	if (type == 4 && val2 == 0)
	{
		std::cout << "Второе число не может равняться нулю для исключения ошибки при делении" << std::endl;
	}
	else
	{
		printResult(type, val1, val2);
	}

	return EXIT_SUCCESS;
}

void printResult(int type, double val1, double val2)
{
	switch (type)
	{
	case 1:
		std::cout << val1 << " + " << val2 << " = " << sum(val1, val2) << std::endl;
		break;
	case 2:
		std::cout << val1 << " - " << val2 << " = " << difference(val1, val2) << std::endl;
		break;
	case 3:
		std::cout << val1 << " * " << val2 << " = " << multiplication(val1, val2) << std::endl;
		break;
	case 4:
		std::cout << val1 << " / " << val2 << " = " << division(val1, val2) << std::endl;
		break;
	case 5:
		std::cout << val1 << " в степени " << val2 << " = " << power(val1, val2) << std::endl;
		break;
	default:
		std::cout << "Ошибка! Неизвестный тип операции!" << std::endl;
		break;
	}
}