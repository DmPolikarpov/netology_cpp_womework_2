#include <iostream>
#include <Windows.h>

class Shape
{
private:
    int sides{ 0 };

protected:
    void setSidesNumber(int value) { sides = value; };

public:
    int getSidesNumber() { return sides; };
};

class Triangle : public Shape
{
public:
    Triangle()
    {
        setSidesNumber(3);
    }
};

class Quadrangle : public Shape
{
public:
    Quadrangle()
    {
        setSidesNumber(4);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    
    Shape shape{};
    Triangle triangle{};
    Quadrangle quadrangle{};

    std::cout << "���������� ������: " << std::endl;
    std::cout << "������: " << shape.getSidesNumber() << std::endl;
    std::cout << "�����������: " << triangle.getSidesNumber() << std::endl;
    std::cout << "���������������: " << quadrangle.getSidesNumber() << std::endl;

    return EXIT_SUCCESS;
}

