#include <iostream>
#include "vector.hpp"
#include "matrix.hpp"

template<unsigned int rw, unsigned int cl>
void print_matrix(const Matrix<rw, cl>& matrix);

template<unsigned int size>
void print_vector(const Vector<size>& vector);

int main()
{
    std::cout << "test\n";
    float arr[4] = {7, 8, 9, 1};

    Vector<4> vec(arr);
    std::cout << vec.length() << '\n';
    print_vector(vec);
    Vector<4> newvec = 2 * vec;
    print_vector(vec);
    print_vector(newvec);
    print_vector(vec + newvec);

    std::cout << "\n\n";

    float vals[] = {1, 2, 3, 4, 5, 6};
    Matrix<2, 3> matrix(vals);
    Matrix<3, 2> newmatrix(vals);
    print_matrix(matrix);
    print_matrix(matrix * newmatrix);
    print_matrix(newmatrix + newmatrix);

}

template<unsigned int rw, unsigned int cl>
void print_matrix(const Matrix<rw, cl>& matrix)
{
    for(std::size_t i = 0; i < rw; i++)
    {
        for(std::size_t j = 0; j < cl; j++)
        {
            std::cout << matrix.at(i, j) << ' ';
        }
        std::cout << '\n';
    }
}

template<unsigned int size>
void print_vector(const Vector<size>& vector)
{
    for(std::size_t i = 0; i < size; i++)
    {
        std::cout << vector.at(i) << ' ';
    }
    std::cout << '\n';
}