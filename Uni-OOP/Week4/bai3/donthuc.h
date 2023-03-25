#ifndef DONTHUC_H
#define DONTHUC_H

#include <iostream>
#include <cassert>
#include <math.h>

class DonThuc
{
public:
    DonThuc();

    void Input();
    void Output();

    void SetValue(float coeff, int deg);

    float GetValue(float var) const;

    int GetDeg() const;

    DonThuc& operator+=(const DonThuc& dt);
    DonThuc& operator-=(const DonThuc& dt);
    DonThuc& operator*=(const DonThuc& dt);
    DonThuc& operator/=(const DonThuc& dt);

    void Negative();

private:
    float m_Coeff;
    int m_Deg;
};

inline DonThuc operator+(DonThuc ldt, const DonThuc& rdt)
{
    ldt += rdt;
    return ldt;
}

inline DonThuc operator-(DonThuc ldt, const DonThuc& rdt)
{
    ldt -= rdt;
    return ldt;
}

inline DonThuc operator*(DonThuc ldt, const DonThuc& rdt)
{
    ldt *= rdt;
    return ldt;
}

inline DonThuc operator/(DonThuc ldt, const DonThuc& rdt)
{
    ldt /= rdt;
    return ldt;
}

#endif // DONTHUC_H