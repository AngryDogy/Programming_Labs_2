
#ifndef LAB1_REGULAR_POLYGON_H
#define LAB1_REGULAR_POLYGON_H

#include "Polygon.h"
#include "Vector.h"

class Regular_polygon : public Polygon
{
public:
    Regular_polygon()
    {}

    Regular_polygon(std::vector<Point> points)
    {
        points_.resize(points.size());
        int value = 0;
        bool check = true;
        Vector v;
        for (int i = 0; i < points.size() - 1; i++)
        {
            v = Vector(points[i], points[i + 1]);
            if (value == 0)
            {
                value = v.len();
            }
            else
            {
                if (value != v.len())
                {
                    check = false;
                    break;
                }
            }
        }
        if (check)
        {
            for (int i = 0; i < points.size(); i++)
            {
                points_[i].x_change(points[i].x());
                points_[i].y_change(points[i].y());
            }
        }
    }

    Regular_polygon(const Regular_polygon &other)
    {
        points_.resize(other.points_.size());
        for (int i = 0; i < other.points_.size(); i++)
        {
            points_[i].x_change(other.points_[i].x());
            points_[i].y_change(other.points_[i].y());
        }
    }

    ~Regular_polygon()
    {}

};

#endif
