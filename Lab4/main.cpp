#include<iostream>
#include<fstream>
#include "Cube.h"

using namespace std;

int main()
{
    Cube a;
    a.print();
    a.solve();
    a.print();

    fstream in;
    in.open("input.txt");
    Cube c(in);
    cout << c.solve() << '\n';
    c.print();
    c.out_ans();

}