#include <iostream>
#include<vector>
#include "Point.h"
#include "Broken_line.h"
#include "Closed_line.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Trapeze.h"
#include "Vector.h"
#include "Regular_polygon.h"
#include "Polynom.h"

int main()
{
    Point A(1, 1), B(3, 1), C(3, 3), D(1, 3);
    std::vector<Point> points;
    points.resize(3);
    points[0] = A;
    points[1] = B;
    points[2] = C;
    Broken_line bline(points);
    std::cout << "Number of broken line's points:" << bline.number_points() << ' ' << "First point: "
              << bline.point_x(0) << ' ' << bline.point_y(0) << '\n';
    points.resize(4);
    points[3] = D;
    Closed_line cline(points);
    std::cout << "For closed line: " << cline.number_points() << '\n';
    Polygon polygon(points);
    std::cout << "Area and perimeter: " << polygon.area() << ' ' << polygon.perimeter() << ' ' << "For "
              << polygon.number_points() << '\n';
    Regular_polygon rpolygon(points);
    std::cout << "Regular_polygon points:" << '\n';
    for (int i = 0; i < rpolygon.number_points(); i++)
    {
        std::cout << rpolygon.point_x(i) << ' ' << rpolygon.point_y(i) << '\n';
    }
    points[0] = Point(1, 1);
    points[1] = Point(6, 1);
    points[2] = Point(3, 3);
    points[3] = Point(5, 3);
    Trapeze trapeze(points);
    std::cout << "Trapeze: " << trapeze.area() << ' ' << trapeze.perimeter() << '\n';
    points.resize(3);
    Triangle triangle(points);
    std::cout << "Area and perimeter of Triangle: " << triangle.area() << ' ' << triangle.perimeter() << '\n';
    std::vector<double> values;
    values.resize(3);
    values[0] = 1.0;
    values[1] = 1.5;
    values[2] = -2.5;
    Polynom p1(values), p2;
    std::cin >> p2;
    Polynom p = p1 + p2;
    p *= 5;
    std::cout << p;
    return 0;
}