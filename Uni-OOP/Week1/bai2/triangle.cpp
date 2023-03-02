#include "triangle.h"

void Triangle::input(double pointA[], double pointB[], double pointC[])
{
    // point A
    m_A.x = pointA[0];
    m_A.y = pointA[1];

    // point B
    m_B.x = pointB[0];
    m_B.y = pointB[1];

    // point C
    m_C.x = pointC[0];
    m_C.y = pointC[1];

    // edge AB
    m_AB.first = m_A;
    m_AB.last = m_B;
    m_AB.length = calculate_edge_len(m_A, m_B);

    // edge BC
    m_BC.first = m_B;
    m_BC.last = m_C;
    m_BC.length = calculate_edge_len(m_B, m_C);

    // edge AC
    m_AC.first = m_A;
    m_AC.last = m_C;
    m_AC.length = calculate_edge_len(m_A, m_C);
}

double Triangle::calculate_edge_len(Point A, Point B)
{

}

bool Triangle::is_triangle(Point A, Point B, Point C)
{

}

void Triangle::print()
{

}

double Triangle::area()
{

}

double Triangle::perimeter()
{

}

void Triangle::shape()
{

}