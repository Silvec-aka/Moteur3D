#include "quad3D.hpp"

Quad3D::Quad3D(const Triangle3D& t1, const Triangle3D t2)
{
    trig1 = t1;
    trig2 = t2;
}

Quad3D::Quad3D(const Vector3D& _a, const Vector3D& _b, const Vector3D& _c, const Vector3D& _d)
{
    trig1 = Triangle3D(_a, _b, _c);
    trig2 = Triangle3D(_c, _d, _a);
}

Triangle3D Quad3D::get_trig1() const
{
    return trig1;
}

Triangle3D Quad3D::get_trig2() const
{
    return trig2;
}