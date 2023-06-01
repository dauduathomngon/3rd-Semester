#include "congty.h"

CongTy::CongTy() // DONE
	: m_DanhSachNV(nullptr)
	, m_Size(0)
{
}

CongTy::CongTy(const CongTy& ct) // DONE
	: m_Size(ct.m_Size)
	, m_DanhSachNV(nullptr)
{
	if (m_Size != 0)
	{
		m_DanhSachNV = new NhanVien * [m_Size]();
		for (int i = 0; i < m_Size; i++)
		{
			m_DanhSachNV[i] = ct.m_DanhSachNV[i]->Clone();
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

void CongTy::WriteToFile() // DONE
{
	std::ofstream writeFile;
	writeFile.open("ds_NhanVien.dat", std::ios_base::trunc | std::ios_base::out);

	if (!writeFile)
	{
		std::cout << "Can't write to file \n";
	}
	else
	{
		writeFile.write((char*)&m_Size, sizeof(m_Size)); // ghi so luong nhan vien

		std::cout << "Da ghi nhan vien: \n";
		for (int i = 0; i < m_Size; i++)
		{
			char* type = m_DanhSachNV[i]->GetType();
			writeFile.write(type, strlen(type) + 1); // ghi loai nhan vien

			writeFile.write((char*)m_DanhSachNV[i], sizeof(*m_DanhSachNV[i])); // ghi thong tin nhan vien

			m_DanhSachNV[i]->Output();
		}
	}

	writeFile.close();
}

void CongTy::ReadFromFile() // TODO
{
	NhanVien value;

	std::ifstream readFile;
	readFile.open("ds_NhanVien.dat", std::ios_base::binary | std::ios_base::in);

	if (!readFile)
	{
		std::cout << "Can't read file \n";
	}
	else
	{
		if (m_DanhSachNV != nullptr)
		{
			Delete(); // xoa danh sach cu
		}

		readFile.seekg(0);

		readFile.read((char*)&m_Size, sizeof(int)); // doc so luong nhan vien
		m_DanhSachNV = new NhanVien * [m_Size]();

		for (int i = 0; i < m_Size; i++) // doc loai nhan vien va ca thong tin nhan vien
		{
			char* type = new char[MAX_LEN]();
			readFile.read(type, MAX_LEN);

			if (strcmp(type, "cong nhat") == 0) // cong nhat;
			{
				m_DanhSachNV[i] = new NVCongNhat();
			}
			else if (strcmp(type, "san xuat") == 0) // san xuat;
			{
				m_DanhSachNV[i] = new NVSanXuat();
			}
			/*char* val = new char[MAX_LEN]();
			for (int i = 0; i < 6; i++)
			{
				readFile.read(val, MAX_LEN);
			}*/
			readFile.read(reinterpret_cast<char*>(m_DanhSachNV[i]), sizeof(*m_DanhSachNV[i]));
		}
	}

	readFile.close();
}

void CongTy::WriteBelowAvg() // DONE
{


	std::ofstream writeFile;
	writeFile.open("emp_LowerAvgSalary.dat", std::ios_base::binary | std::ios_base::trunc | std::ios_base::out);

	if (!writeFile)
	{
		std::cout << "Can't write to file \n";
	}
	else
	{
		float avgSalary = this->GetAvgSalary();
		for (int i = 0; i < m_Size; i++)
		{
			float salary = m_DanhSachNV[i]->GetSalary();
			if (salary < avgSalary)
			{
				writeFile.write((char*)m_DanhSachNV[i], sizeof(*m_DanhSachNV[i]));
				std::cout << "Da ghi nhan vien: \n";
				m_DanhSachNV[i]->Output();
			}
		}
	}

	writeFile.close();
}

void CongTy::Input() // DONE
{
	if (m_DanhSachNV != nullptr)
	{
		Delete();
	}

	std::cout << "Moi ban nhap so luong nhan vien: ";
	std::cin >> m_Size;

	m_DanhSachNV = new NhanVien * [m_Size]();

	for (int i = 0; i < m_Size; i++)
	{
		int type = 0;

		std::cout << "------------------------\n";
		std::cout << "Nhan vien thuoc loai nao ? (1 cho cong nhat, 2 la san xuat): ";
		std::cin >> type;
		std::cin.ignore();

		switch (type)
		{
		case(1):
		{
			NhanVien* newNV = new NVCongNhat();

			newNV->Input();
			std::cout << "------------------------\n";

			m_DanhSachNV[i] = newNV;
			break;
		}
		case(2):
		{
			NhanVien* newNV = new NVSanXuat();

			newNV->Input();
			std::cout << "------------------------\n";

			m_DanhSachNV[i] = newNV;
			break;
		}
		default:
			break;
		}
	}
}

void CongTy::Output() // DONE
{
	std::cout << "Duoi day la danh sach cac nhan vien: \n";
	for (int i = 0; i < m_Size; i++)
	{
		m_DanhSachNV[i]->Output();
	}
}

void CongTy::FindHighestSalary() // DONE
{
	float highestSalary = this->GetHighestSalary();
	for (int i = 0; i < m_Size; i++)
	{
		if (m_DanhSachNV[i]->GetSalary() == highestSalary)
		{
			std::cout << "Nhan vien co luong cao nhat la: \n";
			m_DanhSachNV[i]->Output();
		}
	}
}

void CongTy::FindID(const char* ID) // DONE
{
	std::cout << "Duoi day la danh sach nhan vien co ID " << ID << ": \n";
	for (int i = 0; i < m_Size; i++)
	{
		if (strcmp(ID, m_DanhSachNV[i]->GetID()) == 0)
		{
			m_DanhSachNV[i]->Output();
		}
	}
}

void CongTy::FindName(const char* name) // DONE
{
	std::cout << "Duoi day la danh sach nhan vien co ten " << name << ": \n";
	for (int i = 0; i < m_Size; i++)
	{
		if (strcmp(name, m_DanhSachNV[i]->GetName()) == 0)
		{
			m_DanhSachNV[i]->Output();
		}
	}
}

void CongTy::FindMonth(int month) // DONE
{
	int count = 0;
	std::cout << "Duoi day la danh sach nhan vien co thang sinh " << month << ": \n";

	for (int i = 0; i < m_Size; i++)
	{
		if (month == m_DanhSachNV[i]->GetMonthOfBirth())
		{
			count++;
			m_DanhSachNV[i]->Output();
		}
	}

	std::cout << "So nhan vien sinh trong thang " << month << " la: " << count << "\n";
	std::cout << "------------------------\n";
}

void CongTy::AddEmployee() // DONE
{
	int choice = 0;
	std::cout << "Ban muon them nhan vien nao (1 la cong nhat, 2 la san xuat): ";
	std::cin >> choice;
	std::cin.ignore();

	NhanVien* newNV = nullptr;

	switch (choice)
	{
	case(1):
	{
		newNV = new NVCongNhat();
		break;
	}
	case(2):
	{
		newNV = new NVSanXuat();
		break;
	}
	default:
		return;
	}

	newNV->Input(); // nhap gia tri cho nhan vien

	NhanVien** temp = new NhanVien * [m_Size + 1](); // tao array phu
	for (int i = 0; i < m_Size; i++)
	{
		temp[i] = m_DanhSachNV[i]->Clone(); // copy 
	}
	temp[m_Size] = newNV;

	Delete(); // xoa danh sach cu
	++m_Size; // tang size
	m_DanhSachNV = temp; 

	this->WriteToFile(); // ghi lai file
}

void CongTy::RemoveEmployee() // DONE
{
	std::cout << "Duoi day la danh sach cac nhan vien: \n";
	for (int i = 0; i < m_Size; i++)
	{
		std::cout << i << ". \n";
		m_DanhSachNV[i]->Output();
	}

	int choice = 0;
	std::cout << "Moi ban nhap so thu tu de xoa nhan vien tuong ung: ";
	std::cin >> choice;

	this->Remove(choice); // xoa nhan vien duoc chon
	this->WriteToFile();
}

float CongTy::GetTotalSalary() const // DONE
{
	float total = 0;
	for (int i = 0; i < m_Size; i++)
	{
		total += m_DanhSachNV[i]->GetSalary();
	}
	return total;
}

float CongTy::GetAvgSalary() const // DONE
{
	return GetTotalSalary() / m_Size;
}

float CongTy::GetHighestSalary() const // DONE
{
	float max = 0;

	for (int i = 0; i < m_Size; i++)
	{
		float salary = m_DanhSachNV[i]->GetSalary();
		if (salary >= max)
		{
			max = salary;
		}
	}

	return max;
}

void CongTy::Delete() // DONE
{
	for (int i = 0; i < m_Size; i++)
	{
		delete m_DanhSachNV[i];
		m_DanhSachNV[i] = nullptr;
	}
	delete[] m_DanhSachNV;
}

void CongTy::Remove(int idx)
{
	for (int i = 0; i < m_Size - 1; i++) // dua nhan vien can xoa ve cuoi
	{
		if (i >= idx)
		{
			std::swap(m_DanhSachNV[i], m_DanhSachNV[i + 1]);
		}
	}

	NhanVien** temp = new NhanVien * [m_Size - 1]();

	for (int i = 0; i < m_Size - 1; i++)
	{
		temp[i] = m_DanhSachNV[i]->Clone();
	}

	Delete();
	--m_Size;
	m_DanhSachNV = temp;
}

void swap(CongTy& ct1, CongTy& ct2) // DONE
{
	using std::swap;
	swap(ct1.m_Size, ct2.m_Size);
	swap(ct1.m_DanhSachNV, ct2.m_DanhSachNV);
}
