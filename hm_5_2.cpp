#include <iostream>
#include <Windows.h>

class Shape
{
private:
    int sides{ 0 };

public:
    virtual void getSides() = 0;
    virtual void getAngles() = 0;
};

class Triangle : public Shape
{
private:
    int side1{};
    int side2{};
    int side3{};
    int angle1{};
    int angle2{};
    int angle3{};

public:
    Triangle(int setSide1, int setSide2, int setSide3, int setAngle1, int setAngle2, int setAngle3) : side1{ setSide1 }, side2{ setSide2 }, side3{ setSide3 }, angle1{ setAngle1 }, angle2{ setAngle2 }, angle3{ setAngle3 }
    {};
    void getSides() override
    {
        std::cout << "Стороны: a = " << side1 << " b = " << side2 << " c = " << side3 << std::endl;
    };
    void getAngles() override
    {
        std::cout << "Углы: A = " << angle1 << " B = " << angle2 << " C = " << angle3 << std::endl;
    };
};

// TRIANGLE OPTIONS

class RightTriangle : public Triangle
{
public:
    RightTriangle(int setSide1, int setSide2, int setSide3, int setAngle1, int setAngle2) : Triangle{setSide1, setSide2, setSide3, setAngle1, setAngle2, 90 }
    {};
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int setSide1, int setSide2, int setAngle1, int setAngle2) : Triangle{ setSide1, setSide2, setSide2, setAngle1, setAngle2, setAngle2 }
    {
    };
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
    EquilateralTriangle(int setSide) : IsoscelesTriangle{ setSide, setSide, 60, 60 }
    {
    };
};

// QUADRANGLE OPTIONS

class Quadrangle : public Shape
{
private:
    int side1{};
    int side2{};
    int side3{};
    int side4{};
    int angle1{};
    int angle2{};
    int angle3{};
    int angle4{};

public:
    Quadrangle(int setSide1, int setSide2, int setSide3, int setSide4, int setAngle1, int setAngle2, int setAngle3, int setAngle4) : 
        side1{ setSide1 }, side2{ setSide2 }, side3{ setSide3 }, side4{ setSide4 }, angle1{ setAngle1 }, angle2{ setAngle2 }, angle3{ setAngle3 }, angle4{ setAngle4 }
    {
    };
    void getSides() override
    {
        std::cout << "Стороны: a = " << side1 << " b = " << side2 << " c = " << side3 << " d = " << side4 << std::endl;
    };
    void getAngles() override
    {
        std::cout << "Углы: A = " << angle1 << " B = " << angle2 << " C = " << angle3 << " D = " << angle4 << std::endl;
    };
};

class Rectangle1 : public Quadrangle
{
public:
    Rectangle1(int setSide1, int setSide2) : Quadrangle{ setSide1, setSide2, setSide1, setSide2, 90, 90, 90, 90 }
    {
    };
};

class Square : public Rectangle1
{
public:
    Square(int setSide) : Rectangle1{ setSide, setSide}
    {
    };
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int setSide1, int setSide2, int setAngle1, int setAngle2) : Quadrangle{ setSide1, setSide2, setSide1, setSide2, setAngle1, setAngle2, setAngle1, setAngle2 }
    {
    };
};

class Rhomb : public Parallelogram
{
public:
    Rhomb(int setSide1, int setAngle1, int setAngle2) : Parallelogram{ setSide1, setSide1, setAngle1, setAngle2 }
    {
    };
};

// COMMON FUNCTIONS
void print_info(Shape* shape);


int main()
{
    setlocale(LC_ALL, "Russian");

    // TRIANGLES

    Triangle triangle{10, 20, 30, 40, 50, 60};
    RightTriangle rightTriangle{10, 20, 30, 40, 50};
    IsoscelesTriangle isoscelesTriangle{ 10, 20, 40, 50 };
    EquilateralTriangle equilateralTriangle{ 10 };

    // QUADRANGLES

    Quadrangle quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };
    Rectangle1 rectangle{ 10, 20 };
    Square square{ 10 };
    Parallelogram parallelogram{ 10, 20, 50, 60 };
    Rhomb rhomb{ 20, 50, 60 };

    // TRIANGLES DATA

    std::cout << "Треугольник: " << std::endl;
    print_info(&triangle);
    std::cout << "Прямоугольный треугольник: " << std::endl;
    print_info(&rightTriangle);
    std::cout << "Равнобедренный треугольник: " << std::endl;
    print_info(&isoscelesTriangle);
    std::cout << "Равносторонний треугольник: " << std::endl;
    print_info(&equilateralTriangle);

    std::cout << std::endl;

    // QUADRANGLE DATA

    std::cout << "Четырёхугольник: " << std::endl;
    print_info(&quadrangle);
    std::cout << "Прямоугольник: " << std::endl;
    print_info(&rectangle);
    std::cout << "Квадрат: " << std::endl;
    print_info(&square);
    std::cout << "параллелограмм: " << std::endl;
    print_info(&parallelogram);
    std::cout << "Ромб: " << std::endl;
    print_info(&rhomb);


    return EXIT_SUCCESS;
}

void print_info(Shape* shape)
{
    shape->getSides();
    shape->getAngles();
};