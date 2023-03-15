#include "sinhvien.h"

SinhVien::SinhVien()
: m_Ten(new char[maxSize] ())
, m_MaSo(new char[maxSize] ())
, m_NgaySinh(new char[maxSize] ())
{
}

SinhVien::~SinhVien()
{
    delete[] m_Ten;
    delete[] m_MaSo;
    delete[] m_NgaySinh;
}

void SinhVien::SetValue(const char* tenSV, const char* maSoSV, const char* ngaySinhSV)
{
    strcpy(m_Ten, tenSV);
    strcpy(m_MaSo, maSoSV);
    strcpy(m_NgaySinh, ngaySinhSV);
}

SinhVien::SinhVien(const char* tenSV, const char* maSoSV, const char* ngaySinhSV)
: m_Ten(new char[strlen(tenSV)]())
, m_MaSo(new char[strlen(maSoSV)]())
, m_NgaySinh(new char[strlen(ngaySinhSV)]())
{
    strcpy(m_Ten, tenSV);
    strcpy(m_MaSo, maSoSV);
    strcpy(m_NgaySinh, ngaySinhSV);
}

SinhVien::SinhVien(const SinhVien& sv)
: m_Ten(new char[strlen(sv.m_Ten)]())
, m_MaSo(new char[strlen(sv.m_MaSo)]())
, m_NgaySinh(new char[strlen(sv.m_NgaySinh)]())
{
    strcpy(m_Ten, sv.m_Ten);
    strcpy(m_MaSo, sv.m_MaSo);
    strcpy(m_NgaySinh, sv.m_NgaySinh);
}

void swap(SinhVien& sv1, SinhVien& sv2)
{
    using std::swap;
    swap(sv1.m_Ten, sv2.m_Ten);
    swap(sv1.m_MaSo, sv2.m_MaSo);
    swap(sv1.m_NgaySinh, sv2.m_NgaySinh);
}

SinhVien& SinhVien::operator=(SinhVien other)
{
    swap(*this, other);
    return *this;
}

void SinhVien::Print()
{
    std::cout << "Ten cua sinh vien la: " << this->m_Ten << "\n";
    std::cout << "Ma so cua sinh vien la: " << this->m_MaSo << "\n";
    std::cout << "Ngay sinh cua sinh vien la: " << this->m_NgaySinh << "\n";
}
