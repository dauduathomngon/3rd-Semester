#include "roster.h"

Roster::Roster()
: m_StudentsName(nullptr)
, m_Size(0)
{
}

Roster::~Roster()
{
	Delete();
}

Roster::Roster(const Roster& rt)
: m_Size(rt.m_Size)
{
	m_StudentsName = (m_Size != 0) ? new char* [m_Size]() : nullptr;

	// copy array
	for (int i = 0; i < m_Size; i++)
	{
		m_StudentsName[i] = new char[strlen(rt.m_StudentsName[i]) + 1]();
		strcpy_s(m_StudentsName[i], strlen(rt.m_StudentsName[i]) + 1, rt.m_StudentsName[i]);
	}
}

Roster* Roster::Clone() const
{
	return new Roster(*this);
}

void Roster::AddStudent(const char* name)
{
	// create temp arr
	char** temp = new char* [m_Size + 1]();
	for (int i = 0; i < m_Size; i++)
	{
		temp[i] = new char[strlen(m_StudentsName[i]) + 1]();
	}
	temp[m_Size] = new char[strlen(name) + 1]();

	// copy to temp
	for (int i = 0; i < m_Size; i++)
	{
		strcpy_s(temp[i], strlen(m_StudentsName[i]) + 1, m_StudentsName[i]);
	}
	strcpy_s(temp[m_Size], strlen(name) + 1, name);

	// create new array
	Delete();
	m_Size++;
	m_StudentsName = temp;
}

int Roster::GetSize() const
{
	return m_Size;
}

void Roster::Print()
{
	std::cout << "Cac hoc sinh da dang ky khoa hoc: \n";
	for (int i = 0; i < m_Size; i++)
	{
		std::cout << i + 1 << ". " << m_StudentsName[i] << "\n";
	}
}

void Roster::Delete()
{
	for (int i = 0; i < m_Size; i++)
	{
		delete[] m_StudentsName[i];
	}
	delete[] m_StudentsName;
}
