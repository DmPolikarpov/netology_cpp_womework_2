#include <iostream>
#include <Windows.h>

int function(std::string str, int forbidden_length);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int forbidden_length{ };

	std::string word{};

	std::cout << "������� ��������� �����: ";
	std::cin >> forbidden_length;


	try
	{
		while (true)
		{
			std::cout << "������� �����: ";
			std::cin >> word;
			std::cout << "����� ����� \"" << word << "\" ����� " << function(word, forbidden_length) << std::endl;
		}
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}


	return EXIT_SUCCESS;
}

int function(std::string str, int forbidden_length)
{
	int str_length{ static_cast<int>(str.length())};

	if (str_length == forbidden_length)
		throw std::runtime_error("�� ����� ����� ��������� �����! �� ��������");
	
	return str_length;
}