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
	/*do
	{
		std::cout << "Moi ban nhap so san pham (so san pham hop le la tu 10 cho den 15): ";
		std::cin >> m_ProductQuantity;
	} while (m_ProductQuantity < 10 || m_ProductQuantity > 15);*/

	bool isTrying = true;
	while (isTrying)
	{
		std::cout << "Moi ban nhap so san pham (so san pham hop le la tu 10 cho den 15): ";
		try
		{
			std::cin >> m_ProductQuantity;
			
			if (m_ProductQuantity < 10)
			{
				throw InputException("So luong san pham it hon 10");
			}
			else if (m_ProductQuantity > 15)
			{
				throw InputException("So luong san pham lon hon 15");
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

void NVSanXuat::Output() // DONE
{
	std::cout << "------------------------\n";
	std::cout << "La nhan vien san xuat \n";
	NhanVien::Output();
	std::cout << "So san pham: " << m_ProductQuantity << "\n";
	std::cout << "------------------------\n";
}

//void NVSanXuat::SetValue(int type, const char* val) // DONE
//{
//	switch (type)
//	{
//	case(5): // PRODUCT QUANTITY
//		m_ProductQuantity = std::atoi(val);
//		break;
//
//	default:
//		NhanVien::SetValue(type, val);
//		break;
//	}
//}

float NVSanXuat::GetSalary() const // DONE
{
	return NVSX_SALARY * m_ProductQuantity;
}

char* NVSanXuat::GetType() const
{
	char* type = new char[9]();
	strcpy_s(type, 9, "san xuat");
	return type;
}
