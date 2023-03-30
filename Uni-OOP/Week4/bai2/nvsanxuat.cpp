#include "nvsanxuat.h"

NVSanXuat::NVSanXuat()
: m_SanPham(0)
{
}

NVSanXuat::NVSanXuat(const NVSanXuat& sx)
: m_SanPham(sx.m_SanPham)
, NhanVien(sx)
{
}

NVSanXuat* NVSanXuat::Clone() const
{
	return new NVSanXuat(*this);
}

float NVSanXuat::GetSalary() const
{
	return (m_SanPham * NVSX_LUONG);
}

void NVSanXuat::Input()
{
	std::cin.ignore();

	std::cout << "Moi ban nhap ID: ";
	getline(std::cin, m_ID);

	std::cout << "Moi ban nhap ten: ";
	getline(std::cin, m_Ten);

	std::cout << "Moi ban nhap ngay sinh (vi du 18/07/2003): ";
	getline(std::cin, m_NgaySinh);

	std::cout << "Moi ban nhap dia chi (vi du Thu Duc, TP HCM): ";
	getline(std::cin, m_DiaChi);

	std::cout << "Moi ban nhap so san pham: ";
	std::cin >> m_SanPham;
}

void NVSanXuat::Output()
{
	std::cout << "Nhan vien san xuat \n";
	std::cout << "ID: " << m_ID << "\n";
	std::cout << "Ten: " << m_Ten << "\n";
	std::cout << "Ngay sinh: " << m_NgaySinh << "\n";
	std::cout << "Dia chi: " << m_DiaChi << "\n";
	std::cout << "So san pham: " << m_SanPham << "\n";
}
