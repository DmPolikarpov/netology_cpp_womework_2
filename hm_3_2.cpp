#include <iostream>
#include <Windows.h>

class Counter
{
private:
    int value{1};

public:

    Counter() = default;
    Counter(int setVal) : value{setVal}
    {};

    void incrementValue()
    {
        value++;
    }

    void decrementValue()
    {
        value--;
    }

    void showCurrentValue()
    {
        std::cout << value << std::endl;
    }
};

void startWork(Counter counter);


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    bool isCorrect{};
    int option{ 0 };

    while (!isCorrect)
    {
        std::string answer{};
        std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
        std::cin >> answer;
        
        if (answer == "��" || answer == "��")
        {
            option = 1;
            isCorrect = true;
        }
        else if (answer == "���" || answer == "���")
        {
            option = 0;
            isCorrect = true;
        }
        else
            isCorrect = false;      
    }

    if (option)
    {
        int initVal{ 0 };
        std::cout << "������� ��������� �������� ��������: ";
        std::cin >> initVal;
        Counter counter{ initVal };
        startWork(counter);
    }
    else
    {
        Counter counter{};
        startWork(counter);
    }


    return EXIT_SUCCESS;
}

void startWork(Counter counter)
{
    char command{};
    bool isRunning{true};

    do
    {
        std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
        std::cin >> command;

        switch (command)
        {
        case 'x':
            std::cout << "�� ��������!";
            isRunning = false;
            break;
        case '+':
            counter.incrementValue();
            break;
        case '-':
            counter.decrementValue();
            break;
        case '=':
            counter.showCurrentValue();
            break;
        default:
            std::cout << "����������� �������!";
            break;
        }
    } while (isRunning);
}
