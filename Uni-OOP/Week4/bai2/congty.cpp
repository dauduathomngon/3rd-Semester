#include "congty.h"

CongTy::CongTy()
: m_DanhSachNV(nullptr)
, m_Size(0)
{
}

CongTy::CongTy(const CongTy& ct)
: m_Size(ct.m_Size)
{
	m_DanhSachNV = (m_Size != 0) ? new NhanVien * [m_Size]() : nullptr;

	for (int i = 0; i < m_Size; i++)
	{
		m_DanhSachNV[i] = ct.m_DanhSachNV[i]->Clone();
	}
}

CongTy::~CongTy()
{
	Delete();
}

CongTy& CongTy::operator=(CongTy other)
{
	swap(*this, other);
	return *this;
}

void CongTy::Input()
{
	if (m_Size != 0) { Delete(); }

	std::cout << "Moi nhap so luong cua nhan vien: ";
	std::cin >> m_Size;

	assert(m_Size != 0);

	m_DanhSachNV = new NhanVien * [m_Size]();

	for (int i = 0; i < m_Size; i++)
	{
		m_DanhSachNV[i] = InputNV();
	}
}

void CongTy::Output()
{
	std::cout << "Danh sach cac nhan vien cua cong ty: \n";
	for (int i = 0; i < m_Size; i++)
	{
		if (m_DanhSachNV[i] != nullptr)
		{
			std::cout << i + 1 << ". ";
			m_DanhSachNV[i]->Output();
		}
	}
}

float CongTy::GetSalary() const
{
	float tong = 0.0f;
	for (int i = 0; i < m_Size; i++)
	{
		tong += m_DanhSachNV[i]->GetSalary();
	}
	return tong;
}

float CongTy::GetHighestSalary() const
{
	float max = 0.0f;
	for (int i = 0; i < m_Size; i++)
	{
		float nvSalary = m_DanhSachNV[i]->GetSalary();
		if (nvSalary > max) { max = nvSalary; }
	}
	return max;
}

void CongTy::FindHighestSalary()
{
	float highest = this->GetHighestSalary();
	for (int i = 0; i < m_Size; i++)
	{
		if (m_DanhSachNV[i]->GetSalary() == highest)
		{
			std::cout << "Nhan vien co luong cao nhat la: \n";
			m_DanhSachNV[i]->Output();
		}
	}
}

float CongTy::GetAvgSalary() const
{
	return (this->GetSalary() / m_Size);
}

void CongTy::FindID(std::string id)
{
	std::cout << "Cac nhan vien co cung ID: " << id << " la: \n";
	for (int i = 0; i < m_Size; i++)
	{
		if (m_DanhSachNV[i]->GetID().compare(id) == 0)
		{
			m_DanhSachNV[i]->Output();
		}
	}
}

void CongTy::FindName(std::string name)
{
	std::cout << "Cac nhan vien co cung ten: " << name << " la: \n";
	for (int i = 0; i < m_Size; i++)
	{
		if (m_DanhSachNV[i]->GetName().compare(name) == 0)
		{
			m_DanhSachNV[i]->Output();
		}
	}
}

void CongTy::FindMonth(std::string month)
{
	std::cout << "Cac nhan vien co cung thang sinh " << month << " la: \n";

	if (month.length() == 1) // for example: make 7 to 07
	{
		month.insert(0, "0");
	}

	for (int i = 0; i < m_Size; i++)
	{
		if (m_DanhSachNV[i]->GetMonth().compare(month) == 0)
		{
			m_DanhSachNV[i]->Output();
		}
	}
}

void CongTy::AddNV()
{
	std::cout << "Moi ban nhap thong tin cua nhan vien moi \n";
	NhanVien* newNV = InputNV();

	// copy to temp array
	NhanVien** temp = new NhanVien * [m_Size]();
	for (int i = 0; i < m_Size; i++)
	{
		temp[i] = m_DanhSachNV[i]->Clone();
	}

	// temp size
	int tempSize = m_Size;

	// create new danhsach
	Delete();
	m_Size++;
	m_DanhSachNV = new NhanVien * [m_Size]();

	// copy back to danhsach
	for (int i = 0; i < m_Size - 1; i++)
	{
		m_DanhSachNV[i] = temp[i]->Clone();
	}
	m_DanhSachNV[m_Size - 1] = newNV;

	// delete temp
	for (int i = 0; i < tempSize; i++)
	{
		delete temp[i];
	}
	delete[] temp;
}

void CongTy::RemoveNV()
{
	int posNV = 0;
	std::cout << "Cac nhan vien co the xoa: \n";
	this->Output();

	std::cout << "Nhap so tuong ung voi nhan vien muon xoa: ";
	std::cin >> posNV;

	Remove(posNV - 1);
}

void CongTy::WriteBelowAvg()
{
	float avg = this->GetAvgSalary();

	std::ofstream writeFile;
	// write in binary, and delete file content before write
	writeFile.open("emp_LowerAvgSalary.dat", std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);

	for (int i = 0; i < m_Size; i++)
	{
		float salary = m_DanhSachNV[i]->GetSalary();
		if (salary < avg)
		{
			// write to dat file
			writeFile.write((char*)m_DanhSachNV[i], sizeof(*m_DanhSachNV[i]));
			std::cout << "Da ghi nhan vien: \n";
			m_DanhSachNV[i]->Output();
		}
	}

	writeFile.close();
}

void CongTy::Delete()
{
	for (int i = 0; i < m_Size; i++)
	{
		delete m_DanhSachNV[i];
	}
	delete[] m_DanhSachNV;
}

NhanVien* CongTy::InputNV()
{
	NhanVien* nv = nullptr;

	int type = 0;
	std::cout << "1. Nhan vien cong nhat \n";
	std::cout << "2. Nhan vien san xuat \n";
	std::cout << "Nhap so de chon loai nhan vien tuong ung: ";
	std::cin >> type;
	
	if (type == 1)
	{
		nv = new NVCongNhat();
		nv->Input();
	}
	else if (type == 2)
	{
		nv = new NVSanXuat();
		nv->Input();
	}
	
	return nv;
}

void CongTy::Remove(int pos)
{
	// chuyen nhan vien can xoa ve cuoi
	for (int i = 0; i < m_Size-1; i++)
	{
		if (i >= pos)
		{
			std::swap(m_DanhSachNV[i], m_DanhSachNV[i + 1]);
		}
	}

	// copy to temp array
	NhanVien** temp = new NhanVien * [m_Size]();
	for (int i = 0; i < m_Size; i++)
	{
		temp[i] = m_DanhSachNV[i]->Clone();
	}
	
	// temp size
	int tempSize = m_Size;

	// create new danhsach
	Delete();
	m_Size--;
	m_DanhSachNV = new NhanVien * [m_Size]();
	
	for (int i = 0; i < m_Size; i++)
	{
		m_DanhSachNV[i] = temp[i]->Clone();
	}

	// delete temp
	for (int i = 0; i < tempSize; i++)
	{
		delete temp[i];
	}
	delete[] temp;
}

void swap(CongTy& ct1, CongTy& ct2)
{
	using std::swap;
	swap(ct1.m_Size, ct2.m_Size);
	swap(ct1.m_DanhSachNV,ct2.m_DanhSachNV);
}
