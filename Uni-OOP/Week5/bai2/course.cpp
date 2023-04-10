#include "course.h"

Course::Course()
: m_ID(nullptr)
, m_Name(nullptr)
, m_StartDate(nullptr)
, m_Roster(nullptr)
{
}

Course::~Course()
{
	delete[] m_ID;
	delete[] m_Name;
	delete[] m_StartDate;
	delete m_Roster;
}

Course::Course(const Course& cs)
: m_ID(nullptr)
, m_Name(nullptr)
, m_StartDate(nullptr)
, m_Roster(nullptr)
{
	if (strlen(cs.m_ID) != 0)
	{
		m_ID = new char[strlen(cs.m_ID) + 1]();
		strcpy_s(m_ID, strlen(cs.m_ID) + 1, cs.m_ID);
	}

	if (strlen(cs.m_Name) != 0)
	{
		m_Name = new char[strlen(cs.m_Name) + 1]();
		strcpy_s(m_Name, strlen(cs.m_Name) + 1, cs.m_Name);
	}

	if (strlen(cs.m_StartDate) != 0)
	{
		m_StartDate = new char[strlen(cs.m_StartDate) + 1]();
		strcpy_s(m_StartDate, strlen(cs.m_StartDate) + 1, cs.m_StartDate);
	}

	// copy roster
	m_Roster = cs.m_Roster->Clone();
}

Course& Course::operator=(Course other)
{
	swap(*this, other);
	return *this;
}

Roster* Course::GetRoster()
{
	return m_Roster;
}

char* Course::GetName() const
{
	return m_Name;
}

void Course::InitRoster()
{
	if (m_Roster != nullptr)
	{
		delete m_Roster;
	}
	m_Roster = new Roster();
}

void Course::SetValue(const char* var, int type)
{
	switch (type)
	{
	case(0): // ID
	{
		if (strlen(var) != 0)
		{
			delete[] m_ID;
			m_ID = new char[strlen(var) + 1]();
			strcpy_s(m_ID, strlen(var) + 1, var);
		}
		break;
	}
	case(1): // name
	{
		if (strlen(var) != 0)
		{
			delete[] m_Name;
			m_Name = new char[strlen(var) + 1]();
			strcpy_s(m_Name, strlen(var) + 1, var);
		}
		break;
	}
	case(2): // start date
	{
		if (strlen(var) != 0)
		{
			delete[] m_StartDate;
			m_StartDate = new char[strlen(var) + 1]();
			strcpy_s(m_StartDate, strlen(var) + 1, var);
		}
		break;
	}
	default:
		m_Roster->AddStudent(var);
		break;
	}
}

void Course::Print()
{
	std::cout << "Ma so: " << m_ID << "\n";
	std::cout << "Ten: " << m_Name << "\n";
	std::cout << "Ngay bat dau: " << m_StartDate << "\n";
	m_Roster->Print();
}

void swap(Course& cs1, Course& cs2)
{
	using std::swap;
	swap(cs1.m_ID, cs2.m_ID);
	swap(cs1.m_Name, cs2.m_Name);
	swap(cs1.m_StartDate, cs2.m_StartDate);
	swap(cs1.m_Roster, cs2.m_Roster);
}
