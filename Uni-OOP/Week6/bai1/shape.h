/*****************************************************
* Define Shape class, File giao dien cho lop Shape
*****************************************************/
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

// Dinh nghia diem Point
struct Point {
    double X, Y;
};

// Dinh nghia lop Shape
class Shape {
public:
    // it'll reimplement in each derived class
    /* area of shape, e.g. area of circle, or rectange */
    virtual double area() = 0;
    virtual Shape*Clone() = 0;
    virtual bool IsSelected(Point p) = 0;
    virtual void input() {/*nothing to do*/};
    virtual void print() {/*nothing to do*/};
};

#endif