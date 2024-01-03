#include "matrix.hpp"
#include <cmath>


Matrix::Matrix()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            data[i][j] = 1.0f;
        }
    }
}

Matrix::Matrix(const Matrix& mat)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            data[i][j] = mat.data[i][j];
        }
    }
}

Matrix::Matrix(float a00, float a01, float a02, float a03,
               float a10, float a11, float a12, float a13,
               float a20, float a21, float a22, float a23,
               float a30, float a31, float a32, float a33)
{
    data[0][0] = a00; data[0][1] = a01; data[0][2] = a02; data[0][3] = a03;
    data[1][0] = a10; data[1][1] = a11; data[1][2] = a12; data[1][3] = a13;
    data[2][0] = a20; data[2][1] = a21; data[2][2] = a22; data[2][3] = a23;
    data[3][0] = a30; data[3][1] = a31; data[3][2] = a32; data[3][3] = a33;
}

Matrix Matrix::inverse()
{
    Matrix out;
    out[{0,0}] = data[0][0] ; out[{0,1}] = data[1][0] ; out[{0,2}] = data[2][0] ; out[{0,3}] = 0.0f;
    out[{1,0}] = data[0][1] ; out[{1,1}] = data[1][1] ; out[{1,2}] = data[2][1] ; out[{1,3}] = 0.0f;
    out[{2,0}] = data[0][2] ; out[{2,1}] = data[1][2] ; out[{2,2}] = data[2][2] ; out[{2,3}] = 0.0f;
    out[{3,0}] = -(data[3][0] * out[{0,0}] + data[3][1] * out[{1,0}] + data[3][2] * out[{2,0}]);
    out[{3,1}] = -(data[3][0] * out[{0,1}] + data[3][1] * out[{1,1}] + data[3][2] * out[{2,1}]);
    out[{3,2}] = -(data[3][0] * out[{0,2}] + data[3][1] * out[{1,2}] + data[3][2] * out[{2,2}]);
    out[{3,3}] = 1.0f;
    return out;
}

float& Matrix::operator[](std::pair<int, int> idx){
    return data[idx.first][idx.second];
}

const float& Matrix::operator[](std::pair<int, int> idx) const{
    return data[idx.first][idx.second];
}

std::ostream& operator<<(std::ostream& os,const Matrix& mat){
    os << mat[{0,0}] << "; " << mat[{0,1}] << "; " << mat[{0,2}] << "; " << mat[{0,3}] << std::endl
    << mat[{1,0}] << "; " << mat[{1,1}] << "; " << mat[{1,2}] << "; " << mat[{1,3}] << std::endl
    << mat[{2,0}] << "; " << mat[{2,1}] << "; " << mat[{2,2}] << "; " << mat[{2,3}] << std::endl
    << mat[{3,0}] << "; " << mat[{3,1}] << "; " << mat[{3,2}] << "; " << mat[{3,3}] << std::endl << std::endl;
    return os;
}


void Matrix::initializeZRot(float angle){
    data[0][0] = cosf(angle);
    data[0][1] = sinf(angle);
    data[1][0] = -sinf(angle);
    data[1][1] = cosf(angle);
    data[2][2] = 1;
    data[3][3] = 1;
}

void Matrix::initializeYRot(float angle){
    data[0][0] = cosf(angle);
    data[0][2] = -sinf(angle);
    data[1][1] = 1;
    data[2][0] = sinf(angle);
    data[2][2] = cosf(angle);
    data[3][3] = 1;
}

void Matrix::initializeXRot(float angle){
    data[0][0] = 1;
    data[1][1] = cosf(angle);
    data[1][2] = sinf(angle);
    data[2][1] = -sinf(angle);
    data[2][2] = cosf(angle);
    data[3][3] = 1;
}

void Matrix::initializeProj(int window_width, int window_height){
    float fNear = 0.1f;
    float fFar = 1000.0f;
    float fFov = 90.0f;
    float fAspectRatio = (float)window_height / (float)window_width;
    float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

    data[0][0] = fAspectRatio * fFovRad;
    data[1][1] = fFovRad;
    data[2][2] = fFar / (fFar - fNear);
    data[3][2] = (-fFar * fNear) / (fFar - fNear);
    data[2][3] = 1.0f;
}

