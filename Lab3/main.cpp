#include <iostream>
#include<vector>
#include<algorithm>
#include "circular_buffer.h"
#include "algorithms.h"
#include "point.h"

template<typename T>
bool function(T a)
{
    return a == 50;
}

void pow(int &i)
{ i *= i; }

template<typename T>
bool sorted(T a, T b)
{
    if (a > b)
        return true;
    return false;
}

template<typename T>
bool zero(T a)
{
    if (a == 0)
        return true;
    return false;
}

template<typename T>
bool greater(T a)
{
    if (a < 20)
        return true;
    return false;
}

template<typename T>
bool func(T a, T b)
{
    if (a == b)
        return true;
    return false;
}

int main()
{
    circular_buffer<int> buffer(8);
    std::cout << "Capacity of the buffer - " << buffer.capacity() << std::endl;
    for (int i = 0; i < 4; i++)
        buffer.push_back(i);
    for (int i = 4; i < 8; i++)
        buffer.push_front(i);
    std::cout << buffer.front() << " - front element" << std::endl;
    std::cout << buffer.back() << " - back element" << std::endl;
    buffer.print();
    buffer.erase_front();
    buffer.erase_back();
    std::cout << "Gonna delete some elements" << std::endl;
    buffer.print();
    std::cout << "Create a new buffer" << std::endl;
    circular_buffer<int> new_buffer(buffer);
    new_buffer.print();
    for (int i = 8; i < 12; i++)
    {
        new_buffer.push_front(i);
    }
    for (int i = 12; i < 16; i++)
    {
        new_buffer.push_back(i);
    }
    std::cout << "Try to add new elements" << std::endl;
    new_buffer.print();
    std::cout << "Resize a buffer" << std::endl;
    new_buffer.resize(3);
    new_buffer.print();
    new_buffer.resize(10);
    for (int i = 16; i < 26; i++)
        new_buffer.push_back(i);
    new_buffer.print();
    std::cout << "Using an iterator with STL algorithms" << std::endl;
    circular_buffer<int>::iterator it = std::find(new_buffer.begin(), new_buffer.end(), 25);
    std::cout << *it << std::endl;
    std::cout << (bool) std::any_of(new_buffer.begin(), new_buffer.end(), function<int>) << std::endl;
    std::for_each(new_buffer.begin(), new_buffer.end(), pow);
    new_buffer.print();
    circular_buffer<int>::iterator it2 = new_buffer.begin();
    std::cout << it2[2] << std::endl;
    std::cout << "Using my algorithms with different types" << std::endl;
    circular_buffer<int>::iterator it3 = Find_backward(new_buffer.begin(), new_buffer.end(), 400);
    std::cout << *it3 << std::endl;

    std::vector<int> vec;
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(1);
    auto find_it = Find_not(vec.begin(), vec.end(), 0);
    std::cout << *find_it << std::endl;
    std::cout << is_Sorted(vec.begin(), vec.end(), sorted<int>) << std::endl;
    std::cout << is_Partioned(vec.begin(), vec.end(), zero<int>) << std::endl;
    Point point[15];
    for (int i = 0; i < 15; i++)
    {
        point[i] = Point(i, i + 1);
    }
    std::cout << All_of(point, point + 15, greater<Point>) << std::endl;
    Point points[4];
    points[0] = Point(4, 5);
    points[3] = Point(4, 5);
    points[1] = Point(2, 3);
    points[2] = Point(2, 3);
    std::cout << is_Palindrome(point, point + 15, func<Point>) << std::endl;
    std::cout << is_Palindrome(points, points + 4, func<Point>) << std::endl;


    return 0;
}