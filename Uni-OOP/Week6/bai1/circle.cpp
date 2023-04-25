#include "circle.h"
Circle::Circle()
: R(0)
, C()
{
}

Circle::Circle(Point p, double c)
: C(p)
, R(c)
{
}

double Circle::area()
{
    return (3.14) * (3.14) * R;
}

bool Circle::IsSelected(Point p)
{
    return (((p.X - C.X)*(p.X - C.X) + (p.Y - C.Y)*(p.Y - C.Y)) <= R*R);
}

Shape* Circle::Clone()
{
    return  new Circle(this->C, this->R);
}

void Circle::input()
{
    std::cout << "Nhap gia tri x cua tam: ";
    std::cin >> C.X;
    std::cout << "Nhap gia tri y cua tam: ";
    std::cin >> C.Y;
    std::cout << "Nhap ban kinh: ";
    std::cin >> R;
}

void Circle::print()
{
    std::cout << "Tam: (" << C.X << ", " << C.Y << ") \n";
    std::cout << "Ban kinh: " << R << "\n";
}
