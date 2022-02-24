
#ifndef LAB1_BROKEN_LINE_H
#define LAB1_BROKEN_LINE_H

#include "Point.h"

class Broken_line
{
public:
    Broken_line()
    {}

    Broken_line(std::vector<Point> &points)
    {

        points_.resize(points.size());
        for (int i = 0; i < points.size(); i++)
        {
            points_[i].x_change(points[i].x());
            points_[i].y_change(points[i].y());
        }
    }

    Broken_line(const Broken_line &other)
    {
        points_.resize(other.points_.size());
        for (int i = 0; i < other.points_.size(); i++)
        {
            points_[i].x_change((other.points_[i].x()));
            points_[i].y_change(other.points_[i].y());
        }
    }

    ~Broken_line()
    {}

    Broken_line &operator=(Broken_line other)
    {
        points_.resize(other.points_.size());
        for (int i = 0; i < other.points_.size(); i++)
        {
            points_[i].x_change(other.points_[i].x());
            points_[i].y_change(other.points_[i].y());
        }
        return *this;
    }

    int number_points()
    {
        return points_.size();
    }

    int point_x(int n) const
    {
        if (n < points_.size())
            return points_[n].x();
        else
            exit(-1);
    }

    int point_y(int n) const
    {
        if (n < points_.size())
            return points_[n].y();
        else
            exit(-1);
    }

protected:
    std::vector<Point> points_;
};

#endif
