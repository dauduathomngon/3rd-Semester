#ifndef BAI1_H
#define BAI1_H

#include "poly.h"

#include <vector>
#include <string>
#include <iostream>

Polynomial P_Process(std::string poly_raw);

class Bai1
{
public:
    Bai1() {}
    ~Bai1() {}

    void nhap();
    void xuat();
    void tinh_gia_tri();
    void cong();
    void tru();
    void nhan();

private:
    std::vector<Polynomial> P {};
};

#endif // BAI1_H