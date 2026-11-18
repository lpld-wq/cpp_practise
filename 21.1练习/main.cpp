#include <iostream>
#include <numeric>


class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    explicit Fraction(int numerator, int denominator)
        : m_numerator{ numerator }, m_denominator{ denominator }
    {
        reduce();
    }
    void reduce()
    {
        
        int gcd{ std::gcd(m_numerator,m_denominator) };
        if (gcd)
        {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
       
    }

    void print()
    {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int x);
    friend Fraction operator*(int x, const Fraction& f1);

};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    int numerator{ f1.m_numerator * f2.m_numerator };
    int denominator{ f1.m_denominator * f2.m_denominator };
    return Fraction{ numerator , denominator };
}


Fraction operator*(const Fraction& f1, int x)
{
    int numerator{ f1.m_numerator * x};
    int denominator{ f1.m_denominator};
    return Fraction{ numerator , denominator };
}

Fraction operator*(int x, const Fraction& f1)
{
    int numerator{ f1.m_numerator * x };
    int denominator{ f1.m_denominator };
    return Fraction{ numerator , denominator };
}

int main()
{
    Fraction f1{ 2, 5 };
    f1.print();

    Fraction f2{ 3, 8 };
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    return 0;

}
