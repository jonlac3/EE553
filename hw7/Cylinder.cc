#include "Cylinder.hh"
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

void Cylinder::print(string filename) const{
    double slices = (M_PI*2)/f;
    //x and y coordinates of vertices
    //(x,y,z) = (x+rcos(theta), y +rsin(theta), z (or z+h) )
    vector<double> bottom;
    ofstream f;
    f.open(filename);
    f << "solid cylinder"<<endl;
    for(int i = 0; i < 2*M_PI; i+=slices){
        double vx1 = x + r*cos(i);
        double vy1 = y + r*sin(i);
        double vz1 = z;
        double vx2 = x + r*cos(i+slices);
        double vy2 = y + r*sin(i+slices);
        double vz2 = z;
        double vx3 = x + r*cos(i+(slices/2));       
        double vy3 = y + r*sin(i+(slices/2));        
        double vz3 = z+h;
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

        vx1 = x + r*cos(i);
        vy1 = y + r*sin(i);
        vz1 = z;
        vx2 = x + r*cos(i+slices);
        vy2 = y + r*sin(i+slices);
        vz2 = z;
        vx3 = x + r*cos(i+(slices/2));       
        vy3 = y + r*sin(i+(slices/2));        
        vz3 = z+h;
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
