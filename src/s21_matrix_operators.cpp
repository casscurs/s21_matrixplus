#include "s21_matrix_oop.hpp"

S21Matrix& S21Matrix::operator=(S21Matrix other)
{
    swap(other);
    return *this;
}