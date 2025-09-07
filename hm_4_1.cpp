#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class Address
{
private:
	std::string town{};
	std::string street{};
	int house{};
	int flat{};

public:
	Address(const std::string& setTown, const std::string& setStreet, int setHouse, int setFlat) : town{setTown}, street{setStreet}, house{ setHouse }, flat{setFlat}
	{};
	Address() = default;

	std::string getAddress()
	{
		return town + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
	}
	
};

int main()
{
	SetConsoleOutputCP(1251);

	int size{ 0 };
	std::string town;
	std::string street;
	int house;
	int flat;

	std::ifstream iText{ "in.txt" };

	if (iText.is_open())
	{

		iText >> size;

		Address* adresses_list = new Address[size];

		for (int i = 0; i < size; i++) {
			iText >> town;
			iText >> street;
			iText >> house;
			iText >> flat;
			adresses_list[i] = Address(town, street, house, flat);
		}

		std::ofstream oText{ "out.txt" };

		if (oText.is_open()) {
			oText << size << std::endl;
			for (int i = size - 1; i >= 0; i--) {
				oText << adresses_list[i].getAddress() << std::endl;
			}
		}
		else {
			std::cout << "some error in output file happened!" << std::endl;
		}

		oText.close();

		delete[] adresses_list;
	}
	else
	{
		std::cout << "some error in input file happened!" << std::endl;
	}

	iText.close();

	return EXIT_SUCCESS;
}