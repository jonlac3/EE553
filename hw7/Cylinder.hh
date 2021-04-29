#pragma once
#include <iostream>
using namespace std;

class Cylinder{
protected:
    double x, y, z, r, h, facets;
public:
    Cylinder(double x, double y, double z, double r, double h, double facets): x(x), y(y), z(z), r(r), h(h), facets(facets){}

    void print(string file) const;
};
