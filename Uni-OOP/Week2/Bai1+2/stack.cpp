#include "stack.h"

Stack::Stack(int capacity)
: m_Capacity(capacity)
, m_Size(1)
, m_Ptr(new int[capacity]())
{
}

Stack::~Stack()
{
    delete[] m_Ptr; 
}

void Stack::push(const int& element)
{
    if (m_Size == m_Capacity)
    {
        std::cout << "Overflow \n";
        return;
    }
    ++m_Size;
    m_Ptr[m_Size - 1] = element;
}

int Stack::pop()
{
    if (m_Size == 0) 
    {
        std::cout << "Underflow \n";
        return;
    }
    --m_Size;
    return m_Ptr[m_Size];
}