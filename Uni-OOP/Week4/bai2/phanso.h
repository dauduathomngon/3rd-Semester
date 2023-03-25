#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
#include <cassert>

class PhanSo
{
public:
    PhanSo();

    void Input();
    void Print();
    void Simplify();

    void SetValue(const std::string& mauSo, const std::string& tuSo);

    PhanSo& operator+=(const PhanSo& ps);
    PhanSo& operator-=(const PhanSo& ps);
    PhanSo& operator*=(const PhanSo& ps);
    PhanSo& operator/=(const PhanSo& ps);

    friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);
    friend bool operator>(const PhanSo& lps, const PhanSo& rps);

private:
    int m_Denom;
    int m_Numer;
    
    PhanSo(int, int) = delete;

    int FindGCD(int a, int b)
    {
        if (a == 0) { return b; }
        return FindGCD(b % a, a);
    }
};

inline PhanSo operator+(PhanSo lps, const PhanSo& rps)
{
    lps += rps;
    return lps;
}

inline PhanSo operator-(PhanSo lps, const PhanSo& rps)
{
    lps -= rps;
    return lps;
}

inline PhanSo operator*(PhanSo lps, const PhanSo& rps)
{
    lps *= rps;
    return lps;
}

inline PhanSo operator/(PhanSo lps, const PhanSo& rps)
{
    lps /= rps;
    return lps;
}

#endif // PHANSO_H