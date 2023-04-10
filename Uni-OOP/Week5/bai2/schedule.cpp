#include "schedule.h"

Schedule::Schedule()
: m_CoursesName(nullptr)
, m_Size(0)
{
}

Schedule::~Schedule()
{
	Delete();
}

Schedule::Schedule(const Schedule& sc)
: m_Size(sc.m_Size)
{
	m_CoursesName = (m_Size != 0) ? new char* [m_Size]() : nullptr;

	// copy array
	for (int i = 0; i < m_Size; i++)
	{
		m_CoursesName[i] = new char[strlen(sc.m_CoursesName[i]) + 1]();
		strcpy_s(m_CoursesName[i], strlen(sc.m_CoursesName[i]) + 1, sc.m_CoursesName[i]);
	}
}

Schedule* Schedule::Clone() const
{
	return new Schedule(*this);
}

bool Schedule::AddCourse(const char* name)
{
	// find course before add
	for (int i = 0; i < m_Size; i++)
	{
		if (strcmp(name, m_CoursesName[i]) == 0)
		{
			std::cout << "Khoa hoc da dang ky roi \n";
			return false;
		}
	}

	// create temp arr
	char** temp = new char* [m_Size + 1]();
	for (int i = 0; i < m_Size; i++)
	{
		temp[i] = new char[strlen(m_CoursesName[i]) + 1]();
	}
	temp[m_Size] = new char[strlen(name) + 1]();

	// copy to temp
	for (int i = 0; i < m_Size; i++)
	{
		strcpy_s(temp[i], strlen(m_CoursesName[i]) + 1, m_CoursesName[i]);
	}
	strcpy_s(temp[m_Size], strlen(name) + 1, name);

	// create new array
	Delete();
	m_Size++;
	m_CoursesName = temp;

	return true;
}

int Schedule::GetSize() const
{
	return m_Size;
}

void Schedule::Print()
{
	std::cout << "Cac khoa hoc da dang ky: \n";
	for (int i = 0; i < m_Size; i++)
	{
		std::cout << i+1 << ". " << m_CoursesName[i] << "\n";
	}
}

char* Schedule::GetStudentName(int idx) const
{
	return m_CoursesName[idx];
}

void Schedule::Delete()
{
	for (int i = 0; i < m_Size; i++)
	{
		delete[] m_CoursesName[i];
	}
	delete[] m_CoursesName;
}
