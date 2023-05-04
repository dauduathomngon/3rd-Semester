#include "nvcongnhat.h"

NVCongNhat::NVCongNhat() // DONE
	: NhanVien()
	, m_NumberOfDays(0)
{
}

NVCongNhat::NVCongNhat(const NVCongNhat& cn) // DONE
	: NhanVien(cn)
	, m_NumberOfDays(cn.m_NumberOfDays)
{
}

NVCongNhat::~NVCongNhat() // DONE
{
}

NVCongNhat* NVCongNhat::Clone() const // DONE
{
	return new NVCongNhat(*this);
}

void NVCongNhat::Input() // DONE
{
	NhanVien::Input();
	do
	{
		std::cout << "Moi ban nhap so ngay lam viec (so ngay lam viec nam trong khoang 20 -> 26 ngay): ";
		std::cin >> m_NumberOfDays;
	} while (m_NumberOfDays < 20 || m_NumberOfDays > 26);
}

void NVCongNhat::Output() // DONE
{
	std::cout << "------------------------\n";
	std::cout << "La nhan vien cong nhat \n";
	NhanVien::Output();
	std::cout << "So ngay lam: " << m_NumberOfDays << "\n";
	std::cout << "------------------------\n";
}

//void NVCongNhat::SetValue(int type, const char* val) // DONE
//{
//	switch (type)
//	{
//	case(5): // NUM OF DAYS
//		m_NumberOfDays = std::atoi(val);
//		assert(m_NumberOfDays >= 22 && m_NumberOfDays <= 26);
//		break;
//
//	default:
//		NhanVien::SetValue(type, val);
//		break;
//	}
//}

float NVCongNhat::GetSalary() const // DONE
{
	return NVCN_SALARY * m_NumberOfDays;
}

char* NVCongNhat::GetType() const
{
	char* type = new char[10]();
	strcpy_s(type, 10, "cong nhat");
	return type;
}
