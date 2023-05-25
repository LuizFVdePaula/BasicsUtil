#pragma once

template<unsigned int size>
class Vector
{
private:
    float data[size];

public:
    Vector(const float []);

    Vector();

    unsigned int length() const;

    const float at(unsigned int) const;

    template<unsigned int len>
    friend Vector<len> operator*(const Vector<len>&, const float);

    template<unsigned int len>
    friend Vector<len> operator*(const float, const Vector<len>&);

    template<unsigned int len>
    friend Vector<len> operator+(const Vector<len>&, const Vector<len>&);
};

#include "vector.cpp"