#ifndef RECTANGE_H
#define RECTANGE_H

#include "shape.h"

class Rectange : public Shape {
protected:
    Point X; // Toa do goc trai tren
    double W, H; // Chieu rong va chieu cao
public:
    // Constructors
    Rectange();
    Rectange(Point p, double h, double w);
    /* area of rectange */
    double area();
    bool IsSelected(Point p);
    Shape* Clone();
    void input();
    void print();
};

#endif