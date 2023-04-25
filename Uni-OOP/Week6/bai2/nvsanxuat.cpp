#include "nvsanxuat.h"

NVSanXuat::NVSanXuat() // DONE
: NhanVien()
, m_ProductQuantity(0)
{
}

NVSanXuat::NVSanXuat(const NVSanXuat& sx) // DONE
: NhanVien(sx)
, m_ProductQuantity(sx.m_ProductQuantity)
{
}

NVSanXuat::~NVSanXuat() // DONE
{
}

NVSanXuat* NVSanXuat::Clone() const // DONE
{
	return new NVSanXuat(*this);
}

void NVSanXuat::Input() // DONE
{
	NhanVien::Input();
	std::cout << "Moi ban nhap so san pham: ";
	std::cin >> m_ProductQuantity;
}

void NVSanXuat::Output() // DONE
{
	std::cout << "La nhan vien san xuat \n";
	NhanVien::Output();
	std::cout << "So san pham: " << m_ProductQuantity << "\n";
}

void NVSanXuat::SetValue(int type, const char* val) // DONE
{
	switch (type)
	{
	case(5): // PRODUCT QUANTITY
		assert((m_ProductQuantity <= 15) && (m_ProductQuantity >= 10));
		m_ProductQuantity = std::atoi(val);
		break;

	default:
		NhanVien::SetValue(type, val);
		break;
	}
}

float NVSanXuat::GetSalary() const // DONE
{
	return NVSX_SALARY * m_ProductQuantity;
}
