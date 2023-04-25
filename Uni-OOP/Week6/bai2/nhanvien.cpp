#include "nhanvien.h"

NhanVien::NhanVien() // DONE
: m_ID(nullptr)
, m_Name(nullptr)
, m_Birthday(nullptr)
, m_Address(nullptr)
, m_Gender(-1)
{
}

NhanVien::NhanVien(const NhanVien& nv) // DONE
: m_ID(nullptr)
, m_Name(nullptr)
, m_Birthday(nullptr)
, m_Address(nullptr)
, m_Gender(nv.m_Gender)
{
	SetString(m_ID, nv.m_ID);
	SetString(m_Name, nv.m_Name);
	SetString(m_Birthday, nv.m_Birthday);
	SetString(m_Address, nv.m_Address);
}

NhanVien::~NhanVien() // DONE
{
	delete[] m_ID;
	delete[] m_Name;
	delete[] m_Birthday;
	delete[] m_Address;
}

NhanVien* NhanVien::Clone() const // DONE
{
	return new NhanVien(*this);
}

void NhanVien::Input() // DONE
{
	// TODO
}

void NhanVien::Output()
{
	const char* gender = (m_Gender == 0) ? "nam" : "nu";

	std::cout << "La nhan vien " << gender << "\n";
	std::cout << "Ma nhan vien: " << m_ID << "\n";
	std::cout << "Ten nhan vien: " << m_Name << "\n";
	std::cout << "Ngay sinh cua nhan vien: " << m_Birthday << "\n";
	std::cout << "Dia chi cua nhan vien: " << m_Address << "\n";
	std::cout << "Tuoi cua nhan vien: " << FindAge() << "\n";
}

void NhanVien::SetValue(int type, const char* val) // DONE
{
	assert(strlen(val) > 0);

	switch (type)
	{
	case(0): // ID
	{
		assert(strlen(val) <= 5);
		SetString(m_ID, val);
		break;
	}
	case(1): // NAME
	{
		SetString(m_Name, val);
		break;
	}
	case(2): // GENDER
	{
		m_Gender = std::atoi(val);
		break;
	}
	case(3): // ADDRESS
	{
		SetString(m_Address, val);
		break;
	}
	case(4): // BIRTHDAY
	{
		SetString(m_Birthday, val);
		assert(CheckAge() == true);
		break;
	}
	default:
		break;
	}
}

float NhanVien::GetSalary() const // DONE
{
	return 0.0f;
}

char* NhanVien::GetID() const // DONE
{
	return m_ID;
}

char* NhanVien::GetName() const //DONE
{
	return m_Name;
}

char* NhanVien::GetMonthOfBirth() const
{
	// TODO
	return nullptr;
}

int NhanVien::GetAge() const // DONE
{
	return FindAge();
}

void NhanVien::SetString(char*& des, const char* src) // DONE
{
	if (des != nullptr)
	{
		delete[] des;
	}

	if (strlen(src) != 0)
	{
		des = new char[strlen(src) + 1]();
		strcpy_s(des, strlen(src) + 1, src);
	}
}

bool NhanVien::CheckAge() // DONE
{
	if (m_Gender == 0) // nam
	{
		return (FindAge() <= 60) && (FindAge() >= 18);
	}
	else // nu
	{
		return (FindAge() <= 55) && (FindAge() >= 18);
	}
}

int NhanVien::FindAge() const // DONE
{
	int todayYear = std::stoi(GetCurrentYear());
	
	char* year = new char[5]();
	for (int i = 6; i < strlen(m_Birthday); i++)
	{
		year[i - 6] = m_Birthday[i];
	}
	int birthYear = std::atoi(year);

	return todayYear - birthYear;
}
