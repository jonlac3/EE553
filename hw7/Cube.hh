#pragma once
#include <iostream>
using namespace std;

class Cube{
protected:
    double x, y, z, s;
public:
    Cube(double x, double y, double z, double side): x(x), y(y), z(z), s(s){}
    void print(string filename) const;
};