#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <algorithm>

struct Point
{
    double x;
    double y;
};

struct Edge
{
    Point first{0, 0};
    Point last{0, 0};
    double length = 0;
};

class Triangle
{
public:
    Triangle() = default;

    ~Triangle() = default;

    void input(double pointA[], double pointB[], double pointC[]);

    void print();

    double area();

    double perimeter();

    void shape();

private:
    Point m_A{0,0};
    Point m_B{0,0};
    Point m_C{0,0};

    Edge m_AB;
    Edge m_BC;
    Edge m_AC;

    double calculate_edge_len(Point A, Point B);

    bool is_triangle(Point A, Point B, Point C);
};

#endif // TRIANGLE_H