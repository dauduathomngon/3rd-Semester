#ifndef FRACTION_H
#define FRACTION_H

#include <stdexcept>

class Fraction
{
public:
    Fraction(const int num, const int den)
    {
        if (den == 0) { throw std::logic_error("denominator must not equal zero"); }

        m_denominator = den;
        m_numerator = num;
    }

    Fraction(const Fraction &frac) {
        m_denominator = frac.GetDen();
        m_numerator = frac.GetNum();
    }

    ~Fraction() = default;

    int GetNum() const { return m_numerator; }

    int GetDen() const { return m_denominator; }

    Fraction operator + (Fraction const &frac)
    {
        int new_den;
        int new_num;

        if (m_denominator = frac.m_denominator)
        {
            new_den = m_denominator;
            new_num = m_numerator + frac.m_numerator;
        }
        else
        {
            new_den = m_denominator * frac.m_denominator;
            new_num = m_numerator * frac.m_denominator + frac.m_numerator * m_denominator;
        }

        return Fraction(new_num, new_den);
    }

private:
    Fraction() = delete;

    int m_denominator;
    int m_numerator;
};

#endif // FRACTION_H