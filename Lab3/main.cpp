#include <iostream>
#include<vector>
#include<algorithm>
#include "circular_buffer.h"
#include "algorithms.h"
template<typename T>
bool function(T a)
{
    return a == 50;
}
void pow(int &i)
{ i *= i; }

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
    circular_buffer<int>::iterator it3 = find_backward(new_buffer.begin(), new_buffer.end(), 400);
    std::cout << *it3;
    return 0;
}