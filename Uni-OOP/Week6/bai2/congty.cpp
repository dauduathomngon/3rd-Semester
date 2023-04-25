#include "congty.h"

CongTy::CongTy() // DONE
: m_DanhSach(nullptr)
, m_Size(0)
{
}

CongTy::CongTy(const CongTy& ct) // DONE
: m_Size(ct.m_Size)
, m_DanhSach(nullptr)
{
	if (m_Size != 0)
	{
		m_DanhSach = new NhanVien * [m_Size]();
		for (int i = 0; i < m_Size; i++)
		{
			m_DanhSach[i] = ct.m_DanhSach[i]->Clone();
		}
	}
}

CongTy::~CongTy() // DONE
{
	Delete();
}

CongTy& CongTy::operator=(CongTy other) // DONE
{
	swap(*this, other);
	return *this;
}

void CongTy::WriteToFile() // TODO
{
}

void CongTy::ReadFromFile() // TODO
{
}

void CongTy::WriteBelowAvg() // TODO
{
}

void CongTy::OutputListEmployee() // TODO
{
}

void CongTy::FindHighestSalary() // TODO
{
}

void CongTy::FindID(const char* ID) // TODO
{
}

void CongTy::FindName(const char* name) // TODO
{
}

void CongTy::FindMonth(int month) // TODO
{
}

void CongTy::AddEmployee() // TODO
{
}

void CongTy::RemoveEmployee() // TODO
{
}

float CongTy::GetTotalSalary() const // TODO
{
	return 0.0f;
}

float CongTy::GetAvgSalary() const // TODO
{
	return 0.0f;
}

float CongTy::GetHighestSalary() const // TODO
{
	return 0.0f;
}

void CongTy::Delete() // DONE
{
	for (int i = 0; i < m_Size; i++)
	{
		delete m_DanhSach[i];
	}
	delete[] m_DanhSach;
}

void swap(CongTy& ct1, CongTy& ct2) // DONE
{
	using std::swap;
	swap(ct1.m_Size, ct2.m_Size);
	swap(ct1.m_DanhSach, ct2.m_DanhSach);
}
