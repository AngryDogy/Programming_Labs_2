
#ifndef LAB1_TRAPEZE_H
#define LAB1_TRAPEZE_H

#include "Polygon.h"
#include "Vector.h"

double eps = 1e-12;

class Trapeze : public Polygon
{
public:
    Trapeze()
    {}

    Trapeze(std::vector<Point> points)
    {
        if (points.size() == 4)
        {
            Vector v[4];
            v[0] = Vector(points[0], points[1]);
            v[1] = Vector(points[1], points[2]);
            v[2] = Vector(points[2], points[3]);
            v[3] = Vector(points[3], points[0]);
            int k = 0;
            for (int i = 0; i < 4; i++)
            {
                for (int j = i + 1; j < 4; j++)
                {
                    if (1 - v[i].getCos(v[j]) < eps)
                    {
                        k++;

                    }
                }
            }
            if (k == 1)
            {
                points_.resize(4);
                for (int i = 0; i < 4; i++)
                {
                    points_[i].x_change(points[i].x());
                    points_[i].y_change(points[i].y());
                }
            }
        }
    }

};

#endif
