#include <iostream>
#include <Windows.h>
#include <cmath>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
		simplify();
	}

	int gcd(int a, int b) {
		return (b == 0) ? a : gcd(b, a % b);
	}
	void simplify() {
		int gcdValue = gcd(fabs(numerator_), fabs(denominator_));
		numerator_ /= gcdValue;
		denominator_ /= gcdValue;
	}


	int getNumerator() { return numerator_; };
	int getDenomirator() { return denominator_;  };

	Fraction operator+(Fraction other) { return Fraction(numerator_ * other.getDenomirator() + denominator_ * other.getNumerator(), denominator_ * other.getDenomirator()); };
	Fraction operator-(Fraction other) { return Fraction(numerator_ * other.getDenomirator() - denominator_ * other.getNumerator(), denominator_ * other.getDenomirator()); };
	Fraction operator*(Fraction other) { return Fraction(numerator_ * other.getNumerator(), denominator_ * other.getDenomirator()); };
	Fraction operator/(Fraction other) { return Fraction(numerator_ * other.getDenomirator(), denominator_ * other.getNumerator()); };
	Fraction& operator++()
	{ 
		numerator_ = numerator_ + denominator_;
		simplify();
		return *this;
	};
	Fraction& operator--(int)
	{
		Fraction temporary{ *this };
		numerator_ = numerator_ - denominator_;
		simplify();
		return temporary;
	};
	
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int num1{};
	int num2{};
	int den1{};
	int den2{};

	std::cout << "¬ведите числитель дроби 1: ";
	std::cin >> num1;

	std::cout << "¬ведите знаменатель дроби 1: ";
	std::cin >> den1;

	std::cout << "¬ведите числитель дроби 2: ";
	std::cin >> num2;

	std::cout << "¬ведите знаменатель дроби 2: ";
	std::cin >> den2;


	Fraction f1(num1, den1);
	Fraction f2(num2, den2);


	/*3 / 4 + 4 / 5 = 31 / 20
	a* d + b * c, b* d
	3*5 + 4*4 = 31*/

	Fraction f3{ f1 + f2 };
	std::cout << num1 << "/" << den1 << " + " << num2 << "/" << den2 << " = " << f3.getNumerator() << "/" << f3.getDenomirator() << std::endl;

	Fraction f4{ f1 - f2 };
	std::cout << num1 << "/" << den1 << " - " << num2 << "/" << den2 << " = " << f4.getNumerator() << "/" << f4.getDenomirator() << std::endl;

	Fraction f5{ f1 * f2 };
	std::cout << num1 << "/" << den1 << " * " << num2 << "/" << den2 << " = " << f5.getNumerator() << "/" << f5.getDenomirator() << std::endl;

	Fraction f6{ f1 / f2 };
	std::cout << num1 << "/" << den1 << " / " << num2 << "/" << den2 << " = " << f6.getNumerator() << "/" << f6.getDenomirator() << std::endl;

	Fraction f7{ ++f1 * f2 };
	std::cout << "++" << num1 << "/" << den1 << " * " << num2 << "/" << den2 << " = " << f7.getNumerator() << "/" << f7.getDenomirator() << std::endl;

	std::cout << "«начение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenomirator() << std::endl;

	Fraction f8{ f1-- * f2 };
	std::cout << num1 << "/" << den1 << "-- " << " * " << num2 << " / " << den2 << " = " << f8.getNumerator() << " / " << f8.getDenomirator() << std::endl;

	std::cout << "«начение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenomirator() << std::endl;

	return 0;
}