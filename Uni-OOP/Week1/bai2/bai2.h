#ifndef BAI2_H
#define BAI2_H

#include "triangle.h"

#include <iostream>

class Bai2
{
public:
    Bai2() = default;
    ~Bai2() = default;

    void nhap();

    void xuat();

    void dien_tich();

    void chu_vi();

    void loai_tam_giac();

private:
    double m_pointA[2];
    double m_pointB[2];
    double m_pointC[2];

    Triangle ABC;
};

#endif // BAI2_H