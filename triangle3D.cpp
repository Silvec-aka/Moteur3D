#include "triangle3D.hpp"

Triangle3D::Triangle3D()
{
    a =Vector3D(0,0,0); b =Vector3D(0,0,0); c =Vector3D(0,0,0);
}

Triangle3D::Triangle3D(const Triangle3D& t)
{
    Vector3D tmp_a(t.a.get_x(), t.a.get_y(), t.a.get_z());
    a=tmp_a;
    Vector3D tmp_b(t.b.get_x(), t.b.get_y(), t.b.get_z());
    b=tmp_b;
    Vector3D tmp_c(t.c.get_x(), t.c.get_y(), t.c.get_z());
    c=tmp_c;

    i=t.i;
}

Triangle3D::Triangle3D(Vector3D& _a, Vector3D& _b, Vector3D& _c)
{
    a=_a; b=_b; c=_c; i=0;
}

Vector3D& Triangle3D::get_a()
{
    return a;
}

Vector3D& Triangle3D::get_b()
{
    return b;
}

Vector3D& Triangle3D::get_c()
{
    return c;
}

float Triangle3D::get_i()
{
    return i;
}

void Triangle3D::set_a(const Vector3D& _a)
{
    a=_a;
}

void Triangle3D::set_b(const Vector3D& _b)
{
    b=_b;
}

void Triangle3D::set_c(const Vector3D& _c)
{
    c=_c;
}

void Triangle3D::set_i(const float _i)
{
    i=_i;
}

Vector3D Triangle3D::getCenterOfThirdSide()
{
    float f0 = a.get_x()/2 + c.get_x()/2;
    float f1 = a.get_y()/2 + c.get_y()/2;
    float f2 = a.get_z()/2 + c.get_z()/2;
    return Vector3D(f0, f1, f2);
}

Triangle3D Triangle3D::multiplyByMatrix(const Matrix mat)
{
    a = a.multiplyVector3ByMatrix(mat);
    b = b.multiplyVector3ByMatrix(mat);
    c = c.multiplyVector3ByMatrix(mat);
    return *this;
}

void Triangle3D::inverseXY()
{
    a.inverseXY(); b.inverseXY(); c.inverseXY();
}

void Triangle3D::scaleToViewAndWindow(int window_w,int window_h)
{
    a+=Vector3D(1,1,0); b+=Vector3D(1,1,0); c+=Vector3D(1,1,0);

    a = a*Vector3D(0.5*((float) window_w), 0.5*((float) window_h), 1);
    b = b*Vector3D(0.5*((float) window_w), 0.5*((float) window_h), 1);
    c = c*Vector3D(0.5*((float) window_w), 0.5*((float) window_h), 1);
}

void Triangle3D::operator+=(const Vector3D vect)
{
    a+=vect; b+=vect; c+=vect;
}

void Triangle3D::operator*=(float f)
{
    a*=f; b*=f; c*=f; 
}

Triangle3D Triangle3D::operator=(const Triangle3D& t)
{
    a=t.a; b=t.b; c=t.c; i=t.i;
    return *this;
}

std::ostream& operator<<(std::ostream& os, Triangle3D& t)
{
    os << t.get_a() << " | " << t.get_b() << " | " << t.get_c() << std::endl;
    return os;
}