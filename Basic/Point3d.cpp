#ifndef POINT3D
#define POINT3D

#include <iostream>

class Point3d
{
public:
    Point3d(float x=0.0,float y=0.0,float z=0.0):
	_x(x),_y(y),_z(z){};

    float x() {return _x;}
    float y() {return _y;}
    float z() {return _z;}

    void x(float xval){_x = xval;}

private:
    float _x;
    float _y;
    float _z;
};

inline ostream& operator<<(ostream &os,const Point3d &pt)
{
    os << "(" << pt.x() << "," << pt.y() << "," << pt.z() << ")" << endl;
}
