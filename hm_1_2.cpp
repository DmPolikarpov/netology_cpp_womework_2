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
        std::cout << "¬аш счет: " << " " << name << ", " << accountNumber << ", " << balance << std::endl;
    }

    void setBalance(float value)
    {
        balance = value;
    }
};

void changeBalance(Client& client, float balance);

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string name{};
    int accountNumber{ 0 };
    float balance{ 0.0 };

    std::cout << "¬ведите номер счЄта: ";
    std::cin >> accountNumber;

    std::cout << "¬ведите им€ владельца: ";
    std::cin >> name;

    std::cout << "¬ведите баланс: ";
    std::cin >> balance;

    Client client{ name, accountNumber, balance };

    std::cout << "¬ведите новый баланс: ";
    std::cin >> balance;

    changeBalance(client, balance);

    client.printData();


    return EXIT_SUCCESS;
}

void changeBalance(Client& client, float balance)
{
    client.setBalance(balance);
}