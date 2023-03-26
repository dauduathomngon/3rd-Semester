#pragma once
#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <string.h>
#include <string>
#include <iostream>

const int MARK_SIZE = 3;
const int STR_SIZE = 50;
const int DATE_SIZE = 10; // format: dd/mm/yyyy
const int DATE_WITHOUT_YEAR_SIZE = 6; // format: dd/mm

class SinhVien
{
public:
    // default constructor
    SinhVien();

    // destructor
    ~SinhVien();

    // setter (use for file input)
    void SetValue(const std::string& val, int status);

    // copy constructor
    SinhVien(const SinhVien& sv);

    // swap function (optional)
    friend void swap(SinhVien& sv1, SinhVien& sv2);

    // assignment operator (optional)
    SinhVien& operator=(SinhVien other);

    // output
    void Output();

    // find average mark
    float AvgMark() const;

    // get date
    std::string GetDate() const;

    // iostream
    friend std::ostream& operator<<(std::ostream& os, const SinhVien& sv);

private:
    char* m_Ten;
    char* m_MaSo;
    char* m_NgaySinh;
    float* m_Diem;
};


#endif // SINHVIEN_H