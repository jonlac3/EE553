#pragma once
#include <iostream>
using namespace std;

class Cylinder{
protected:
    double x, y, z, r, h, f;
public:
    Cylinder(double x, double y, double z, double r, double h, double f): x(x), y(y), z(z), r(r), h(h), f(f){}
    void print(string filename) const;
};