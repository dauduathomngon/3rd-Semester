#pragma once
#ifndef MANG_PS_H
#define MANG_PS_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "phanso.h"

class MangPS
{
public:
    MangPS();
    ~MangPS();
    MangPS(const MangPS& arr);

    void Input();
    void Output();

    PhanSo GetSum() const;

    void SortAscending();

    void WriteToFile();
    void ReadFromFile();
private:
    PhanSo* m_pArr;
    int m_Size;
};

#endif // MANG_PS_H
