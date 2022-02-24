
#ifndef LAB1_TRIANGLE_H
#define LAB1_TRIANGLE_H
#include "Polygon.h"
#include "Vector.h"
class Triangle : public Polygon
{
public:
    Triangle(){}
    Triangle(std::vector<Point> points)
    {
        if (points.size() == 3)
        {
            double len[3];
            Vector v;
            v = Vector(points[1], points[0]);
            len[0] = v.len();
            v = Vector(points[2], points[1]);
            len[1] = v.len();
            v = Vector(points[2], points[0]);
            len[2] = v.len();
            if(len[0] + len[1] > len[2] && len[1] + len[2] > len[0] && len[2] + len[0] > len[1])
            {
                points_.resize(3);
                for (int i = 0; i < 3; i++)
                {
                    points_[i].x_change(points[i].x());
                    points_[i].y_change(points[i].y());
                }
            }
        }
    }
    Triangle(const Triangle &other)
    {
        points_.resize(other.points_.size());
        for(int i = 0; i < other.points_.size(); i++)
        {
            points_[i].x_change(other.points_[i].x());
            points_[i].y_change(other.points_[i].y());
        }
    }
    ~Triangle(){}
};
#endif
