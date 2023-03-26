#ifndef MY_INT_ARRAY_H
#define MY_INT_ARRAY_H

#include <iostream>
#include <cassert>

class MyIntArray
{
public:
    MyIntArray();

    MyIntArray(int sz);

    ~MyIntArray();

    int& operator[](int idx);

    MyIntArray(const MyIntArray& arr);

    MyIntArray& operator=(const MyIntArray& other);

    void Input();

    void Print();
private:
    int* m_pArr;
    int m_Size;
};

#endif // MY_ARRAY_H