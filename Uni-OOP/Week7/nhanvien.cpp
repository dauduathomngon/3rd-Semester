#include "nhanvien.h"

NhanVien::NhanVien() // DONE
	: m_ID(nullptr)
	, m_Name(nullptr)
	, m_Birthday(nullptr)
	, m_Address(nullptr)
	, m_Gender(nullptr)
{
}

NhanVien::NhanVien(const NhanVien& nv) // DONE
	: m_ID(nullptr)
	, m_Name(nullptr)
	, m_Birthday(nullptr)
	, m_Address(nullptr)
	, m_Gender(nullptr)
{
	SetString(m_ID, nv.m_ID);
	SetString(m_Name, nv.m_Name);
	SetString(m_Birthday, nv.m_Birthday);
	SetString(m_Address, nv.m_Address);
	SetString(m_Gender, nv.m_Gender);
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
	InputString(m_ID, 0);
	InputString(m_Name, 1);
	InputString(m_Gender, 2);
	InputString(m_Address, 3);
	InputString(m_Birthday, 4);
}

void NhanVien::Output() // DONE
{
	std::cout << "Gioi tinh nhan vien: " << m_Gender << "\n";
	std::cout << "Ma nhan vien: " << m_ID << "\n";
	std::cout << "Ten nhan vien: " << m_Name << "\n";
	std::cout << "Ngay sinh cua nhan vien: " << m_Birthday << "\n";
	std::cout << "Dia chi cua nhan vien: " << m_Address << "\n";
	std::cout << "Tuoi cua nhan vien: " << FindAge() << "\n";
}

//void NhanVien::SetValue(int type, const char* val) // DONE
//{
//	assert(strlen(val) > 0);
//
//	switch (type)
//	{
//	case(0): // ID
//	{
//		assert(strlen(val) <= 5);
//		SetString(m_ID, val);
//		break;
//	}
//	case(1): // NAME
//	{
//		SetString(m_Name, val);
//		break;
//	}
//	case(2): // GENDER
//	{
//		SetString(m_Gender, val);
//		break;
//	}
//	case(3): // ADDRESS
//	{
//		SetString(m_Address, val);
//		break;
//	}
//	case(4): // BIRTHDAY
//	{
//		SetString(m_Birthday, val);
//		assert(CheckAge() == true);
//		break;
//	}
//	default:
//		break;
//	}
//}

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

int NhanVien::GetMonthOfBirth() const
{
	// 17/07/2003
	char* month = new char[3]();
	for (int i = 3; i < strlen(m_Birthday) - 5; i++)
	{
		month[i-3] = m_Birthday[i];
	}
	
	int monthInt = std::atoi(month);
	return monthInt;
}

int NhanVien::GetAge() const // DONE
{
	return FindAge();
}

char* NhanVien::GetType() const
{
	return nullptr;
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

void NhanVien::InputString(char*& des, int type) // DONE
{
	if (des != nullptr)
	{
		delete[] des;
	}
	des = new char[MAX_LEN + 1]();

	switch (type)
	{
	case(0):
	{
		bool isTrying = true;
		while (isTrying)
		{
			std::cout << "Moi ban nhap ID cua nhan vien (toi da 5 ki tu): ";
			try
			{
				std::cin.getline(des, MAX_LEN);
				if (strlen(des) > 5)
				{
					throw InputException("Vuot qua gioi han ky tu cua ID nhan vien");
				}
				else
				{
					isTrying = false;
				}
			}
			catch (const InputException& err)
			{
				std::cout << err.what() << std::endl;
			}
		}

		break;
	}
	case(1):
	{
		std::cout << "Moi ban nhap ten cua nhan vien: ";
		std::cin.getline(des, MAX_LEN);
		break;
	}
	case(2):
	{
		std::cout << "Moi ban nhap gioi tinh cua nhan vien: ";
		std::cin.getline(des, MAX_LEN);
		break;
	}
	case(3):
	{
		std::cout << "Moi ban nhap dia chi cua nhan vien: ";
		std::cin.getline(des, MAX_LEN);
		break;
	}
	case(4):
	{
		int maxAge = 0;
		int minAge = 0;

		if (strcmp(m_Gender, "nam") == 0)
		{
			std::cout << "Do la nhan vien nam nen tuoi nhan vien tu 18 -> 60 tuoi \n";
			maxAge = 60;
			minAge = 18;
		}
		else
		{
			std::cout << "Do la nhan vien nu nen tuoi nhan vien tu 18 -> 55 tuoi \n";
			maxAge = 60;
			minAge = 18;
		}

		/*do
		{
			std::cout << "Moi ban nhap ngay sinh cua nhan vien (vi du 27/06/2003): ";
			std::cin.getline(des, MAX_LEN);
		} while (CheckAge() == false);*/

		bool isTrying = true;

		while (isTrying)
		{
			std::cout << "Moi ban nhap ngay sinh cua nhan vien (vi du 27/06/2003): ";
			try
			{
				std::cin.getline(des, MAX_LEN);

				if (FindAge() < minAge)
				{
					throw InputException("Duoi " + std::to_string(minAge) + " tuoi, khong hop le");
				}

				else if (FindAge() > maxAge)
				{
					throw InputException("Vuot qua " + std::to_string(maxAge) + " tuoi, khong hop le");
				}

				else
				{
					isTrying = false;
				}
			}
			catch (const InputException& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	default:
		break;
	}
}

bool NhanVien::CheckAge() // DONE
{
	if (strcmp(m_Gender, "nam") == 0) // nam
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
