#include "dathuc.h"

DaThuc::DaThuc()
: m_Size(0)
, m_Dathuc(nullptr)
{
}

DaThuc::~DaThuc()
{
    delete[] m_Dathuc;
}

void DaThuc::Input()
{
    if (m_Size != 0) { delete m_Dathuc; }

    std::cout << "Moi ban nhap so luong cac don thuc trong da thuc: ";
    std::cin >> m_Size;

    m_Dathuc = new DonThuc[m_Size]();

    for (int i=0; i < m_Size; i++) 
    {
        m_Dathuc[i].Input();
    }
}

void DaThuc::Output()
{
    for (int i=0; i < m_Size; i++) 
    {
        m_Dathuc[i].Output();
    }
}

float DaThuc::GetValue(float var) const
{
    float total = 0;
    for (int i=0; i < m_Size; i++)    
    {
        total += m_Dathuc[i].GetValue(var);
    }
    return total;
}

DaThuc& DaThuc::operator+=(const DaThuc& dt)
{ 
    int newSize = 0;
    std::vector<DonThuc> temp;

    int i = 0;
    int j = 0;

    // create vector to store new da thuc
    while ((i < m_Size) && (j < dt.m_Size))
    {
        if (m_Dathuc[i].GetDeg() > dt.m_Dathuc[j].GetDeg())
        {
            temp.push_back(m_Dathuc[i]);
            ++i;
            ++newSize;
        }
        else if (m_Dathuc[i].GetDeg() < dt.m_Dathuc[j].GetDeg())
        {
            temp.push_back(m_Dathuc[j]);
            ++j;
            ++newSize;
        }
        else
        {
            m_Dathuc[i] += dt.m_Dathuc[j];
            temp.push_back(m_Dathuc[i]);
            ++i;
            ++j;
            ++newSize;
        }
    }

    // copy temp to array
    delete[] m_Dathuc;
    m_Size = newSize;
    m_Dathuc = new DonThuc[m_Size]();
    for (int i=0; i < m_Size; i++)
    {
        m_Dathuc[i] = temp[i];
    }

    return *this;
}

DaThuc& DaThuc::operator-=(DaThuc dt)
{
    for (int i=0; i < dt.m_Size; i++)
    {
        dt.m_Dathuc[i].Negative();
    }
    this->m_Dathuc += dt.m_Dathuc;
    return *this;
}

DaThuc& DaThuc::operator/=(const DaThuc& dt)
{
    return *this;    
}

DaThuc& DaThuc::operator*=(const DaThuc& dt)
{
    return *this;    
}