#include "myqueue.h"

MyIntQueue::MyIntQueue(int cap)
: m_Capacity(cap)
{
	m_Queue.Reserve(cap);
}

bool MyIntQueue::Enqueue(int val)
{
	if (m_Queue.Size() < m_Capacity)
	{
		m_Queue.Push(val);
		return true;
	}
	return false;
}

bool MyIntQueue::Dequeue()
{
	if (m_Queue.Size() != 0)
	{
		m_Queue.Remove(0);
		return true;
	}
	return false;
}

bool MyIntQueue::isEmpty()
{
	return (m_Queue.Size() == 0);
}

int MyIntQueue::GetFront() const
{
	if (m_Queue.Size() == 0)
	{
		return -1;
	}
	return m_Queue[0];
}