#include "bai1.h"

Polynomial P_Process(std::string poly_raw)
{

}

void Bai1::nhap()
{
    std::string poly_raw;
    std::cout << "**Luu y: Da thuc chi co toi da 3 bien la x, y, z. Khong chap nhan cac bien bang chu khac. Da thuc khong co dau ngoac** \n";
    std::cout << "Moi ban nhap mot da thuc bat ki: ";
    std::cin >> poly_raw;

    P.push_back(P_Process(poly_raw));
}

void Bai1::xuat()
{
    for (int i=0; i < P.size(); i++) 
    {
        P[i].print();
        std::cout << "\n";
    }
}