#include "vector3D.hpp"

Vector3D::Vector3D(float _x, float _y, float _z)
{
    x=_x; y=_y; z=_z; p=1;
}

float Vector3D::get_x() const
{
    return x;
}

float Vector3D::get_y() const
{
    return y;
}

float Vector3D::get_z() const
{
    return z;
}

float Vector3D::get_p() const
{
    return p;
}

void Vector3D::set_x(const float _x)
{
    x=_x;
}

void Vector3D::set_y(const float _y)
{
    y=_y;
}

void Vector3D::set_z(const float _z)
{
    z=_z;
}

void Vector3D::set_p(const float _p)
{
    p=_p;
}

void Vector3D::normalize()
{
    float l = std::sqrt(x*x + y*y + z*z);
    if (l != 0)
    {
        x/=l;
        y/=l;
        z/=l;
    }
}

float Vector3D::magnitude()
{
    return sqrt(x*x+y*y+z*z);
}

float Vector3D::dotProduct(const Vector3D& other_vect) const
{
    return x*other_vect.x + y*other_vect.y + z+other_vect.z;
}

Vector3D Vector3D::crossProduct(const Vector3D& other_vect) const
{
    return Vector3D(y*other_vect.z - z*other_vect.y, z*other_vect.x - x*other_vect.z, x*other_vect.y - y*other_vect.x);
}

Vector3D Vector3D::multiplyVector3ByMatrix4(Vector3D vect_out, const Matrix& mat)
{
    vect_out.set_x(x * mat[{0,0}] + y * mat[{1,0}] + z * mat[{2,0}] + p*mat[{3,0}]);
    vect_out.set_y(x * mat[{0,1}] + y * mat[{1,1}] + z * mat[{2,1}] + p*mat[{3,1}]);
    vect_out.set_z(x * mat[{0,2}] + y * mat[{1,2}] + z * mat[{2,2}] + p*mat[{3,2}]);
    vect_out.set_p(x * mat[{0,3}] + y * mat[{1,3}] + z * mat[{2,3}] + p*mat[{3,3}]);
}

Vector3D Vector3D::multiplyVector3ByMatrix4(const Matrix& mat)
{
    Vector3D out;
    out.set_x(x * mat[{0,0}] + y * mat[{1,0}] + z * mat[{2,0}] + p*mat[{3,0}]);
    out.set_y(x * mat[{0,1}] + y * mat[{1,1}] + z * mat[{2,1}] + p*mat[{3,1}]);
    out.set_z(x * mat[{0,2}] + y * mat[{1,2}] + z * mat[{2,2}] + p*mat[{3,2}]);
    out.set_p(x * mat[{0,3}] + y * mat[{1,3}] + z * mat[{2,3}] + p*mat[{3,3}]);
    return out;
}

void Vector3D::operator+=(const Vector3D& vect)
{
    x += vect.x; y += vect.y; z += vect.z;
}

void Vector3D::operator-=(const Vector3D& vect)
{
    x -= vect.x; y -= vect.y; z -= vect.z;
}

void Vector3D::operator*=(const float& a)
{
    x *= a; y *= a; z *= a;
}

void Vector3D::operator/=(const float& a)
{
    if (a == 0) throw std::invalid_argument("Division par zéro");
    x /= a; y /= a;  z /= a;
}



Vector3D operator+(const Vector3D& vect1, const Vector3D& vect2)
{
    Vector3D vect3(0, 0, 0);
    vect3+=vect1;
    vect3+=vect2;
    return vect3;
}

Vector3D operator-(const Vector3D& vect1, const Vector3D& vect2)
{
    Vector3D vect3(0, 0, 0);
    vect3+=vect1;
    vect3-=vect2;
    return vect3;
}

Vector3D operator*(const Vector3D& vect1, const float& a)
{
    Vector3D* vect2 = new Vector3D(vect1);
    *vect2 *=a;
    return *vect2;
}

Vector3D operator*(const float& a, const Vector3D& vect1)
{
    Vector3D* vect2 = new Vector3D(vect1);
    *vect2 *=a;
    return *vect2;
}

Vector3D operator*(const Vector3D& vect1, const Vector3D& vect2)
{
    Vector3D vect3(0, 0, 0);
    vect3.set_x(vect1.get_x()*vect2.get_x());
    vect3.set_y(vect1.get_y()*vect2.get_y());
    vect3.set_z(vect1.get_z()*vect2.get_z());
    return vect3;
}

Vector3D operator/(const Vector3D& vect1, const float& a)
{
    Vector3D* vect2 = new Vector3D(vect1);
    *vect2 /=a;
    return *vect2;
}

Vector3D operator/(const float& f, const Vector3D& vect1)
{
    Vector3D* vect2 = new Vector3D(vect1);
    *vect2 /=f;
    return *vect2;
}

void Vector3D::inverseXY()
{
    x *= -1;
    y *= -1;
}

std::ostream& operator<<(std::ostream& os, Vector3D vect)
{
    os << "(" << vect.get_x() << "; " << vect.get_y() << "; " << vect.get_z() << "; " << vect.get_p() <<")" << std::endl;
    return os;
}

Vector3D CrossProduct(const Vector3D& vect1, const Vector3D& vect2)
{
    return Vector3D(vect1.get_y()*vect2.get_z() - vect1.get_z()*vect2.get_y(), vect1.get_z()*vect2.get_x() - vect1.get_x()*vect2.get_z(), vect1.get_x()*vect2.get_y() - vect1.get_y()*vect2.get_x());
}