#include <iostream>

class Fraction
{
private:
    int m_numerator = 0;
    int m_denominator = 1;

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(int value, const Fraction &f);
    friend Fraction operator*(const Fraction &f, int value);
    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1);
    friend std::istream& operator>>(std::istream& in, Fraction &f1);

    void print()
    {
        reduce();
        std::cout << m_numerator << "/" << m_denominator << std::endl;
    }

    void reduce()
    {
        int gcd = Fraction::gcd(m_numerator, m_denominator);

        m_numerator /= gcd;
        m_denominator /= gcd;
    }

    int gcd(int a, int b) {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }
};

std::ostream& operator<< (std::ostream& out, const Fraction &f1)
{
    out << f1.m_numerator << "/" << f1.m_denominator;

    return out;
}

std::istream& operator>> (std::istream& in, Fraction &f1)
{
    char c;
    in >> f1.m_numerator;
    in >> c; //ignore "/"
    in >> f1.m_denominator;

    return in;
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    int numerator = f1.m_numerator * f2.m_numerator;
    int denominator = f1.m_denominator * f2.m_denominator;

    return Fraction(numerator,denominator);
}

Fraction operator*(int value, const Fraction &f2)
{
    int numerator = value * f2.m_numerator;
    int denominator = f2.m_denominator;

    return Fraction(numerator,denominator);
}

Fraction operator*(const Fraction &f, int value)
{
    return (value * f);
}

int main()
{
    std::cout << "Test";
    Fraction f1;
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2;
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

    /**
    Fraction f1(2, 5);
    f1.print();

    Fraction f2(3, 8);
    f2.print();

    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 2;
    f4.print();

    Fraction f5 = 2 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();
    **/

    return 0;
}
