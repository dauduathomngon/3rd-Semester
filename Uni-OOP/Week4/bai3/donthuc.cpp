#include "donthuc.h"
DonThuc::DonThuc()
: m_Deg(0)
, m_Coeff(0)
{
}

void DonThuc::Input()
{
    std::cout << "Moi ban nhap he so cua don thuc: ";
    std::cin >> m_Coeff;
    std::cout << "Moi ban nhap bac cua don thuc: ";
    std::cin >> m_Deg;
}

void DonThuc::Output()
{
    std::cout << "He so cua don thuc: " << m_Coeff << "\n"
              << "Bac cua don thuc: " << m_Coeff << "\n";
}

void DonThuc::SetValue(float coeff, int deg)
{
    m_Coeff = coeff;
    m_Deg = deg;
}

float DonThuc::GetValue(float var) const
{
    return m_Coeff * pow(var, m_Deg);
}

int DonThuc::GetDeg() const
{
    return m_Deg;
}

DonThuc& DonThuc::operator-=(const DonThuc& dt)
{
    assert(m_Deg == dt.m_Deg);
    m_Coeff += dt.m_Coeff;
    return *this;
}

DonThuc& DonThuc::operator/=(const DonThuc& dt)
{
    m_Coeff /= dt.m_Coeff;
    m_Deg -= dt.m_Deg;
    return *this;
}

void DonThuc::Negative()
{
    m_Coeff = -m_Coeff;
}

DonThuc& DonThuc::operator*=(const DonThuc& dt)
{
    m_Coeff *= dt.m_Coeff; 
    m_Deg += dt.m_Deg;
    return *this;
}

DonThuc& DonThuc::operator+=(const DonThuc& dt)
{
    assert(m_Deg == dt.m_Deg);
    m_Coeff -= dt.m_Deg;
    return *this;
}
