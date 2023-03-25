#include "phanso.h"

PhanSo::PhanSo()
: m_Denom(1)
, m_Numer(0)
{
}

void PhanSo::Input()
{
    // nhap mau so
    int mauSo = 1;
    do
    {
        std::cout << "Moi ban nhap mau so: ";
        std::cin >> mauSo;
    } while (mauSo == 0);

    // nhap tu so
    int tuSo = 0;
    std::cout << "Moi ban nhap tu so: ";
    std::cin >> tuSo;

    // gan gia tri
    m_Denom = mauSo;
    m_Numer = tuSo;
}

void PhanSo::Print()
{
    std::cout << "Tu so la: " << m_Numer << "\n";
    std::cout << "Mau so la: " << m_Denom << "\n";
}

void PhanSo::Simplify()
{
    int gcd = FindGCD(m_Numer, m_Denom);
    m_Numer /= gcd;
    m_Denom /= gcd;
}

void PhanSo::SetValue(const std::string& mauSo, const std::string& tuSo)
{
    m_Denom = std::atoi(mauSo.c_str());
    m_Numer = std::atoi(tuSo.c_str());
}

PhanSo& PhanSo::operator+=(const PhanSo& ps)
{ 
    // quy dong
    m_Numer = m_Numer * ps.m_Denom + ps.m_Numer * m_Denom;
    m_Denom *= ps.m_Denom;
    // rut gon
    this->Simplify();
    return *this;
}

PhanSo& PhanSo::operator-=(const PhanSo& ps)
{
    // quy dong
    m_Numer = m_Numer * ps.m_Denom - ps.m_Numer * m_Denom;
    m_Denom *= ps.m_Denom;
    // rut gon
    this->Simplify();
    return *this;
}

PhanSo& PhanSo::operator*=(const PhanSo& ps) 
{
    // nhan mau va tu
    m_Numer *= ps.m_Numer;
    m_Denom *= ps.m_Denom;
    // rut gon
    this->Simplify();
    return *this;
}

PhanSo& PhanSo::operator/=(const PhanSo& ps)
{
    // nhan mau va tu
    m_Numer *= ps.m_Denom;
    m_Denom *= ps.m_Numer;
    // rut gon
    this->Simplify();
    return *this;
}

bool operator>(const PhanSo& lps, const PhanSo& rps)
{
    return lps.m_Numer * rps.m_Denom > rps.m_Numer * lps.m_Denom;
}

std::ostream& operator<<(std::ostream& os, const PhanSo& ps)
{
    os << "Tu so: " << ps.m_Numer << " "
       << "Mau so: " << ps.m_Denom << "\n";
    return os;
}