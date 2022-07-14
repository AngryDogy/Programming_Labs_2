
#ifndef LAB1_CLOSED_LINE_H
#define LAB1_CLOSED_LINE_H

#include "Point.h"
#include "Broken_line.h"

class Closed_line : public Broken_line
{
public:
    Closed_line()
    {}

    Closed_line(std::vector<Point> points)
    {
        points_.resize(points.size());
        for (int i = 0; i < points.size(); i++)
        {
            points_[i].x_change(points[i].x());

            points_[i].y_change(points[i].y());
        }

        if (points_[0] != points_[points.size() - 1])
        {
            points_.resize(points.size() + 1);
            points_[points.size()] = points_[0];
        }
    }

    Closed_line(const Closed_line &other)
    {
        points_.resize(other.points_.size());
        for (int i = 0; i < other.points_.size(); i++)
        {
            points_[i].x_change(other.points_[i].x());
            points_[i].y_change(other.points_[i].y());
        }
    }

    ~Closed_line()
    {};


};

#endif
