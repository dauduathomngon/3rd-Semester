#pragma once
#ifndef DATHUC_H
#define DATHUC_H

#include <vector>

#include "donthuc.h"

class DaThuc
{
public:
    DaThuc();
    ~DaThuc();
    DaThuc(const DaThuc& dt);
    DaThuc(const DonThuc& dt);

    void Input();
    void Output();

    float GetValue(float var) const;

    DaThuc& operator+=(const DaThuc& dt);
    DaThuc& operator-=(DaThuc dt);
    DaThuc& operator*=(const DaThuc& dt);
    // return quotient
    DaThuc& operator/=(const DaThuc& dt);
    // return remainder
    DaThuc& operator%=(const DaThuc& dt);

    void swap(DaThuc& dt1, DaThuc& dt2);
    DaThuc& operator=(DaThuc dt);

private:
    int m_Size;
    DonThuc* m_Dathuc;
};

inline DaThuc operator+(DaThuc ldt, const DaThuc& rdt)
{
    ldt += rdt;
    return ldt;
}

inline DaThuc operator-(DaThuc ldt, const DaThuc& rdt)
{
    ldt -= rdt;
    return ldt;
}

inline DaThuc operator*(DaThuc ldt, const DaThuc& rdt)
{
    ldt *= rdt;
    return ldt;
}

inline DaThuc operator/(DaThuc ldt, const DaThuc& rdt)
{
    ldt /= rdt;
    return ldt;
}

inline DaThuc operator%(DaThuc ldt, const DaThuc& rdt)
{
    ldt %= rdt;
    return ldt;
}

#endif // DATHUC_H
