#include "sinhvien.h"

SinhVien::SinhVien()
: m_Ten(new char[STR_SIZE]())
, m_MaSo(new char[STR_SIZE]())
, m_NgaySinh(new char[STR_SIZE]())
, m_Diem(new float[MARK_SIZE]())
{
}

SinhVien::~SinhVien()
{
    delete[] m_Ten;
    delete[] m_MaSo;
    delete[] m_NgaySinh;
    delete[] m_Diem;
}

void SinhVien::SetValue(const std::string& val, int status)
{
    switch (status)
    {
    case 0:
        strcpy_s(m_Ten, val.size() + 1, val.c_str());
        break;
    case 1:
        strcpy_s(m_MaSo, val.size() + 1, val.c_str());
        break;
    case 2:
        strcpy_s(m_NgaySinh, val.size() + 1, val.c_str());
        break;
    default:
        m_Diem[status - 3] = std::atof(val.c_str());
        break;
    }
}

SinhVien::SinhVien(const SinhVien& sv)
: m_Ten(new char[STR_SIZE]())
, m_MaSo(new char[STR_SIZE]())
, m_NgaySinh(new char[STR_SIZE]())
, m_Diem(new float[MARK_SIZE]())
{ 
    // copy char*
    strcpy_s(m_Ten, strlen(sv.m_Ten) + 1, sv.m_Ten);
    strcpy_s(m_MaSo, strlen(sv.m_MaSo) + 1, sv.m_MaSo);
    strcpy_s(m_NgaySinh, strlen(sv.m_NgaySinh) + 1, sv.m_NgaySinh);

    // copy array
    std::copy(sv.m_Diem, sv.m_Diem + MARK_SIZE, m_Diem);
}

SinhVien& SinhVien::operator=(SinhVien other)
{
    swap(*this, other);
    return *this;
}

void SinhVien::Output()
{
    std::cout << "Ten cua sinh vien: "  << m_Ten << "\n";
    std::cout << "Ma so sinh vien: " << m_MaSo << "\n";
    std::cout << "Ngay sinh cua sinh vien: " << m_NgaySinh << "\n";
    std::cout << "Diem bai tap cua sinh vien: " << m_Diem[0] << "\n";
    std::cout << "Diem giua ky cua sinh vien: " << m_Diem[1] << "\n";
    std::cout << "Diem cuoi ky cua sinh vien: " << m_Diem[2] << "\n";
}

float SinhVien::AvgMark() const
{
    return (m_Diem[0] * 0.25f) + (m_Diem[1] * 0.25f) + (m_Diem[2] * 0.5f);
}

std::string SinhVien::GetDate() const
{
    char* date = new char[DATE_WITHOUT_YEAR_SIZE]();

    int count = 0;
    for (int i=0; i < DATE_SIZE; i++)
    {
        if (m_NgaySinh[i] == '/')
        {
            ++count;
        }

        if (count == 2)
        {
            break;
        }

        date[i] = m_NgaySinh[i];
    };

    return std::string(date);
}

/*
write in format: ten,ma so,ngay sinh,diembt,diemgk,diemck
*/
std::ostream& operator<<(std::ostream& os, const SinhVien& sv)
{
    os << sv.m_Ten << " | "
       << sv.m_MaSo << " | " 
       << sv.m_NgaySinh << " | " 
       << sv.m_Diem[0] << " | " 
       << sv.m_Diem[1] << " | " 
       << sv.m_Diem[2] << std::endl;
    return os;
}

void swap(SinhVien& sv1, SinhVien& sv2)
{
    using std::swap; // ADL
    swap(sv1.m_Ten, sv2.m_Ten);
    swap(sv1.m_MaSo, sv2.m_MaSo);
    swap(sv1.m_NgaySinh, sv2.m_NgaySinh);
    swap(sv1.m_Diem, sv2.m_Diem);
}