#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <string.h>
#include <iostream>

const int maxSize = 100;

class SinhVien
{
public:
    // default constructor
    SinhVien();

    // destructor
    ~SinhVien();

    // setter
    void SetValue(const char* tenSV, const char* maSoSV, const char* ngaySinhSV);

    // parameter constructor
    SinhVien(const char* tenSV, const char* maSoSV, const char* ngaySinhSV);

    // copy constructor
    SinhVien(const SinhVien& sv);

    // swap 
    friend void swap(SinhVien& sv1, SinhVien& sv2);

    // assignment operator
    SinhVien& operator=(SinhVien other);

    // print sinh vien
    void Print();

private:
    char* m_Ten;
    char* m_MaSo;
    char* m_NgaySinh;
};

#endif // SINHVIEN_H