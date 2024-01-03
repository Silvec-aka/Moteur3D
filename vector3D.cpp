#include "vector3D.hpp"

Vector3D::Vector3D(float _x, float _y, float _z)
{
    x=_x; y=_y; z=_z; p=1;
}

float Vector3D::get_x()
{
    return x;
}