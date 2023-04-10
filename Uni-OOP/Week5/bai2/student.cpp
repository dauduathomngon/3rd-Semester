#include "student.h"

Student::Student()
: m_ID(nullptr)
, m_Name(nullptr)
, m_Address(nullptr)
, m_Birthday(nullptr)
, m_Schedule(nullptr)
{
}

Student::~Student()
{
	delete[] m_ID;
	delete[] m_Name;
	delete[] m_Address;
	delete[] m_Birthday;
	delete m_Schedule;
}

Student::Student(const Student& st)
: m_ID(nullptr)
, m_Name(nullptr)
, m_Address(nullptr)
, m_Birthday(nullptr)
, m_Schedule(nullptr)
{
	if (strlen(st.m_ID) != 0)
	{
		m_ID = new char[strlen(st.m_ID) + 1]();
		strcpy_s(m_ID, strlen(st.m_ID) + 1, st.m_ID);
	}

	if (strlen(st.m_Name) != 0)
	{
		m_Name = new char[strlen(st.m_Name) + 1]();
		strcpy_s(m_Name, strlen(st.m_Name) + 1, st.m_Name);
	}

	if (strlen(st.m_Address) != 0)
	{
		m_Address = new char[strlen(st.m_Address) + 1]();
		strcpy_s(m_Address, strlen(st.m_Address) + 1, st.m_Address);
	}

	if (strlen(st.m_Birthday) != 0)
	{
		m_Birthday = new char[strlen(st.m_Birthday) + 1]();
		strcpy_s(m_Birthday, strlen(st.m_Birthday) + 1, st.m_Birthday);
	}

	// copy schedule
	m_Schedule = st.m_Schedule->Clone();
}

Student& Student::operator=(Student other)
{
	swap(*this, other);
	return *this;
}

Schedule* Student::GetSchedule()
{
	return m_Schedule;
}

char* Student::GetName() const
{
	return m_Name;
}

void Student::InitSchedule()
{
	if (m_Schedule != nullptr)
	{
		delete m_Schedule;
	}
	m_Schedule = new Schedule();
}

void Student::SetValue(const char* var, int type)
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
	case(2): // address
	{
		if (strlen(var) != 0)
		{
			delete[] m_Address;
			m_Address = new char[strlen(var) + 1]();
			strcpy_s(m_Address, strlen(var) + 1, var);
		}
		break;
	}
	case(3): // date
	{
		if (strlen(var) != 0)
		{
			delete[] m_Birthday;
			m_Birthday = new char[strlen(var) + 1]();
			strcpy_s(m_Birthday, strlen(var) + 1, var);
		}
		break;
	}
	default:
		m_Schedule->AddCourse(var);
		break;
	}
}

void Student::Print()
{
	std::cout << "Ma so: " << m_ID << "\n";
	std::cout << "Ten: " << m_Name << "\n";
	std::cout << "Dia chi: " << m_Address << "\n";
	std::cout << "Ngay sinh: " << m_Birthday << "\n";
	m_Schedule->Print();
}

void swap(Student& st1, Student& st2)
{
	using std::swap;
	swap(st1.m_ID, st2.m_ID);
	swap(st1.m_Name, st2.m_Name);
	swap(st1.m_Address, st2.m_Address);
	swap(st1.m_Birthday, st2.m_Birthday);
	swap(st1.m_Schedule, st2.m_Schedule);
}

std::ostream& operator<<(std::ostream& os, const Student& st)
{
	os << st.m_ID << " | "
		<< st.m_Name << " | "
		<< st.m_Address << " | "
		<< st.m_Birthday << " | ";

	int size = st.m_Schedule->GetSize();

	for (int i = 0; i < size - 1; i++)
	{
		os << st.m_Schedule->GetStudentName(i) << ",";
	}
	os << st.m_Schedule->GetStudentName(size - 1) << "\n";

	return os;
}