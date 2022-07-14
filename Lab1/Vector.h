
#ifndef LAB1_VECTOR_H
#define LAB1_VECTOR_H

#include "Point.h"

class Vector
{
public:

    Vector(Point p1 = 0, Point p2 = 0)
            : x_(p1.x() - p2.x()), y_(p1.y() - p2.y())
    {
        if (x_ < 0)
            x_ = -x_;
        if (y_ < 0)
            y_ = -y_;
    }

    Vector(Vector &object)
            : x_(object.x_), y_(object.y_)
    {}

    ~Vector()
    {}

    double getCos(Vector &other)
    {
        return (this->x_ * other.x_ + this->y_ * other.y_) / (this->len() * other.len());
    }

    double len() const
    {
        return sqrt(x_ * x_ + y_ * y_);
    }

private:
    int x_;
    int y_;
};

#endif
