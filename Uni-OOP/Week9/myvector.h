#pragma once
#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <stdexcept>
#include <algorithm>
#include <iostream>

template<typename T>
class MyVector
{
public:
	MyVector();
	MyVector(int capacity);
	~MyVector();	

	/* Expand extra memory */
	void Reserve(int newMalloc);

	/* Operator [] */
	T& operator[](int idx);
	const T& operator[](int idx) const;

	void Push(const T& element);
	/*void Insert(const T& element, int idx);*/
	void Remove(int idx);

	void Print();
	void Clear();

	int Size() const;
	int Capacity() const;

private:
	T* m_Arr;
	int m_Size;
	int m_Capacity;
};

#endif // MYVECTOR_H

template<typename T>
inline MyVector<T>::MyVector()
	: m_Size(0)
	, m_Capacity(0)
	, m_Arr(nullptr)
{
}

template<typename T>
inline MyVector<T>::MyVector(int capacity)
	: m_Capacity(capacity)
	, m_Size(0)
{
	m_Arr = (m_Capacity != 0) ? new T[m_Capacity]() : nullptr;
}

template<typename T>
inline MyVector<T>::~MyVector()
{
	delete[] m_Arr;
}

template<typename T>
inline void MyVector<T>::Reserve(int newMalloc)
{
	if (newMalloc <= m_Capacity)
	{
		std::cout << "Can't reserve size less or equal than current capacity \n";
		return;
	}

	m_Capacity = newMalloc;
	T* temp = new T[m_Capacity]();

	for (int i = 0; i < m_Size; i++)
	{
		temp[i] = m_Arr[i];
	}

	delete[] m_Arr;
	m_Arr = temp;
}

template<typename T>
inline T& MyVector<T>::operator[](int idx)
{
	return m_Arr[idx];
}

template<typename T>
inline const T& MyVector<T>::operator[](int idx) const
{
	return m_Arr[idx];
}

template<typename T>
inline void MyVector<T>::Push(const T& element)
{
	if (m_Size == m_Capacity)
	{
		Reserve(m_Capacity + 1);
		m_Capacity++;
	}

	m_Arr[m_Size] = element;
	m_Size++;
}

template<typename T>
inline void MyVector<T>::Print()
{
	for (int i = 0; i < m_Size; i++)
	{
		std::cout << m_Arr[i] << " ";
	}
	std::cout << "\n";
}

//template<typename T>
//inline void MyVector<T>::Insert(const T& element, int idx)
//{
//	if (m_Size == m_Capacity)
//	{
//		std::cout << "Vector overflow \n"
//			<< "Please use Reserve method to expand the capacity \n";
//		return;
//	}
//
//	if (idx == m_Size)
//	{
//		Push(element);
//		return;
//	}
//
//	T* temp = new T[m_Capacity]();
//	for (int i = 0; i < m_Size; i++) // copy array
//	{
//		temp[i] = m_Arr[i];
//	}
//	for (int i = idx; i < m_Size; i++) // add element
//	{
//		temp[i + 1] = temp[i];
//	}
//	temp[idx] = element;
//
//	m_Size++;
//	delete[] m_Arr;
//	m_Arr = temp;
//}

template<typename T>
inline void MyVector<T>::Remove(int idx)
{	
	T* temp = new T[m_Capacity]();

	for (int i = idx; i < m_Size - 1; i++)
	{
		std::swap(m_Arr[i], m_Arr[i + 1]);
	}

	for (int i = 0; i < m_Size - 1; i++)
	{
		temp[i] = m_Arr[i];
	}

	m_Size--;
	delete[] m_Arr;
	m_Arr = temp;
}

template<typename T>
inline void MyVector<T>::Clear()
{
	T* temp = new T[m_Capacity]();
	delete[] m_Arr;
	m_Arr = temp;
	m_Size = 0;
}

template<typename T>
inline int MyVector<T>::Size() const
{
	return m_Size;
}

template<typename T>
inline int MyVector<T>::Capacity() const
{
	return m_Capacity;
}
