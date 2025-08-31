#include <iostream>

struct Client
{
private:
    std::string name{};
    int accountNumber{};
    float balance{};

public:
    Client(std::string setName, int setNumber, float setBalance) : name{ setName }, accountNumber{ setNumber }, balance{ setBalance }
    {};

    void printData()
    {
        std::cout << "��� ����: " << " " << name << ", " << accountNumber << ", " << balance << std::endl;
    }

    void changeBalance(float value)
    {
        balance = value;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string name{};
    int accountNumber{ 0 };
    float balance{ 0.0 };

    std::cout << "������� ����� �����: ";
    std::cin >> accountNumber;

    std::cout << "������� ��� ���������: ";
    std::cin >> name;

    std::cout << "������� ������: ";
    std::cin >> balance;

    Client client{ name, accountNumber, balance };

    std::cout << "������� ����� ������: ";
    std::cin >> balance;

    client.changeBalance(balance);

    client.printData();


    return EXIT_SUCCESS;
}