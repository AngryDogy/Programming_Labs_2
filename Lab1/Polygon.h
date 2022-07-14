

#ifndef LAB1_POLYGON_H
#define LAB1_POLYGON_H

#include "Closed_line.h"

class Polygon : public Closed_line
{
public:
    Polygon()
    {}

    Polygon(std::vector<Point> points)
    {
        points_.resize(points.size());
        for (int i = 0; i < points.size(); i++)
        {
            points_[i].x_change(points[i].x());
            points_[i].y_change(points[i].y());
        }
    }

    Polygon(const Polygon &other)
    {
        points_.resize(other.points_.size());
        for (int i = 0; i < other.points_.size(); i++)
        {
            points_[i].x_change(other.points_[i].x());
            points_[i].y_change(other.points_[i].y());
        }
    }

    ~Polygon()
    {}

    double perimeter() const
    {
        double ans = 0, x, y;
        for (int i = 0; i < points_.size() - 1; i++)
        {
            x = this->point_x(i + 1) - this->point_x(i);
            y = this->point_y(i + 1) - this->point_y(i);
            ans = ans + sqrt(x * x + y * y);
        }
        return ans;
    }

    double area()
    {
        double sum = 0;
        for (int i = 0; i < points_.size() - 1; i++)
        {
            sum = sum + (points_[i].x() + points_[i + 1].x()) * (points_[i + 1].y() - points_[i].y());
        }
        sum = sum +
              (points_[points_.size() - 1].x() + points_[0].x()) * (points_[0].y() - points_[points_.size() - 1].y());
        sum = sum / 2;
        if (sum < 0)
            return -sum;
        else
            return sum;
    }

};

#endif
