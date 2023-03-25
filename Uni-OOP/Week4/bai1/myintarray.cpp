#include "myintarray.h"

MyIntArray::MyIntArray()
: m_Size(0)
, m_pArr(nullptr)
{
}

MyIntArray::MyIntArray(int sz)
: m_Size(sz)
, m_pArr(m_Size != 0 ? new int[sz]() : nullptr)
{
}

MyIntArray::~MyIntArray()
{
    delete[] m_pArr; 
}

MyIntArray::MyIntArray(const MyIntArray& arr)
: m_Size(arr.m_Size)
, m_pArr(m_Size != 0 ? new int[m_Size]() : nullptr)
{
    for (int i=0; i < m_Size; i++)
    {
        m_pArr[i] = arr.m_pArr[i];
    }
}

MyIntArray& MyIntArray::operator=(const MyIntArray& other)
{
    if (this == &other) { return *this; }
    if (m_Size != 0) { delete[] m_pArr; }

    // copy size
    m_Size = other.m_Size; 
    // copy whole array
    m_pArr = new int[m_Size]();
    for (int i=0; i < m_Size; i++)
    {
        m_pArr[i] = other.m_pArr[i];
    }

    return *this; 
}

void MyIntArray::Input()
{
    int n = 0;
    std::cout << "Moi ban nhap so luong phan tu trong array (lon hon 0): ";
    std::cin >> n;

    if (m_Size != 0) { delete[] m_pArr; }

    m_Size = n;
    m_pArr = new int[m_Size]();

    for (int i=0; i < m_Size; i++)
    {
        std::cout << "Moi ban nhap gia tri cho array: c: ";
        std::cin >> m_pArr[i];
    }
}

void MyIntArray::Print()
{
    for (int i=0; i < m_Size; i++) 
    {
        std::cout << m_pArr[i] << " ";
    }
    std::cout << std::endl;
}

int& MyIntArray::operator[](int idx)
{
    assert(idx >= 0 && idx < m_Size);
    return m_pArr[idx];
}
