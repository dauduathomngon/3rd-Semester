#include "rectangle.h"

Rectange::Rectange()
: X()
, W(0)
, H(0)
{
}

Rectange::Rectange(Point p, double w, double h)
: X(p)
, W(w)
, H(h)
{
}

double Rectange::area()
{
    return  W * H;
}

bool Rectange::IsSelected(Point p)
{
    
}

Shape* Rectange::Clone()
{
    return new Rectange(X, W, H);
}

void Rectange::input()
{
    std::cout << "Nhap gia tri x cua toa do goc trai tren: ";
    std::cin >> X.X;
    std::cout << "Nhap gia tri y cua toa do goc trai tren: ";
    std::cin >> X.Y;    
    std::cout << "Nhap do dai: ";
    std::cin >> W;
    std::cout << "Nhap chieu cao: ";
    std::cin >> H;
}

void Rectange::print()
{
    std::cout << "Goc trai tren: (" << X.X << ", " << X.Y << ") \n";
    std::cout << "Chieu dai: " << W << "\n";
    std::cout << "Chieu cao: " << H << "\n";
}
