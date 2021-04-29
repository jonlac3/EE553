#include "Cylinder.hh"
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

void Cylinder::print(string filename) const{
    double slices = (M_PI*2)/facets;
    //x and y coordinates of vertices
    //(x,y,z) = (x+rcos(theta), y +rsin(theta), z (or z+h) )
    ofstream f;
    f.open(filename);
    f << "solid cylinder"<<endl;
    for(double i = 0; i < facets; i++){

        //triangle up
        double vx1 = x + r*cos(i*slices);
        double vy1 = y;
        double vz1 = y + r*sin(i*slices);
        double vx2 = x + r*cos(i*slices+slices);
        double vy2 = y;
        double vz2 = z + r*sin(i*slices+slices);
        double vx3 = x + r*cos(i*slices);       
        double vy3 = y + h;
        double vz3 = z + r*sin(i*slices);
        double nx = (vy2-vy1)*(vz3-vz1)-(vy3-vy1)*(vy2-vy1);
        double ny = (vz2-vz1)*(vx3-vx1)-(vx3-vx1)*(vz2-vz1);
        double nz = (vx2-vx1)*(vy3-vy1)-(vy3-vy1)*(vx2-vx1);
        f<< "    " << "facet normal " << nx << " " << ny << " " << nz << endl;
        f<< "       " << "outer loop" <<endl;
        f<< "           "<< "vertex " << vx1 << " " << vy1 << " " << vz1 << endl;
        f<< "           "<< "vertex " << vx2 << " " << vy2 << " " << vz2 << endl;
        f<< "           "<< "vertex " << vx3 << " " << vy3 << " " << vz3 <<endl;
        f<< "       "<< "endloop" << endl;
        f<< "    " << "endfacet" << endl;

        //triangle down
        vx1 = x + r*cos(i*slices);
        vy1 = y + h;
        vz1 = y + r*sin(i*slices);
        vx2 = x + r*cos(i*slices+slices);
        vy2 = y + h;
        vz2 = z + r*sin(i*slices+slices);
        vx3 = x + r*cos(i*slices+slices);       
        vy3 = y;
        vz3 = z + r*sin(i*slices+slices);
        f<< "    " << "facet normal " << nx << " " << ny << " " << nz << endl;
        f<< "       " << "outer loop" <<endl;
        f<< "           "<< "vertex " << vx1 << " " << vy1 << " " << vz1 << endl;
        f<< "           "<< "vertex " << vx2 << " " << vy2 << " " << vz2 << endl;
        f<< "           "<< "vertex " << vx3 << " " << vy3 << " " << vz3 <<endl;
        f<< "       "<< "endloop" << endl;
        f<< "    " << "endfacet" << endl;

        //bottom circle
        vx1 = x;
        vy1 = y;
        vz1 = y;
        vx2 = x + r*cos(i*slices);
        vy2 = y;
        vz2 = z + r*sin(i*slices);
        vx3 = x + r*cos(i*slices+slices);       
        vy3 = y;
        vz3 = z + r*sin(i*slices+slices);
        nx = (vy2-vy1)*(vz3-vz1)-(vy3-vy1)*(vy2-vy1);
        ny = (vz2-vz1)*(vx3-vx1)-(vx3-vx1)*(vz2-vz1);
        nz = (vx2-vx1)*(vy3-vy1)-(vy3-vy1)*(vx2-vx1);
        f<< "    " << "facet normal " << nx << " " << ny << " " << nz << endl;
        f<< "       " << "outer loop" <<endl;
        f<< "           "<< "vertex " << vx1 << " " << vy1 << " " << vz1 << endl;
        f<< "           "<< "vertex " << vx2 << " " << vy2 << " " << vz2 << endl;
        f<< "           "<< "vertex " << vx3 << " " << vy3 << " " << vz3 <<endl;
        f<< "       "<< "endloop" << endl;
        f<< "    " << "endfacet" << endl;

        //top circle
        vx1 = x;
        vy1 = y+h;
        vz1 = y;
        vx2 = x + r*cos(i*slices);
        vy2 = y+h;
        vz2 = z + r*sin(i*slices);
        vx3 = x + r*cos(i*slices+slices);       
        vy3 = y+h;
        vz3 = z + r*sin(i*slices+slices);
        nx = (vy2-vy1)*(vz3-vz1)-(vy3-vy1)*(vy2-vy1);
        ny = (vz2-vz1)*(vx3-vx1)-(vx3-vx1)*(vz2-vz1);
        nz = (vx2-vx1)*(vy3-vy1)-(vy3-vy1)*(vx2-vx1);
        f<< "    " << "facet normal " << nx << " " << ny << " " << nz << endl;
        f<< "       " << "outer loop" <<endl;
        f<< "           "<< "vertex " << vx1 << " " << vy1 << " " << vz1 << endl;
        f<< "           "<< "vertex " << vx2 << " " << vy2 << " " << vz2 << endl;
        f<< "           "<< "vertex " << vx3 << " " << vy3 << " " << vz3 <<endl;
        f<< "       "<< "endloop" << endl;
        f<< "    " << "endfacet" << endl;
    }
       
    f<< "endsolid cylinder"<<endl;
}
