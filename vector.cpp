#include "vector.hpp"

template<unsigned int size>
Vector<size>::Vector(const float data_[])
{
    for(unsigned int i = 0; i < size; i++)
    {
        data[i] = data_[i];
    }
}

template<unsigned int size>
Vector<size>::Vector()
{
    for(unsigned int i = 0; i < size; i++)
    {
        data[i] = 0;
    }
}

template<unsigned int size>
unsigned int Vector<size>::length() const
{
    return size;
}

template<unsigned int size>
const float Vector<size>::at(unsigned int index) const
{
    return data[index];
}

template<unsigned int len>
Vector<len> operator*(const Vector<len>& vec, const float x)
{
    Vector<len> newvec(vec.data);
    for(float& val : newvec.data)
    {
        val *= x;
    }
    return newvec;
}

template<unsigned int len>
Vector<len> operator*(const float x, const Vector<len>& vec)
{
    Vector<len> newvec(vec.data);
    for(float& val : newvec.data)
    {
        val *= x;
    }
    return newvec;
}

template<unsigned int len>
Vector<len> operator+(const Vector<len>& vec1, const Vector<len>& vec2)
{
    Vector<len> newvec;
    for(unsigned int i = 0; i < len; i++)
    {
        newvec.data[i] = vec1.data[i] + vec2.data[i];
    }
    return newvec;
}