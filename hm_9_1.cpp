#include <iostream>
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
	}

	double division() { return numerator_ / denominator_; };

	bool isEqualed(Fraction other) { return fabs(division() - other.division()) <= std::numeric_limits<double>::epsilon(); };
	bool isBigger(Fraction other) { return division() > other.division(); };

	bool operator==(Fraction other) { return isEqualed(other); };
	bool operator!=(Fraction other) { return !isEqualed(other); };
	bool operator<(Fraction other) { return !isBigger(other); };
	bool operator>(Fraction other) { return isBigger(other); };
	bool operator<=(Fraction other) { return !isBigger(other) || isEqualed(other); };
	bool operator>=(Fraction other) { return isBigger(other) || isEqualed(other); };
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}