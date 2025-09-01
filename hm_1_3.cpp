#include <iostream>

struct Address
{
private:
    std::string town{};
    std::string street{};
    int building{};
    int flat{};
    int index{};

public:
    Address(std::string setTown, std::string setStreet, int setBuild, int setFlat, int setIndex) : town{ setTown }, street{ setStreet }, building{ setBuild }, flat{ setFlat }, index{ setIndex }
    {
    };

    void printData()
    {
        std::cout << "Город: " << town << std::endl;
        std::cout << "Улица: " << street << std::endl;
        std::cout << "Номер дома: " << building << std::endl;
        std::cout << "Номер квартиры: " << flat << std::endl;
        std::cout << "Индекс: " << index << std::endl;
    }
};

void showAddress(Address& address);

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string town{};
    std::string street{};
    int building{};
    int flat{};
    int index{};

    std::cout << "Город: ";
    std::cin >> town;

    std::cout << "Улица: ";
    std::cin >> street;

    std::cout << "Номер дома: ";
    std::cin >> building;

    std::cout << "Номер квартиры: ";
    std::cin >> flat;

    std::cout << "Индекс: ";
    std::cin >> index;

    Address address{ town, street, building, flat, index };

    showAddress(address);


    return EXIT_SUCCESS;
}

void showAddress(Address& address)
{
    address.printData();
}