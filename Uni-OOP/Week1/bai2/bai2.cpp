#include "bai2.h"

void Bai2::nhap()
{
    std::cout << "Mot tam giac co ba diem, moi diem co x va y \n";

    std::cout << "Moi ban nhap x cua diem A: ";
    std::cin >> m_pointA[0];
    
    std::cout << "Moi ban nhap y cua diem A: ";
    std::cin >> m_pointA[1];

    std::cout << "Moi ban nhap x cua diem B: ";
    std::cin >> m_pointB[0];
    
    std::cout << "Moi ban nhap y cua diem B: ";
    std::cin >> m_pointB[1];

    std::cout << "Moi ban nhap x cua diem C: ";
    std::cin >> m_pointC[0];
    
    std::cout << "Moi ban nhap y cua diem C: ";
    std::cin >> m_pointC[1];

    ABC.input(m_pointA, m_pointB, m_pointC);
}

void Bai2::xuat()
{
    ABC.print();
}

void Bai2::chu_vi()
{
    std::cout << "Dien tich cua tam giac la: " << ABC.area() << "\n";
}

void Bai2::dien_tich()
{
    std::cout << "Chu vi cua tam giac la: " << ABC.perimeter() << "\n";
}

void Bai2::loai_tam_giac()
{
    ABC.shape();
}