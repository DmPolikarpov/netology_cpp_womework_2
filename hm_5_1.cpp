#include <iostream>
#include <Windows.h>

class Shape
{
private:
    int sides;

public:
    Shape(int sides) : sides(sides) {};
    int getSidesNumber() { return sides; };
};

class Triangle : public Shape
{
public:
    Triangle() : Shape(3) {};
};

class Quadrangle : public Shape
{
public:
    Quadrangle() : Shape(4) {};
};

int main()
{
    setlocale(LC_ALL, "Russian");
    
    Shape shape{0};
    Triangle triangle{};
    Quadrangle quadrangle{};

    std::cout << "Количество сторон: " << std::endl;
    std::cout << "Фигура: " << shape.getSidesNumber() << std::endl;
    std::cout << "Треугольник: " << triangle.getSidesNumber() << std::endl;
    std::cout << "Четырехугольник: " << quadrangle.getSidesNumber() << std::endl;

    return EXIT_SUCCESS;
}

