
#ifndef LAB1_POINT_H
#define LAB1_POINT_H
class Point
{
public:
    Point(int x = 0, int y = 0)
            : x_(x)
            , y_(y)
    {}
    Point(const Point& other)
            : x_(other.x_)
            , y_(other.y_)
    {}
    ~Point(){}
    Point& operator=(const Point& other)
    {
        if(&other == this)
            return *this;
        x_ = other.x_;
        y_ = other.y_;
        return *this;
    }
    bool operator!=(const Point& other)
    {
        if(this->x_ == other.x() && this->y_ == other.y())
            return false;
        else
            return true;
    }
    void x_change(int x)
    {
        this->x_ = x;
    }
    void y_change(int y)
    {
        this->y_ = y;
    }
    int x() const
    {
        return x_;
    }
    int y() const
    {
        return y_;
    }
private:
    int x_;
    int y_;
};
#endif
