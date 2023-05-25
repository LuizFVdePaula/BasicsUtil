#pragma once

template<unsigned int rows, unsigned int cols>
class Matrix
{
private:
    float data[rows][cols];

public:
    Matrix(const float []);
    Matrix();
    const float at(unsigned int, unsigned int) const;

    template<unsigned int rw, unsigned int cl>
    friend Matrix<rw, cl> operator*(const Matrix<rw, cl>&, float);

    template<unsigned int rw, unsigned int cl>
    friend Matrix<rw, cl> operator*(float, const Matrix<rw, cl>&);

    template<unsigned int Arw, unsigned int AclBrw, unsigned int Bcl>
    friend Matrix<Arw, Bcl> operator*(const Matrix<Arw, AclBrw>&, const Matrix<AclBrw, Bcl>&);

    template<unsigned int rw, unsigned int cl>
    friend Matrix<rw, cl> operator+(const Matrix<rw, cl>&, const Matrix<rw, cl>&);

};

#include "matrix.cpp"