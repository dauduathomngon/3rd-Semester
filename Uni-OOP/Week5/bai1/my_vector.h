#pragma once
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
#include <string>

template<typename T>
class MyVector
{
public:
    MyVector();
    MyVector(int cap);
    MyVector(const MyVector& mv);
    ~MyVector();

    T& operator[](int idx);
    const T& operator[](int idx) const;

    void reserve(int newalloc);

    void push(const T& element);
    void print();

private:
    T* m_Arr;
    int m_Capacity;
    int m_Size;
};

#endif // MY_VECTOR_H