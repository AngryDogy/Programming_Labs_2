#include <iostream>
#include<vector>
#include "allocator.h"
int main()
{

    std::vector<int, MyAllocator<int>> g(85);
    g[0] = 1;
    return 0;
}
