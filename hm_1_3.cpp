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
        std::cout << "�����: " << town << std::endl;
        std::cout << "�����: " << street << std::endl;
        std::cout << "����� ����: " << building << std::endl;
        std::cout << "����� ��������: " << flat << std::endl;
        std::cout << "������: " << index << std::endl;
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

    std::cout << "�����: ";
    std::cin >> town;

    std::cout << "�����: ";
    std::cin >> street;

    std::cout << "����� ����: ";
    std::cin >> building;

    std::cout << "����� ��������: ";
    std::cin >> flat;

    std::cout << "������: ";
    std::cin >> index;

    Address address{ town, street, building, flat, index };

    showAddress(address);


    return EXIT_SUCCESS;
}

void showAddress(Address& address)
{
    address.printData();
}