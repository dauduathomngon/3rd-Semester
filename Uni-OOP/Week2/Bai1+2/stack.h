#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack
{
public:
    Stack(int capacity);

    ~Stack();

    void push(const int& element);

    int pop();
private:
    int *m_Ptr;
    int m_Capacity;
    int m_Size;
};

#endif // STACK_H