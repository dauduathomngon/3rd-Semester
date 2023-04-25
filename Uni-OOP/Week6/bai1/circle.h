#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

// Dinh nghia lop Circle
class Circle : public Shape {
protected:
    Point C; // toa do tam
    double R; // do dai ban kinh
public:
    // Constructors
    Circle();
    Circle(Point p, double r);
    /* override area() method */
    double area();
    bool IsSelected(Point p);
    Shape* Clone();
    void input();
    void print();
};

#endif