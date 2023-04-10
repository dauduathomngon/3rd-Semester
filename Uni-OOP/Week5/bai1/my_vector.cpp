#include "my_vector.h"
template<typename T>
MyVector<T>::MyVector()
: m_Capacity(0)
: m_Size(0)
, m_Arr(nullptr)
{
}

template<typename T>
MyVector<T>::MyVector(int cap)
: m_Capacity(cap)
, m_Size(cap)
, m_Arr(new T[cap]())
{
}

template<typename T>
MyVector<T>::MyVector(const MyVector& mv)
: m_Size(mv.m_Size)
, m_Capacity(mv.m_Capacity)
{
    m_Arr = (m_Size != 0) ? new T[m_Size]() : nullptr;

    for (int i=0; i < m_Size; i++)
    {
        m_Arr[i] = mv.m_Arr[i];
    }
}

template<typename T>
MyVector<T>::~MyVector()
{
    delete[] m_Arr;
}

// reserve change capacity but not change size (if size > newalloc) change size too
template<typename T>
void MyVector<T>::reserve(int newalloc)
{
    if (m_Arr = nullptr)
    {
        m_Capacity = 0;
        m_Size = 0;
    }

    T* temp = new T[newalloc]();
    int newSize = newalloc < m_Size ? newalloc : m_Size;

    for (int i=0; i < newSize; i++)
    {
        temp[i] = m_Arr[i];
    }

    delete[] m_Arr;
    m_Arr = temp;
    m_Size = newSize;
    m_Capacity = newalloc;
}

template<typename T>
void MyVector<T>::push(const T& element)
{
    T* temp = new T[m_Size + 1]();

    // copy to temp vector
    for (int i=0; i < m_Size; i++)
    {
        temp[i] = m_Arr[i];
    }

    // add new element
    temp[m_Size] = element;

    // increase size
    ++m_Size;

    // increase capacity
    int newCap = m_Size > m_Capacity ? m_Size : m_Capacity;
    m_Capacity = newCap;

    // change m_Arr
    delete[] m_Arr;
    m_Arr = temp;
}

template<typename T>
void MyVector<T>::print()
{
    for (int i=0; i < m_Size; i++) 
    {
        std::cout << m_Arr[i] << " ";
    }
    std::cout << "\n";
}

template<typename T>
const T& MyVector<T>::operator[](int idx) const
{ 
    return m_Arr[idx];
}

template<typename T>
T& MyVector<T>::operator[](int idx)
{
    return m_Arr[idx];
}
