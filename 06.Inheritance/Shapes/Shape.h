#ifndef SHAPE_H

#define SHAPE_H
#include "Vector2D.h"
#include <sstream>

class Shape {
public:
    Shape(Vector2D& center) : center(center) 
    {}
    Shape() : center(Vector2D(0, 0)) 
    {}
    const Vector2D& getCenter() const {
        return center;
    }
    double getArea() const {
        return area;
    }
protected:
    Vector2D center;
    double area;
};

#endif