#include <iostream>

#define MODE 5

#ifndef MODE
#error you should define variable MODE
#endif
#if MODE == 1
int add(int a, int b)
{
	return a + b;
}
#endif

int main()
{
	setlocale(LC_ALL, "Russian");

#if MODE == 0
	std::cout << "Работаю в тестовом режиме" << std::endl;
#elif MODE == 1
	int a{ 0 };
	int b{ 0 };
	std::cout << "Введите число 1: ";
	std::cin >> a;
	std::cout << "Введите число 2: ";
	std::cin >> b;
	std::cout << "Результат сложения: " << add(a, b) << std::endl;
#else
	std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif


	return EXIT_SUCCESS;
}