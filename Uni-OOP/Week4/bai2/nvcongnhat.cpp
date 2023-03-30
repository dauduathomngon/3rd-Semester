#include "nvcongnhat.h"

NVCongNhat::NVCongNhat()
: m_SoNgay(0)
{
}

NVCongNhat::NVCongNhat(const NVCongNhat& cn)
: m_SoNgay(cn.m_SoNgay)
, NhanVien(cn)
{
}

NVCongNhat* NVCongNhat::Clone() const
{
	return new NVCongNhat(*this);
}

float NVCongNhat::GetSalary() const
{
	return (m_SoNgay * NVCN_LUONG);
}

void NVCongNhat::Input()
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

	std::cout << "Moi ban nhap so ngay di lam cua nhan vien: ";
	std::cin >> m_SoNgay;
}

void NVCongNhat::Output()
{
	std::cout << "Nhan vien cong nhat \n";
	std::cout << "ID: " << m_ID << "\n";
	std::cout << "Ten: " << m_Ten << "\n";
	std::cout << "Ngay sinh: " << m_NgaySinh << "\n";
	std::cout << "Dia chi: " << m_DiaChi << "\n";
	std::cout << "So ngay lam: " << m_SoNgay << "\n";
}
