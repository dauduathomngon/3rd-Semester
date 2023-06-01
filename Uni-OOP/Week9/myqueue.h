#pragma once
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include "myvector.h"

class MyIntQueue
{
public:
	MyIntQueue(int cap);

	bool Enqueue(int val);
	bool Dequeue();

	bool isEmpty();

	int GetFront() const;
private:
	MyVector<int> m_Queue;
	int m_Capacity;
};

#endif // MYQUEUE_H