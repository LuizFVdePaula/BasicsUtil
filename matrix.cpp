#include "matrix.hpp"

template<unsigned int rows, unsigned int cols>
Matrix<rows, cols>::Matrix(const float data_[])
{
    for(unsigned int i = 0; i < rows; i++)
    {
        for(unsigned int j = 0; j < cols; j++)
        {
            data[i][j] = data_[cols * i + j];
        }
    }
}

template<unsigned int rows, unsigned int cols>
Matrix<rows, cols>::Matrix()
{
    for(unsigned int i = 0; i < rows; i++)
    {
        for(unsigned int j = 0; j < cols; j++)
        {
            data[i][j] = 0;
        }
    }
}

template<unsigned int rows, unsigned int cols>
const float Matrix<rows, cols>::at(unsigned int index, unsigned int jndex) const
{
    return data[index][jndex];
}

template<unsigned int rw, unsigned int cl>
Matrix<rw, cl> operator*(const Matrix<rw, cl>& matrix, float x)
{
    Matrix<rw, cl> newmatrix;
    for(unsigned int i = 0; i < rw; i++)
    {
        for(unsigned int j = 0; j < cl; j++)
        {
            newmatrix.data[i][j] = matrix.data[i][j] * x;
        }
    }
    return newmatrix;
}

template<unsigned int rw, unsigned int cl>
Matrix<rw, cl> operator*(float x, const Matrix<rw, cl>& matrix)
{
    Matrix<rw, cl> newmatrix;
    for(unsigned int i = 0; i < rw; i++)
    {
        for(unsigned int j = 0; j < cl; j++)
        {
            newmatrix.data[i][j] = matrix.data[i][j] * x;
        }
    }
    return newmatrix;
}

template<unsigned int Arw, unsigned int AclBrw, unsigned int Bcl>
Matrix<Arw, Bcl> operator*(const Matrix<Arw, AclBrw>& A, const Matrix<AclBrw, Bcl>& B)
{
    Matrix<Arw, Bcl> newmatrix;
    for(unsigned int i = 0; i < Arw; i++)
    {
        for(unsigned int j = 0; j < Bcl; j++)
        {
            for(unsigned int k = 0; k < AclBrw; k++)
            {
                newmatrix.data[i][j] += A.at(i, k) * B.at(k, j);
            }
        }
    }
    return newmatrix;
}

template<unsigned int rw, unsigned int cl>
Matrix<rw, cl> operator+(const Matrix<rw, cl>& A, const Matrix<rw, cl>& B)
{
    Matrix<rw, cl> newmatrix;
    for(unsigned int i = 0; i < rw; i++)
    {
        for(unsigned int j = 0; j < cl; j++)
        {
            newmatrix.data[i][j] = A.at(i, j) + B.at(i, j);
        }
    }
    return newmatrix;
}