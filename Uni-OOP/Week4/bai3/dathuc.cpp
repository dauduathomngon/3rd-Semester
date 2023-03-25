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

DaThuc::DaThuc(const DaThuc& dt)
: m_Size(dt.m_Size)
, m_Dathuc(m_Size != 0 ? new DonThuc[m_Size]() : nullptr)
{
    for (int i = 0; i < m_Size; i++)
    {
        m_Dathuc[i] = dt.m_Dathuc[i];
    }
}

DaThuc::DaThuc(const DonThuc& dt)
: m_Size(1)
, m_Dathuc(new DonThuc[1]())
{
    m_Dathuc[0] = dt;
}

void DaThuc::Input()
{
    if (m_Size != 0) { delete m_Dathuc; }

    std::cout << "Moi ban nhap so luong cac don thuc trong da thuc: ";
    std::cin >> m_Size;

    m_Dathuc = new DonThuc[m_Size]();

    for (int i = 0; i < m_Size; i++)
    {
        m_Dathuc[i].Input();
    }
}

void DaThuc::Output()
{
    for (int i = 0; i < m_Size; i++)
    {
        m_Dathuc[i].Output();
    }
}

float DaThuc::GetValue(float var) const
{
    float total = 0;
    for (int i = 0; i < m_Size; i++)
    {
        total += m_Dathuc[i].GetValue(var);
    }
    return total;
}

DaThuc& DaThuc::operator+=(const DaThuc& dt)
{
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
        }
        else if (m_Dathuc[i].GetDeg() < dt.m_Dathuc[j].GetDeg())
        {
            temp.push_back(dt.m_Dathuc[j]);
            ++j;
        }
        else
        {
            m_Dathuc[i] += dt.m_Dathuc[j];
            temp.push_back(m_Dathuc[i]);
            ++i;
            ++j;
        }
    }

    // store all remain
    while (i < m_Size)
    {
        temp.push_back(m_Dathuc[i]);
        ++i;
    }
    while (j < dt.m_Size)
    {
        temp.push_back(dt.m_Dathuc[j]);
        ++j;
    }

    // remove all zero don thuc in vector temp
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].GetCoeff() == 0)
        {
            temp.erase(temp.begin() + i);
        }
    }

    // copy temp to array
    if (m_Size != 0) { delete[] m_Dathuc; }
    m_Size = temp.size();
    m_Dathuc = new DonThuc[m_Size]();
    for (int i = 0; i < m_Size; i++)
    {
        m_Dathuc[i] = temp[i];
    }
    return *this;
}

DaThuc& DaThuc::operator-=(DaThuc dt)
{
    // negative all value of dt
    for (int i = 0; i < dt.m_Size; i++)
    {
        dt.m_Dathuc[i].Negative();
    }

    // A - B turn to A + (-B)
    *this += dt;

    return *this;
}

DaThuc& DaThuc::operator*=(const DaThuc& dt)
{
    int maxSize = this->m_Dathuc[0].GetDeg() + dt.m_Dathuc[0].GetDeg();
    DonThuc* temp = new DonThuc[maxSize + 1]();

    for (int i = 0; i < m_Size; i++)
    {
        for (int j = 0; j < dt.m_Size; j++)
        {
            DonThuc mul = m_Dathuc[i] * dt.m_Dathuc[j];

            int idx = maxSize - mul.GetDeg();

            if (temp[idx] != DonThuc::Zero) { temp[idx] += mul; }
            else                            { temp[idx] = mul; }
        }
    }

    // copy temp to array
    if (m_Size != 0) { delete[] m_Dathuc; }
    m_Size = maxSize + 1;
    m_Dathuc = temp;
    return *this;
}

DaThuc& DaThuc::operator/=(const DaThuc& dt)
{
    assert(dt.m_Dathuc[0].GetDeg() != 0);

    if (m_Dathuc[0].GetDeg() < dt.m_Dathuc[0].GetDeg())
    {
        delete[] m_Dathuc;
        m_Dathuc = new DonThuc[1]();
        return *this;
    }

    // Da thuc 0 (thuong)
    DaThuc q;
    // phan du = dt
    DaThuc r = *this;

    while (true)
    {
        if (r.m_Dathuc[0].GetDeg() < dt.m_Dathuc[0].GetDeg())
        {
            break;
        }

        DonThuc mul = r.m_Dathuc[0] / dt.m_Dathuc[0];
        DaThuc temp(mul);
        q += temp;
        r -= (temp * dt);
    }

    *this = q;
    return *this;
}

DaThuc& DaThuc::operator%=(const DaThuc& dt)
{
    assert(dt.m_Dathuc[0].GetDeg() != 0);

    if (m_Dathuc[0].GetDeg() < dt.m_Dathuc[0].GetDeg())
    {
        *this = dt;
        return *this;
    }

    // Da thuc 0 (thuong)
    DaThuc q;
    // phan du = dt
    DaThuc r = *this;

    while (true)
    {
        if (r.m_Dathuc[0].GetDeg() < dt.m_Dathuc[0].GetDeg())
        {
            break;
        }

        DonThuc mul = r.m_Dathuc[0] / dt.m_Dathuc[0];
        DaThuc temp(mul);
        q += temp;
        r -= (temp * dt);
    }

    *this = r;
    return *this;
}

void DaThuc::swap(DaThuc& dt1, DaThuc& dt2)
{
    using std::swap;
    swap(dt1.m_Size, dt2.m_Size);
    swap(dt1.m_Dathuc, dt2.m_Dathuc);
}

DaThuc& DaThuc::operator=(DaThuc dt)
{
    swap(*this, dt);
    return *this;
}
